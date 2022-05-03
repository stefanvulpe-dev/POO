#include <cstdio>
#include "Point.h"

int main()
{
    Point* p1 = new Point(5, 10); 
    Point* p2 = new Point(-3, 7); 

    printf("p1: x = %d, y = %d\n", p1->getX(), p1->getY());
    printf("p2: x = %d, y = %d\n", p2->getX(), p2->getY());
    printf("Adunare:\n");

    Point* p3 = (*p1 + *p2);

    printf("p3: x = %d, y = %d\n", p3->getX(), p3->getY());

    printf("Scadere:\n");
    
    p1 = (*p1 - *p3);

    printf("p1: x = %d, y = %d\n", p1->getX(), p1->getY());

    printf("Distanta dintre p1 si p3:\n%.2f", (*p1, *p3));

    return 0;
}

