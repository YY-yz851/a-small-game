#ifndef TIGER_H
#define TIGER_H
#include"Predator.h"
class Tiger:public Predator{
    public:
    Tiger(Game*g,int r,int c);
    void update(int ,size_t);
    void print();
    TYPE getType(){return TIGER;};
    ~Tiger();

};
#endif