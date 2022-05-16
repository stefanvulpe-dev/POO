#pragma once
#include "MyException.h"

class OpenFileException : public MyException {
public: 
	OpenFileException(string name) : MyException(string("can't open file ") + name) { }
};
