#pragma once
#include "MyException.h"

class ReadFileException : public MyException {
public:
	ReadFileException(string name) : MyException(string("can't read file ") + name) { }
};