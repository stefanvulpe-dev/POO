#pragma once
#include "MyException.h" 

class StringDataException : public MyException {
public:
	StringDataException(string str1, string str2) : MyException(string("StringData: len(") + str1 + string(") < ") + str2) { }
};