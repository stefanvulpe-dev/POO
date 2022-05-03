#pragma once
#include "Element.h"

template <class Key, class Value>
class MyIterator {
public:
	Element<Key, Value>** ptr;

	MyIterator(Element<Key, Value>** m_ptr) : ptr(m_ptr) {}

	MyIterator& operator++() {
		this->ptr++;
		return *this;
	}

	bool operator != (const MyIterator& other) {
		return ptr != other.ptr;
	}

	Element<Key, Value> operator* () {
		return **ptr;
	}
};