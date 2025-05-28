#include <iostream>
#include "counter.h"

Counter::Counter() : counter(0)
{}

Counter::~Counter()
{}

void Counter::reset(){
    counter=0;
}

void Counter::inc(){
    counter++;
}

int Counter::getCounter() const{
    return counter;
}

