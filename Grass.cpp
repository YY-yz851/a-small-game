#include "Grass.h"
#include "Game.h"

Grass::Grass(Game* g, int r, int c) 
    : Item(g, r, c) {growth=MAXGROWTH;}

void Grass::update(int c, size_t count) {
    if(growth<MAXGROWTH) growth++;
}

void Grass::print() {
    char ch=' ';
    if(growth>=MAXGROWTH) ch='*';
    else if(growth>=7) ch=':';
    else if(growth>=4) ch='.';
    game->paintAt(row,col,ch);
}

Grass::~Grass() {}