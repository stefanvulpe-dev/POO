#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>

template <class T>
class MyVector {	
	private:
		T** arr; 
		int size; 
		int length; 

		void resize() {
			this->size *= 2;
			if (this->arr != nullptr) {
				this->arr = (T**)(realloc(this->arr, this->size * sizeof(T*)));
			}
		}

	public:
		MyVector() {
			this->arr = (T**)(malloc(sizeof(T*)));
			this->size = 1;
			this->length = 0;
		}

		void push(T* t) {
			if (this->length + 1 > this->size) {
				resize();
			}

			this->length++;
			this->arr[this->length - 1] = t;
		}

		void remove(int index) {
			if (index >= 0 && index < this->length) {
				free(this->arr[index]); 
				this->arr[index] = nullptr;

				for (int i = index + 1; i < this -> length; ++i) {
					this->arr[i - 1] = this->arr[i];
				}

				this->length--;
			}
		}

		void printArray() {
			for (int i = 0; i < this->length; ++i) {
				if (i != this->length - 1) {
					printf("%s %s, ", this->arr[i]->getName(), this->arr[i]->getModel());
				}
				else {
					printf("%s %s", this->arr[i]->getName(), this->arr[i]->getModel());
				}
			}
			printf("\n");
		}

		void insert(T* t, int index) {
			if (index >= 0 && index <= this->length) {
				if (this->length + 1 > this->size)
					this->resize();

				this->arr[this->length] = nullptr;

				for (int i = this->length; i > index; --i) {
					this->arr[i] = this->arr[i - 1];
				}

				this->arr[index] = t;
				this->length += 1;
			}
		}

		void set(T* t, int index) {
			if (index >= 0 && index < this->length) {
				free(this->arr[index]);
				this->arr[index] = (T*)(malloc(sizeof(T*)));
				this->arr[index] = t;
			}
		}
		
		const T& get(int index) {
			if (index >= 0 && index < this->length) {
				return *(this->arr[index]);
			}
		}

		T& pop() {
			return *(this->arr[this->length - 1]);
		}

		int count() {
			return this->length;
		}

		int firstIndexOf(T* t, bool(*func)(T&, T&) = nullptr) {
			if (func == nullptr) {
				for (int i = 0; i < this->length; ++i) {
					if (*this->arr[i] == *t) {
						return i;
					}
				}
			}
			else {
				for (int i = 0; i < this->length; ++i) {
					if (func(*this->arr[i], *t)) {
						return i;
					}
				}
			}
			return -1;
		}

		void sort(bool(*func)(T&, T&) = nullptr) {
			bool ok;
			T* aux = nullptr;
			if (func == nullptr) {
				do {
					ok = true; 
					for (int i = 0; i < this->length - 1; ++i) {
						if (*this->arr[i] < *this->arr[i + 1]) {
							aux = this->arr[i]; 
							this->arr[i] = this->arr[i + 1]; 
							this->arr[i + 1] = aux; 
							ok = false;
						}
					}
				} while (ok == false);
			} 
			else {
				do {
					ok = true;
					for (int i = 0; i < this->length - 1; ++i) {
						if (func(*this->arr[i], *this->arr[i + 1])) {
							aux = this->arr[i];
							this->arr[i] = this->arr[i + 1];
							this->arr[i + 1] = aux;
							ok = false;
						}
					}
				} while (ok == false);
			}
		}

		void deleteVector() {
			free(this->arr);
		}

};