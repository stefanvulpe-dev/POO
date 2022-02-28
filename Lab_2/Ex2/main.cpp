#include <cstdio> 
#include <cstring> 

#include "includes/Student.h"
#include "includes/GlobalFunctions.h"

#define _CRT_SECURE_NO_WARNINGS

int main()
{
    Student student1 = Student("Yahya Curtis", 5.5);
    Student student2 = Student("Mcauley Wyatt", 9.0);
    Student student3; 
    Student student4;
 
    student1.setEnglishGrade(9.5); 
    student1.setHistoryGrade(8.25);

    student2.setEnglishGrade(7.6); 
    student2.setHistoryGrade(8.4);

    student3.setName("Charles Dickens");
    student3.setMathGrade(9.9);
    student3.setEnglishGrade(7.6); 
    student3.setHistoryGrade(8.4);

    student4.setName("Alison Battle");
    student4.setMathGrade(9.50);
    student4.setEnglishGrade(7.8); 
    student4.setHistoryGrade(6.50);

    printf("Students average grades: \n"); 

    printf("%s: %.2f\n", student1.getName(), student1.averageGrade()); 
    printf("%s: %.2f\n", student2.getName(), student2.averageGrade()); 
    printf("%s: %.2f\n", student3.getName(), student3.averageGrade()); 
    printf("%s: %.2f\n", student4.getName(), student4.averageGrade()); 

    if(compareTo_AverageGrade(&student1, &student4) == 1)
    {
        printf("%s has a greater average grade than %s\n", student1.getName(), student4.getName());
    }
    else if(compareTo_AverageGrade(&student1, &student4) == -1)
    {
        printf("%s has a smaller average grade than %s\n", student1.getName(), student4.getName());
    }
    else 
    {
        printf("%s and %s have the same average grade\n", student1.getName(), student4.getName());
    }

    return 0;
}