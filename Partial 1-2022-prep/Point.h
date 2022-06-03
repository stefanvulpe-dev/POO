#pragma once

class Point {
private: 
	int xloc; 
	int yloc; 
public:
	Point(); 
	Point(int xval, int yval); 
	~Point();
	int getX();
	int getY();
	friend Point* operator + (const Point& p1, const Point& p2); 
	friend Point* operator - (const Point& p1, const Point& p2);
	friend double operator , (const Point& p1, const Point& p2);
};