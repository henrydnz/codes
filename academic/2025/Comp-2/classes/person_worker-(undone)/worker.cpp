#include "worker.h"
#include <iostream>
using namespace std;

Worker::Worker(
    string name, 
    int age, 
    float height, 
    float weight, 
    int group, 
    float salary
) : 
    Person(name, age, height, weight), 
    group(group), 
    salary(salary)
{}

Worker::Worker(const Worker &w) : 
    Person(
        w.getName(),
        w.getAge(),
        w.getHeight(),
        w.getWeight()
    ),
    group(w.getGroup()),
    salary(w.getSalary())
{}

int Worker::getGroup() const{
    return group;
}

float Worker::getSalary() const{
    return salary;
}

void Worker::setGroup(int group){
    this->group=group;
}

void Worker::setSalary(float salary){
    this->salary=salary;
}