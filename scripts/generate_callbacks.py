#!/usr/bin/env python

import os
import re
import sys

from parse_header import *

def generate_callback_handler(name, args, badRet):
	code = "bool " + name + "(AMX *amx, void *callback, cell *retval) {\n"
	callargs = ""
	declargs = ", ".join([" ".join(list(arg)) for arg in args])
	index = 0
	for argtype, argname in args:
		inst = "sampgdk::Callbacks::GetInstance()"
		if index > 0:
			callargs += ", "
		if argtype == "const char *":
			callargs += argname + ".c_str()"
		else:
			callargs += argname
		if argtype == "bool":
			method = "GetStackBool"
		elif argtype == "float":
			method = "GetStackFloat"
		elif argtype == "const char *":
			method = "GetStackString"
			argtype = "std::string"
		else:
			method = "GetStackCell"
		code += "\t" + argtype + " " + argname + " = " + inst + "." + method + "(amx, " + str(index) + ");\n"
		index += 1
	typename = name + "Type"
	code += "\ttypedef bool (PLUGIN_CALL *" + typename + ")(" + declargs + ");\n"
	code += "\tbool retval_ = ((" + typename + ")callback)(" + callargs + ");\n"
	code += "\t*retval = static_cast<cell>(retval_);\n"
	if badRet is not None:
		code += "\treturn (retval_ != " + str(badRet) + ");\n"
	else:
		code += "\treturn true;\n"
	code += "}\n"
	return code

def main(argv):
	callbacks = list(get_callbacks(sys.stdin.read()))
	for type, name, args, attrs in callbacks:
		badRet = None
		if "$badRet" in attrs:
			badRet = attrs["$badRet"]
		print generate_callback_handler(name, args, badRet)
	print "void RegisterCallbacks() {"
	for type, name, args, attrs in callbacks:
		print "\tsampgdk::Callbacks::GetInstance().AddHandler(\"" + name + "\", " + name + ");"
	print "}"

if __name__ == "__main__":
	main(sys.argv)
