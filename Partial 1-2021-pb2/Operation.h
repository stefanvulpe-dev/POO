#pragma once
 
class Operation { 
public: 
	virtual int calcul(int t1, int t2) = 0;
	virtual const char* getName() = 0;
};