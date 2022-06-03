#include "MyIterator.h"

MyIterator::MyIterator(Entry** ptr) {
	this->m_ptr = ptr;
}

MyIterator& MyIterator::operator++() {
	this->m_ptr++; 
	return *this;
}

bool MyIterator::operator!=(const MyIterator& it) {
	return (this->m_ptr != it.m_ptr);
}

Entry* MyIterator::operator*() {
	return *m_ptr;
}

