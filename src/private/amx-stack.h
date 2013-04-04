/* Copyright (C) 2012-2013 Zeex
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SAMPGDK_PRIVATE_AMX_STACK_H_
#define SAMPGDK_PRIVATE_AMX_STACK_H_

#include <sampgdk/amx.h>
#include <sampgdk/bool.h>

cell  amx_stack_get_arg_cell(AMX *amx, int index);
bool  amx_stack_get_arg_bool(AMX *amx, int index);
float amx_stack_get_arg_float(AMX *amx, int index);
char *amx_stack_get_arg_string(AMX *amx, int index);

#endif /* !SAMPGDK_PRIVATE_AMX_STACK_H_ */
