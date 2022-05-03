#pragma once
#include <cstdlib>
#include <cstring> 
#include "Element.h"
#include "MyIterator.h"

template <class Key, class Value> 
class Map {
private:
	Element<Key, Value>** arr; 
	unsigned int size; 
public: 
	Map() {
		this->arr = nullptr;
		this->size = 0;
	}

	~Map() {
		for (int i = 0; i < this->size; ++i) {
			delete this->arr[i];
		}
		delete[] this->arr; 
		this->size = 0;
	}

	void Set(Key key, Value value) {
		int ind = this->Contains(key);
		if (ind == -1) {
			if (this->arr == nullptr) {
				this->arr = new Element<Key, Value>*[1];
				this->arr[this->size] = new Element<Key, Value>(key, value, this->size);
			}
			else {
				this->arr = (Element<Key, Value>**)(realloc(this->arr, (static_cast<unsigned long long>(this->size) + 1) * sizeof(Element<Key, Value>*)));
				this->arr[this->size] = new Element<Key, Value>(key, value, this->size);
			}
			this->size++;
		}
		else {
			this->arr[ind]->value = value;
		}
	}

	bool Get(const Key& key, Value& value) {
		int ind = this->Contains(key); 
		if (ind != -1) {
			value = this->arr[ind]->value; 
			return true;
		}
		return false;
	}

	unsigned int Count() {
		return this->size; 
	}

	void Clear() {
		for (int i = 0; i < this->size; ++i) {
			delete this->arr[i];
			this->arr[i] = nullptr;
		}
		delete[] this->arr;
		this->arr = nullptr;
		this->size = 0;
	}

	bool Delete(const Key& key) {
		int index = this->Contains(key);

		if (index != -1) {
			delete this->arr[index]; 
			this->arr[index] = nullptr; 

			for (int i = index + 1; i < this->size; ++i) {
				this->arr[i - 1] = this->arr[i];
			}

			this->size--;
			return true;
		}
		
		return false;
	}

	bool Includes(const Map<Key, Value>& map) {
		for (int i = 0; i < map.size; ++i) {
			if (this->Contains(map.arr[i]->key) == -1) {
				return false;
			}
		}
		return true;
	}

	unsigned int Contains(const Key& key) {
		for (int i = 0; i < this->size; ++i) {
			if (this->arr[i]->key == key) {
				return i;
			}
		}
		return -1;
	}

	Element<Key, Value>& operator[](Key key) {
		int index = this->Contains(key); 
		if (index != -1) {
			return *(this->arr[index]); 
		}
		else {
			this->arr = (Element<Key, Value>**)(realloc(this->arr, (static_cast<unsigned long long>(this->size) + 1) * sizeof(Element<Key, Value>*)));
			this->arr[this->size] = new Element<Key, Value>(key, NULL, this->size);
			this->size++;
			return *(this->arr[this->size - 1]);
		}
	}

	MyIterator<Key, Value> begin() {
		return MyIterator<Key, Value>(this->arr);
	}
	
	MyIterator<Key, Value> end() {
		return MyIterator<Key, Value>(this->arr + this->size);
	}
};