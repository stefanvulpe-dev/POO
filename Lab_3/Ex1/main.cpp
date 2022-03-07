#include <cstdio>
#include <cstring>  
#include "includes/Math.h"

#define _CRT_SECURE_NO_WARNINGS

int main()
{
    //Add two integers
    int resAddTwo = Math::Add(5, 20); 
    printf("Added two integers: %d\n", resAddTwo);\

    //Add three integers
    int resAddThree = Math::Add(0, -71, 35); 
    printf("Added three integers: %d\n", resAddThree); 

    //Add two doubles
    double resAddTwoD = Math::Add(5.25, 7.5);
    printf("Added two doubles: %.2lf\n", resAddTwoD); 

    //Add three doubles
    double resAddThreeD = Math::Add(5.6, 9.3, 12.5);
    printf("Added three doubles: %.2lf\n", resAddThreeD); 

    //Multiplied two integers
    int resMulTwo = Math::Mul(5, 20); 
    printf("Multiplied two integers: %d\n", resMulTwo);

    //Multiplied three integers
    int resMulThree = Math::Mul(0, -71, 35); 
    printf("Multiplied three integers: %d\n", resMulThree);

    //Multiplied two doubles
    double resMulTwoD = Math::Mul(5.25, 7.5);
    printf("Multiplied two doubles: %.2lf\n", resMulTwoD); 

    //Multiplied three doubles
    double resMulThreeD = Math::Mul(5.6, 9.3, 12.5);
    printf("Multiplied three doubles: %.2lf\n", resMulThreeD);

    //Added a list of numbers
    int resAddList = Math::Add(5, 2, 3, 5, 7, 9); 
    printf("Added a list of integers: %d\n", resAddList);

    //Concatenate two strings
    const char * result = Math::Add("Stefan", "Vulpe"); 
    printf("Concatenated two strings: %s\n", result);

    return 0;
}