#ifndef _ITEM_H_
#define _ITEM_H_

#define MAXROW 25
#define MAXCOL 80
#include <iostream>
#include <cstddef>
using namespace std;
class Game;
class Item {
public:
    enum TYPE{GRASS=1,RABBIT,WOLF,TIGER};
    size_t row;
    size_t col;
    size_t last;
    Game* game;
    Item();
    virtual ~Item() {}
    Item(Game* g, int r, int w);
    virtual void update(int, size_t) = 0;
    virtual void print() = 0;
    virtual TYPE getType()=0;
};
int randomBetween(int lo,int hi);
#endif