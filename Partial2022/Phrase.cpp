#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "Phrase.h"

Phrase::Phrase() {
	this -> text = nullptr; 
	this -> wordsArray = nullptr;
	this->arr_size = 0;
}

Phrase::Phrase(const char* str) {
	int length = 0, wordCount = 0, cnt;
	char tmpStr[100];

	for (int i = 0; str[i] != '\0'; ++i) {
		length++;
	}
	
	this->text = new char[length + 1];
	
	memcpy(this->text, str, length);

	this->text[length] = '\0';

	this->wordsArray = new char* [length + 1];

	for (int i = 0; this->text[i]; ++i) {
		if ((this->text[i] >= 'a' && this->text[i] <= 'z') || (this->text[i] >= 'A' && this->text[i] <= 'Z')) { 
			cnt = 0;
			while ((this->text[i] != ' ') && (this->text[i] != '\0')) {
				tmpStr[cnt++] = this->text[i];
				i++;
			}
			tmpStr[cnt] = '\0'; 
			this->wordsArray[wordCount] = new char[cnt + 1];
			memcpy(this->wordsArray[wordCount], tmpStr, cnt);
			this->wordsArray[wordCount][cnt] = '\0';
			wordCount++; 
		}
	}

	this->arr_size = wordCount;
}

Phrase::~Phrase() {
	delete [] this->text;
	this->text = nullptr;
	for (int i = 0; i < this->arr_size; ++i) {
		delete [] this->wordsArray[i];
		this->wordsArray[i] = nullptr;
	}
	delete [] this->wordsArray;
	this->wordsArray = nullptr;
	this->arr_size = 0;
}

int Phrase::CountLetter(char ch) {
	int cnt = 0;
	for (int i = 0; this->text[i]; ++i) {
		if (this->text[i] == ch) {
			cnt++;
		}
	}
	return cnt;
}

int Phrase::CountLetter(int i, char ch) {
	if (this->operator[](i)) {
		int cnt = 0;
		for (int j = 0; this->wordsArray[i][j]; ++j) {
			if (this->wordsArray[i][j] == ch) {
				cnt++;
			}
		}
		return cnt;
	}
	return 0;
}

int Phrase::CountVowels() {
	int vowelCount = 0;
	for (int i = 0; this->text[i]; ++i) {
		if ((this->text[i] == 'a') || (this->text[i] == 'e') | (this->text[i] == 'i') || (this->text[i] == 'o') || (this->text[i] == 'u')
			|| (this->text[i] == 'A') || (this->text[i] == 'E') | (this->text[i] == 'I') || (this->text[i] == 'O') || (this -> text[i] == 'U')) {
			vowelCount++;
		}
	}
	return vowelCount;
}

int Phrase::getLength(const char* str) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		count++;
	}
	return count;
}

const char* Phrase::GetLongestWord() {
	int maxi = 0;
	for (int i = 0; i < this->arr_size; ++i) {
		if (getLength(this->wordsArray[i]) > maxi) {
			maxi = getLength(this->wordsArray[i]);
		}
	}
	
	for (int i = 0; i < this->arr_size; ++i) {
		if (getLength(this->wordsArray[i]) == maxi) {
			return this->wordsArray[i];
		}
	}

	return nullptr;
}

const char* Phrase::operator [] (int index) {
	if (index >= 0 && index < this->arr_size) {
		return this->wordsArray[index];
	}
	return nullptr;
}

Phrase::operator int() {
	return this->arr_size;
}

