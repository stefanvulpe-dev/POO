#pragma once
#include "MyException.h"

class WriteFileException : public MyException {
public:
	WriteFileException(string name) : MyException(string("can't write file ") + name) { }
};