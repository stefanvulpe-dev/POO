#include <iostream>
#include "Repo.h"

using namespace std;

int main()
{
    Repo* m = new Repo();

    m->Add(m->GetShape("Circle", "red"));
    m->Add(m->GetShape("Square", "yellow"));
    m->Add(m->GetShape("Rectangle", "blue"));
    m->Add(m->GetShape("Rectangle", "red"));
    m->Add(m->GetShape("Circle", "green"));

    m->PrintAll();

    m->Remove("Circle");

    m->PrintAll();

    m->Add(new Circle("green"));
    m->Add(new Rectangle("red"));

    m->Remove("red");

    *m += new Square("cyan");

    m->PrintAll();

    return 0;
}