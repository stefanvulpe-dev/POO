#pragma once
#include "MyException.h"

class IntegerDataException : public MyException {
public :
	IntegerDataException(string str1, string str2) : MyException(string("IntegerData: ") + str1 + string(" - ") + str2 + string( " < 0")) { }
};