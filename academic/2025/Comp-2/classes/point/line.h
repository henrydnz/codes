#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line{
    private:
        //Linear coefficient
        double cl;
        //Angular coefficient
        double ca;
        //vertical flag
        bool is_vertical;
        //just used if is_vertical=true
        double x_intercept;

    public:
        //create line passing through (0,0) and p
        Line(const Point &p);
        //create line passing through p1 and p2
        Line(const Point &p1, const Point &p2);
        ~Line();

        double get_cl() const;
        double get_ca() const;
        bool get_is_vertical() const;
        double get_x_intercept() const;
        
        bool is_perpendicular(const Line &l);
        bool is_parallel(const Line &l);
        bool is_same(const Line &l);
        bool is_in(const Point &p);
        
        Point* get_intersection_point(const Line &l);
        double get_angle(const Line &l);
        double get_distance(const Line &l);

};

#endif



