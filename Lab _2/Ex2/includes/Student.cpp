#include <cstring>
#include <cstdio>

#include "Student.h"

#define _CRT_SECURE_NO_WARNINGS

Student::Student(const char * name, float mathGrade)
{
    strcpy(this -> name, name); 
    this -> mathGrade = mathGrade;
}

Student::Student()
{
    printf("Empty constructor called\n");
}

void Student::setName(const char * s)
{
    strcpy(this -> name, s);
}

const char * Student::getName()
{
    return this -> name;
}

bool Student::setMathGrade(float grade)
{
    if((grade >= 1.0f) && (grade <= 10.0f))
    {
        this -> mathGrade = grade; 
        return true;
    }  
    return false; 
}

float Student::getMathGrade()
{
    return this -> mathGrade;
}

bool Student::setEnglishGrade(float grade)
{
    if((grade >= 1.0f) && (grade <= 10.0f))
    {
        this -> englishGrade = grade; 
        return true;
    }  
    return false; 
}

float Student::getEnglishGrade()
{
    return this -> englishGrade;
}

bool Student::setHistoryGrade(float grade)
{
    if((grade >= 1.0f) && (grade <= 10.0f))
    {
        this -> historyGrade = grade; 
        return true;
    }  
    return false; 
}

float Student::getHistoryGrade()
{
    return this -> historyGrade;
}

float Student::averageGrade()
{
    return (this-> mathGrade + this -> englishGrade + this -> historyGrade) / 3;
}

