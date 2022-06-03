#pragma once
#include <iostream>
#include <vector> 
#include "Entry.h"
#include "MyIterator.h"

using namespace std;

class Database {
private:
	vector <Entry*> entries;
public:
	Database(); 
	Database& operator+=(Entry* entry);
	Database& operator-=(const string& name); 
	MyIterator begin(); 
	MyIterator end();
	void Print();
};