#include <cstdio>
#include <cmath>
#include "Point.h"

Point::Point() {
	this->xloc = 0; 
	this->yloc = 0;
}

Point::Point(int xval, int yval) : xloc(xval), yloc(yval) {}

Point::~Point() {
	this->xloc = 0; 
	this->yloc = 0;
}

int Point::getX() {
	return this->xloc;
}

int Point::getY() {
	return this -> yloc;
}

Point* operator + (const Point& p1, const Point& p2) {
	int x_res = p1.xloc + p2.xloc; 
	int y_res = p1.yloc + p2.yloc; 
	return new Point(x_res, y_res);
}

Point* operator - (const Point& p1, const Point& p2) {
	int x_res = p1.xloc - p2.xloc;
	int y_res = p1.yloc - p2.yloc;
	return new Point(x_res, y_res);
}

double operator , (const Point& p1, const Point& p2) {
	return sqrt(pow(p2.xloc - p1.xloc, 2) + pow(p2.yloc - p1.yloc, 2));
}
