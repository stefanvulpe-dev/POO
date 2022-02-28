#include <cstring>

#include "GlobalFunctions.h"

int compareTo_Name(Student * s1, Student * s2)
{
    if(strcmp(s1 -> getName(), s2 -> getName()) > 0)
        return 1; 
    else if(strcmp(s1 -> getName(), s2 -> getName()) < 0)
        return -1;
    else
        return 0;
}

int compareTo_MathGrade(Student * s1, Student * s2)
{
    if(s1 -> getMathGrade() > s2 -> getMathGrade())
        return 1; 
    else if(s1 -> getMathGrade() < s2 -> getMathGrade())
        return -1; 
    else 
        return 0;
}

int compareTo_EnglishGrade(Student * s1, Student * s2)
{   
    if(s1 -> getEnglishGrade() > s2 -> getEnglishGrade())
        return 1; 
    else if(s1 -> getEnglishGrade() < s2 -> getEnglishGrade())
        return -1; 
    else 
        return 0;
}

int compareTo_HistoryGrade(Student * s1, Student * s2)
{
    if(s1 -> getHistoryGrade() > s2 -> getHistoryGrade())
        return 1; 
    else if(s1 -> getHistoryGrade() < s2 -> getHistoryGrade())
        return -1; 
    else 
        return 0;
}

int compareTo_AverageGrade(Student * s1, Student * s2)
{
    if(s1 -> averageGrade() > s2 -> averageGrade())
        return 1; 
    else if(s1 -> averageGrade() < s2 -> averageGrade())
        return -1; 
    else 
        return 0;
}