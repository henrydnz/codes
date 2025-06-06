#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person{
    private:
        std::string name;
        int age;
        float height;
        float weight;
    public:
        Person(
            std::string name, 
            int age, 
            float height, 
            float weight
        );
        Person(Person &p);

        std::string getName() const;
        int getAge() const;
        float getHeight() const;
        float getWeight() const; 

        void setName(std::string name);
        void setAge(int age);
        void setHeight(float height);
        void setWeight(float weight);

        ~Person();
};  

#endif
