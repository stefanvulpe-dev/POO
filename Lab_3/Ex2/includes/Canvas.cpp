#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring> 

#include "Canvas.h"

Canvas::Canvas(int width, int height)
{
    this -> width = width; 
    this -> height = height; 
    
    this -> canvas = (char **) malloc(height * sizeof(char *));

    for(int i = 0; i < height; ++ i)
    {
        this -> canvas[i] = (char *) malloc(width * sizeof(char));
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for(int i = 0; i < this -> height; ++ i)
    {
        for(int j = 0; j < this -> width; ++ j)
        {
            if((int(pow(i - x, 2)) + int(pow(j - y, 2)) >= ray * (ray - 1)) && (int(pow(i - x, 2)) + int(pow(j - y, 2)) <= ray * (ray + 1)))
            {
                this -> canvas[i][j] = ch;
            }
            else 
                this -> canvas[i][j] = '_';
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for(int i = 0; i < this -> height; ++ i)
    {
        for(int j = 0; j < this -> width; ++ j)
        {
            if((int(pow(i - x, 2)) + int(pow(j - y, 2))) <= int(pow(ray, 2)))
            {
                this -> canvas[i][j] = ch;
            }
            else 
                this -> canvas[i][j] = '_';
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for(int i = top; i <= bottom; ++ i)
    {
        for(int j = left; j <= right; ++ j)
        {
            if(((i > top && i < bottom) && (j == left || j == right)) || ((i == top || i == bottom) && (j >= left && j <= right)))
            {
                this -> canvas[i][j] = ch;
            }
        }
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for(int i = top + 1; i < bottom; ++ i)
    {
        for(int j = left + 1; j < right; ++ j)
        {
            this -> canvas[i][j] = ch;
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if((x >= 0 && x < this -> width) && (y >= 0 && y < this -> height))
        this -> canvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx, dy, D, y;
    
    dx = x2 - x1; 
    dy = y2 - y1;
    D = 2 * dy - dx; 
    y = y1;

    for(int x = x1; x <= x2; ++ x)
    {
        this -> canvas[x][y] = ch; 
        if(D > 0)
        {
            y = y + 1; 
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
    }
}

void Canvas::Print()
{
    for(int i = 0; i < this -> height; ++ i)
    {
        for(int j = 0; j < this -> width; ++ j)
        {
            printf("%c", this ->canvas[i][j]); 
        }
        printf("\n");
    }
}

void Canvas::Clear()
{
    for(int i = 0; i < this -> height; ++ i)
    {
        for(int j = 0; j < this -> width; ++ j)
        { 
            this -> canvas[i][j] = '_';
        }
    }
}

