#include "person.h"
#include <iostream>
using namespace std;

Person::Person(
    string name, 
    int age, 
    float height, 
    float weight
) : name(name),
    age(age),
    height(height),
    weight(weight) 
{}

Person::Person(Person &p) : 
    name(p.getName()), 
    age(p.getAge()), 
    height(p.getHeight()),
    weight(p.getWeight())
{}

string Person::getName() const{
    return name;
}

int Person::getAge() const{
    return age;
}

float Person::getHeight() const{
    return height;
}

float Person::getWeight() const{
    return weight;
}

void Person::setName(string name){
    this->name=name;
}

void Person::setAge(int age){
    this->age=age;
}

void Person::setHeight(float height){
    this->height=height;
}

void Person::setWeight(float weight){
    this->weight=weight;
}

Person::~Person(){}