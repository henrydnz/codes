#ifndef POINT_H
#define POINT_H

class Point{
    private:
        double x, y;

    public:
        Point();    //empty point
        Point(double x, double y);  //(x,y) point
        Point(const Point &p);      //copy of p point

        void setX(double newX);
        void setY(double newY);
        void setPoint(double newX, double newY);
        double getX() const;
        double getY() const;

        ~Point();
};

#define min_error 1e-9

bool feq(double a, double b){
    return fabs(a-b)<min_error;
}
#endif
