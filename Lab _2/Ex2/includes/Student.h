#pragma once

class Student 
{
private: 
    char name[256]; 
    float mathGrade, englishGrade, historyGrade; 
public: 
    Student();
    Student(const char * name, float mathGrade);
    void setName(const char * s); 
    const char * getName(); 
    bool setMathGrade(float grade);
    float getMathGrade(); 
    bool setEnglishGrade(float grade);
    float getEnglishGrade();
    bool setHistoryGrade(float grade);
    float getHistoryGrade();  
    float averageGrade(); 
};