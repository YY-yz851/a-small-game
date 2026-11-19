#ifndef RABBIT_H
#define RABBIT_H
#include "Animal.h"
class Rabbit : public Animal{
    public:
    Rabbit(Game* g,int r,int c);
    void update(int,size_t);
    void print();
    TYPE getType(){return RABBIT;}
  ~Rabbit();

};

#endif