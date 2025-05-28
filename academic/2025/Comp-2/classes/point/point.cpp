#include <iostream>
#include "point.h"
using namespace std;

Point::Point() : 
    x(0), 
    y(0) 
{}

Point::Point(double newX, double newY) : 
    x(newX), 
    y(newY) 
{}

Point::Point(const Point &p) : 
    x(p.getX()), 
    y(p.getY())
{}

void Point::setX(double newX){
    x = newX;
}

void Point::setY(double newY){
    y = newY;
}

void Point::setPoint(double newX, double newY){
    x = newX;
    y = newY;
}

double Point::getX() const{
    return x;
}

double Point::getY() const{
    return y;
}

Point::~Point(){}