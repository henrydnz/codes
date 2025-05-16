#ifndef POINT_H
#define POINT_H

class Point{
    private:
        double x;
        double y;

    public:
        Point();
        void setX(double newX);
        void setY(double newY);
        void setPoint(double newX, double newY);
        double getX() const;
        double getY() const;
        ~Point();
};

#endif
