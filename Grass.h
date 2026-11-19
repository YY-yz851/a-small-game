#ifndef GRASS_H
#define GRASS_H
#include "Item.h"
#include <iostream>
using namespace std;
class Grass:public Item {
    int growth;
public:
    static const int MAXGROWTH=10;
    Grass(Game* g, int r, int w);
    void update(int, size_t);
    void print();
    TYPE getType(){return GRASS;}
    bool isFull()const{return growth>=MAXGROWTH;}
    void setGrowth(int g){growth=g;}
    int getGrowth(){return growth;}
    ~Grass();
};





#endif
