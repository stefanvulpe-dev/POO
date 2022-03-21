#include <cstdio> 

#include "includes/Number.h"

#define _CRT_SECURE_NO_WARNINGS

int main()
{
    Number n1("10110010", 2);

    Number n2("734",8);

    Number n3("FF",16);

    Number n7("1AA3", 11);

    Number n8("2AB9", 12);

    n7.Print(); 

    n8.Print();

    n7 += n8;

    printf("n8 added to n7: ");

    n7.Print();

    printf("n1 has %d digits and it is written in base %d\n",n1.GetDigitsCount(),n1.GetBase());

    for(int tr = 0; tr < n1.GetDigitsCount(); tr ++)
    {
        printf("n1[%d]=%c\n",tr,n1[tr]);
    }

    n1.Print();

    n2.Print();

    n1 = (n2+n3-n1)+n1; // after this n1 will be in base 16

    printf("n1 is in base: %d\n", n1.GetBase());

    n1.SwitchBase(2);

    printf("Now in base: %d\n", n1.GetBase());

    n1.Print();

    if (n1 > n2) 
        printf("n1 is bigger than n2\n");
    else 
        printf("n2 is bigger than n1\n");

    Number n4 = 12345; // n4 will be in base 10

    n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)

    n4 += n1; 

    n4.Print();

    n4 = "13579"; // n4 mentains its base (10) and will be 13579

    n4.Print();

    --n4; // the first digit from n4 will be remove ==> n4 becomes 3579

    n4.Print();

    n4--; // the last digit from n4 will be remove ==> n4 becomes 357

    n4.Print();

    Number n5("AAB", 16);

    Number n6("101010101011", 2); 

    if(n5 == n6)
    {
        printf("The values: \nn1 = ");
        n5.Print(); 
        printf("and\nn2 = ");
        n6.Print(); 
        printf("are equal.\n");
    }
    else
    {
        printf("Given numbers are not equal\n");
    }

    return 0;
}