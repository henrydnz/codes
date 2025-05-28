#include "circle.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void clrscr() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){
    clrscr();

    cout << "showing bob's habilities...\n";

    Circle bob(4, 9, 5);
    bob.show();

    bob.incrementR(12);
    bob.show();

    bob.decrementR(4);
    bob.show();

    bob.setR(5);
    bob.show();

    cout << "\ncreating bob's copy...\n";

    Circle secondBob(bob);
    secondBob.show();

    cout << "\nCreating another bob using a Point\n";

    Point bobCenter(4,8);
    Circle anotherBob(bobCenter, 7);
    anotherBob.show();

    return 0;
}

