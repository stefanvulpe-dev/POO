#include <cstdio>
#include "Student.h"
#include "Catalog.h"

int main()
{
    Catalog c; 

    c += {"Andrei"};
    c += {"Roxana"}; 
    c += {"Sorin"}; 

    c["Andrei"]["matematica"] = 8;
    c["Andrei"]["romana"] = 7; 
    c["Andrei"]["franceza"] = 6;
    c["Roxana"]["matematica"] = 9; 
    c["Roxana"]["romana"] = 10; 
    c["Sorin"]["sport"] = 5;
    c["Sorin"]["romana"] = 9;

    printf("Total studenti: %d\n", c.getCount()); 

    for (int index = 0; index < c.getCount(); ++index) {
        printf("Nume: %s\n", c[index].getName());
        printf("Media: %.2f\n", (float)c[index]);
        c[index].PrintNote();
    }

    return 0;
}

