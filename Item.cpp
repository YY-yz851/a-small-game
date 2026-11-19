#include "Item.h"
#include<cstdlib>

Item::Item() : row (0), col (0), last(0),game(0) {}
Item::Item(Game* g, int r, int c) 
    : game(g), row (r), col (c), last(0) {}
int randomBetween(int lo,int hi){
    return lo+rand()%(hi-lo+1);
}