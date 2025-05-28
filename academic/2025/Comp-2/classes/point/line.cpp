#include <iostream>
#include <cmath>
#include "line.h"
using namespace std;

Line::Line(const Point &p) { 
    if(!p.getX()) {
        if(!p.getY())
            throw invalid_argument("Point (0,0) not allowed.\n");
        else { 
            is_vertical=true;
            x_intercept=p.getX();
            cout << "Constructed vertical line passing through " << x_intercept << "." << endl;
        }
    } else {
        is_vertical=false;
        ca = p.getY()/p.getX();
        cl = p.getY() - ca*p.getX();
        cout << "Constructed Line passing through the Origin and the given Point." << endl; 
    }
}

Line::Line(const Point &p1, const Point &p2) { 
    if(feq(p1.getX(), p2.getX())){
        if(feq(p2.getY(), p2.getY()))
            throw invalid_argument("Equal points not allowed\n");
        is_vertical = true;
        x_intercept = p1.getX();
        cout << "Constructed vertical Line passing through " << x_intercept << "." << endl;
    } else {
        is_vertical = false;
        ca = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
        cl = p1.getY() - ca*p1.getX();
        cout << "Constructed Line passing through the given points." << endl; 
    }
}

Line::~Line() { cout << "Destructed Line." << endl;}

double Line::get_cl() const { return cl; }
double Line::get_ca() const { return ca; }
bool Line::get_is_vertical() const { return is_vertical; }
double Line::get_x_intercept() const { return x_intercept; }

bool Line::is_perpendicular(const Line &l){ 
    return (is_vertical) ?
        (l.get_is_vertical() ? false : !l.get_ca()) :
        (l.get_is_vertical() ? !ca : feq(l.get_ca()*ca, -1));
}

bool Line::is_parallel(const Line &l){
    return (is_vertical)?
        (l.get_is_vertical() ? true : false) :
        (l.get_is_vertical() ? false : feq(l.get_ca(), ca));
}

bool Line::is_same(const Line &l){
    return (is_vertical)?
        (l.get_is_vertical() ? feq(l.get_x_intercept(), x_intercept) : false) :
        (l.get_is_vertical() ? false : feq(l.get_ca(), ca) && feq(l.get_cl(), cl));
}

bool Line::is_in(const Point &p){
    return (is_vertical) ? feq(p.getX(), x_intercept) : p.getY() == ca*p.getX() + cl;
}


Point* Line::get_intersection_point(const Line &l){
    // ! implement vertical handling !
    Point *p = nullptr;
    if(!Line::is_parallel(l)){
        double x = (l.get_cl() - cl) / (ca - l.get_ca());
        double y = ca*x + cl;
        p = new Point(x, y);
    } else
        cout << "Error: Lines don't touch or are the same. Returning null." << endl; 
    return p;
}

double Line::get_angle(const Line &l){
    // ! implement vertical handling !   
    if(!Line::is_parallel(l))
        return (Line::is_perpendicular(l))? 90 : atan(fabs((l.get_ca() - ca) / (1 + l.get_ca()*ca)));
    else{    
        cout << "Error: Lines are parallel or are the same." << endl;
        return -1;
    }
}

double Line::get_distance(const Line &l){
    // ! implement vertical handling !
    if(Line::is_parallel(l))
        return (Line::is_same(l))? 0 : fabs(cl - l.get_cl()) / sqrt(1+pow(ca, 2));
    else{
        cout << "Error: Lines are not parallel. No distance." << endl;
        return -1;
    }
}

