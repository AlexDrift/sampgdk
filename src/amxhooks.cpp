// Copyright (c) 2011 Zeex
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <sampgdk/config.h>
#include <sampgdk/core.h>
#include <sampgdk/plugin.h>

#include "amxhooks.h"
#include "callbacks.h"
#include "jump-x86.h"
#include "natives.h"

extern void *pAMXFunctions;

// Gamemode's AMX
AMX *AmxHooks::gamemode_ = 0;

// Curently Exec()'ing public 
std::string AmxHooks::currentPublic_;

// AMX API hooks
JumpX86 AmxHooks::amx_FindPublicHook_;
JumpX86 AmxHooks::amx_ExecHook_;
JumpX86 AmxHooks::amx_RegisterHook_;
JumpX86 AmxHooks::amx_CallbackHook_;
JumpX86 AmxHooks::amx_PushHook_;
JumpX86 AmxHooks::amx_PushStringHook_;

static cell AMX_NATIVE_CALL fixed_funcidx(AMX *amx, cell *params) {
	char *funcname;
	amx_StrParam(amx, params[1], funcname);
	int index;
	int error = amx_FindPublic(amx, funcname, &index);
	if (error != AMX_ERR_NONE || (error == AMX_ERR_NONE && index == AMX_EXEC_GDK)) {
		return -1;
	}
	return index;
}

void AmxHooks::Initialize(void **ppPluginData) {
	pAMXFunctions = ppPluginData[PLUGIN_DATA_AMX_EXPORTS];
	void **amxExports = static_cast<void**>(pAMXFunctions);

	amx_RegisterHook_.Install(
		amxExports[PLUGIN_AMX_EXPORT_Register],   
		(void*)amx_Register);
	amx_FindPublicHook_.Install(
		amxExports[PLUGIN_AMX_EXPORT_FindPublic], 
		(void*)amx_FindPublic);
	amx_ExecHook_.Install(
		amxExports[PLUGIN_AMX_EXPORT_Exec],       
		(void*)amx_Exec);
	amx_CallbackHook_.Install(
		amxExports[PLUGIN_AMX_EXPORT_Callback],
		(void*)amx_Callback);
	amx_PushHook_.Install(
		amxExports[PLUGIN_AMX_EXPORT_Push],
		(void*)amx_Push);
	amx_PushStringHook_.Install(
		amxExports[PLUGIN_AMX_EXPORT_PushString],
		(void*)amx_PushString);
}

void AmxHooks::Finalize() {
	amx_RegisterHook_.Remove();
	amx_FindPublicHook_.Remove();
	amx_ExecHook_.Remove();
	amx_CallbackHook_.Remove();
	amx_PushHook_.Remove();
	amx_PushStringHook_.Remove();
}

int AMXAPI AmxHooks::amx_Register(AMX *amx, const AMX_NATIVE_INFO *nativelist, int number) {
	amx_RegisterHook_.Remove();

	int error = ::amx_Register(amx, nativelist, number);

	for (int i = 0; nativelist[i].name != 0 && (i < number || number == -1); ++i) {
		NativeManager::GetInstance().SetNative(nativelist[i].name, nativelist[i].func);
		// Fix for funcidx() issue
		if (strcmp(nativelist[i].name, "funcidx") == 0) {
			new JumpX86((void*)nativelist[i].func, (void*)fixed_funcidx);
		}
	}

	amx_RegisterHook_.Install();
	return error;
}

int AMXAPI AmxHooks::amx_FindPublic(AMX *amx, const char *name, int *index) {
	amx_FindPublicHook_.Remove();

	int error = ::amx_FindPublic(amx, name, index);

	if (amx == gamemode_) {
		if (error != AMX_ERR_NONE) {
			*index = AMX_EXEC_GDK;
			error = AMX_ERR_NONE;
		}
		currentPublic_ = name;
	}

	amx_FindPublicHook_.Install();
	return error;
}

int AMXAPI AmxHooks::amx_Exec(AMX *amx, cell *retval, int index) {
	amx_ExecHook_.Remove();
	amx_CallbackHook_.Install();
	
	bool canDoExec = true;
	if (index == AMX_EXEC_MAIN) {
		gamemode_ = amx;
		CallbackManager::GetInstance().HandleCallback("OnGameModeInit");
	} else {
		if (amx == gamemode_ && index != AMX_EXEC_CONT) {
			canDoExec = CallbackManager::GetInstance().HandleCallback(currentPublic_.c_str());
		}
	}

	int error = AMX_ERR_NONE;
	if (canDoExec && index != AMX_EXEC_GDK) {
		error = ::amx_Exec(amx, retval, index);
	} else {
		// Pop parameters from stack 
		amx->stk += amx->paramcount * sizeof(cell);			
	}

	// Reset parameter count 
	// <weird>
	// Sometimes it is not auto-reset by amx_Exec though it normally should. 
	// </weird>
	amx->paramcount = 0;	

	amx_CallbackHook_.Remove();
	amx_ExecHook_.Install();

	return error;
}

int AMXAPI AmxHooks::amx_Callback(AMX *amx, cell index, cell *result, cell *params) {
	amx_CallbackHook_.Remove();
	amx_ExecHook_.Install();

	// Forbid SYSREQ.D
	amx->sysreq_d = 0;
	
	int error = ::amx_Callback(amx, index, result, params);
	
	amx_ExecHook_.Remove();
	amx_CallbackHook_.Install();

	return error;
}

int AMXAPI AmxHooks::amx_Push(AMX *amx, cell value) {
	amx_PushHook_.Remove();

	int error = ::amx_Push(amx, value);
	if (amx == gamemode_) {
		CallbackManager::GetInstance().PushArg(value);
	}

	amx_PushHook_.Install();

	return error;
}

int AMXAPI AmxHooks::amx_PushString(AMX *amx, cell *amx_addr, cell **phys_addr, const char *string, int pack, int wchar) {
	amx_PushHook_.Remove(); // PushString calls Push
	amx_PushStringHook_.Remove();

	int error = ::amx_PushString(amx, amx_addr, phys_addr, string, pack, wchar);
	if (amx == gamemode_) {
		CallbackManager::GetInstance().PushArg(*phys_addr);
	}

	amx_PushHook_.Install();
	amx_PushStringHook_.Install();

	return error;
}
