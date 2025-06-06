#ifndef WORKER_H
#define WORKER_H

#include "person.h"

class Worker : public Person {
    private:
        int group;
        float salary;
    public:
        Worker(
            std::string name, 
            int age, 
            float height, 
            float weight, 
            int group, 
            float salary
        );
        Worker(const Worker &w);

        int getGroup() const;
        float getSalary() const;

        void setGroup(int group);
        void setSalary(float salary);
};

#endif