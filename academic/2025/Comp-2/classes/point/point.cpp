#include "point.h"

Point::Point(){
    x = 0;
    y = 0;
}

void Point::setX(double newX){
    Point::x = newX;
}
void Point::setY(double newY){
    Point::y = newY;
}
void Point::setPoint(double newX, double newY){
    Point::setX(newX);
    Point::setY(newY);
}
double Point::getX() const{
    return Point::x;
}
double Point::getY() const{
    return Point::y;
}
