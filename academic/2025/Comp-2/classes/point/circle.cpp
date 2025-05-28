#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "circle.h"
using namespace std;

Circle::Circle(double x, double y, double r) : 
    Point(x, y), 
    radius(r)
{}

Circle::Circle(const Point &p, double r) : 
    Point(p), 
    radius(r) 
{}

Circle::Circle(const Circle &c) : 
    Point(c.getX(), c.getY()), 
    radius(c.getRadius())
{}

Point Circle::getCenter() const{
    return Point(Circle::getX(), Circle::getY());
}

double Circle::getRadius() const{
    return radius;
}

double Circle::getArea() const{
    return M_PI*radius*radius;
}

double Circle::getCircumference() const{
    return 2*M_PI*radius;
}

void Circle::setR(double r){
    radius = r;
    cout << "\nRadius was set to " << r << ".\n";
}

void Circle::incrementR(double d){
    radius+=d;
    cout << "\nRadius increased by " << d << ".\n";
}

void Circle::decrementR(double d){
    radius-=d;
    cout << "\nRadius decreased by " << d << ".\n";
}

void Circle::show() {
    stringstream info;
    info << "(" << Point::getX() << ", " << Point::getY() << ", " << radius << ")";

    cout << "\n--------------\n";
    cout << "Circle: " << info.str() << endl;
    cout << "Area: " << Circle::getArea() << endl;
    cout << "Circumference: " << Circle::getCircumference() << endl;
    cout << "--------------\n";
}

Circle::~Circle(){}
