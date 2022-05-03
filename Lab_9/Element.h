#pragma once

template <class Key, class Value> 
class Element {
public:
	Key key; 
	Value value; 
	unsigned int index;

	Element() {
		this->key = NULL;
		this->value = NULL;
		this->index = 0;
	}
	
	Element(Key key, Value value, unsigned int index) : key(key), value(value), index(index) {}

	~Element() {
		this->key = NULL; 
		this->value = NULL; 
		this->index = 0;
	}

	void operator = (Value value) {
		this->value = value;
	}

};