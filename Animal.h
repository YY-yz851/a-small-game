#ifndef ANIMAL_H
#define ANIMAL_H
#include "Item.h"
class Animal:public Item{
    public:
    int hp;
    int maxHp;
    Animal(Game*g,int r,int c,int maxhp);
    virtual ~Animal(){}
    bool isDead() const {
        return hp<=0;
    }
    void jump(int range);
    void heal(int add);
};

#endif