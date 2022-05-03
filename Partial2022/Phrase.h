#pragma once

class Phrase {
private: 
	char* text; 
	char** wordsArray; 
	int arr_size;
public:
	Phrase(); 
	Phrase(const char* str); 
	~Phrase(); 
	int CountLetter(char ch);
	int CountLetter(int index, char ch);
	int CountVowels();
	int getLength(const char* str);
	const char* GetLongestWord(); 
	const char* operator [] (int index);
	operator int(); 
};