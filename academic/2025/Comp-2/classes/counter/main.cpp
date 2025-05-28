#include <iostream>
#include "counter.h"
using namespace std;

int main(){
    Counter c;
    int i=5;

    while(i--){
        c.inc();
    }

    cout << c.getCounter() << endl;

    c.reset();

    cout << c.getCounter() << endl;
    return 0;
}