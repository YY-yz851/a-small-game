#ifndef WOLF_H
#define WOLF_H
#include "Predator.h"
class Wolf:public Predator{
    public:
    Wolf(Game* g,int r,int c);
    void update(int ,size_t);
    void print();
    TYPE getType(){return WOLF;}
    ~Wolf();
};
#endif