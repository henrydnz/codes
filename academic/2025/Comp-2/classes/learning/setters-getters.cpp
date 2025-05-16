#include <iostream>
#include <cmath>
using namespace std;

class Point{
    private:
        double x;
        double y;

    public:
        Point(){
            x = 0;
            y = 0;
        }

        void setX(double newX){
            x = newX;
        }
        void setY(double newY){
            y = newY;
        }
        void setPoint(double newX, double newY){
            setX(newX);
            setY(newY);
        }
        double const getX(){
            return x;
        }
        double const getY(){
            return y;
        }
        void printPoint(){
            cout << "\n(" << getX() << ", " << getY() << ")\n";
        }
};

class Line{
    private:
        Point a;
        Point b;
    public:
        void setA(double newX, double newY){
            a.setPoint(newX, newY);
        }
        void setB(double newX, double newY){
            b.setPoint(newX, newY);
        }
        void printA(){
            a.printPoint();
        }
        void printB(){
            b.printPoint();
        }
        double distance(){
            return sqrt(
                pow(a.getX() - b.getX(), 2) +
                pow(a.getY() - b.getY(), 2)
            );
        }
};

int main() {
    Line l;
    cout << "distance of line object with two zero points is " << l.distance() << endl;
    cout << "input point A coordinates:\n";
    double ax, ay;
    cin >> ax >> ay;
    l.setA(ax, ay);
    cout << "point A was set to "; l.printA();
    cout << "input point B coordinates:\n";
    double bx, by;
    cin >> bx >> by;
    l.setB(bx, by);
    cout << "Point B was set to"; l.printB();
    cout << "distance of line object with changed points is " << l.distance() << endl;
}