#ifndef PREDATOR_H
#define PREDATOR_H
#include"Animal.h"
class Predator:public Animal{
 protected:
     int range;
     Animal* findPrey(TYPE type);
     void eat(Animal* prey,int gain);
public:
    Predator(Game*g,int r,int c,int maxhp,int rng);
    virtual ~Predator(){}

};
#endif