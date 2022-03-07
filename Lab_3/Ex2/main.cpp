#include <cstdio> 
#include <cmath>
#include "includes/Canvas.h"

#define _CRT_SECURE_NO_WARNINGS

int main()
{
    Canvas c(50, 50);

    c.DrawCircle(5, 5, 5, '*');

    c.FillCircle(5, 5, 5, '*');

    c.DrawRect(30, 30, 40, 40, '?');

    c.FillRect(30, 30, 40, 40, '?');

    c.DrawLine(15, 15, 25, 25, '~');

    c.SetPoint(12, 12, '&');

    c.Print();

    return 0;
}