#ifndef COUNTER_H
#define COUNTER_H

class Counter{
    private:
        int counter;
    public: 
        Counter();
        ~Counter();

        void reset();
        void inc();

        int getCounter() const;
}; 

#endif