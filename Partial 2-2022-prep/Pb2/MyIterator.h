#pragma once
#include "Entry.h"

class MyIterator {
private:
	Entry** m_ptr; 
public: 
	MyIterator(Entry** ptr); 
	MyIterator& operator++(); 
	bool operator !=(const MyIterator& ptr);
	Entry* operator *();
};