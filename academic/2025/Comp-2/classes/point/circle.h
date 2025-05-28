#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle : public Point{
    private:

        double radius;

    public:
        Circle(double x, double y, double r);
        Circle(const Point &p, double r);
        Circle(const Circle &c);

        Point getCenter() const;
        double getRadius() const;
        double getArea() const;
        double getCircumference() const;

        void setR(double r);
        void incrementR(double d);
        void decrementR(double d);

        void show();

        ~Circle();
};

#endif
