#include "point.h"
#include <iostream>
using namespace std;

int main(){
    Point p;
    p.setPoint(5,4);
    cout << "point is " << p.getX() << " " << p.getY() << endl;
    return 0;
}

