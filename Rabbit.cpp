#include"Rabbit.h"
#include"Game.h"
#include"Grass.h"
 Rabbit::Rabbit(Game* g,int r,int c):Animal(g,r,c,3){}
 void Rabbit:: update(int c,size_t count){
    jump(1);
    Grass* food=game->getGrass(row,col);
    if(food->isFull()){
        food->setGrowth(0);
        heal(1);
    }else{
        hp=hp-1;
    }
    }
    void Rabbit::print(){
        game->paintAt(row,col,'R');
    }

Rabbit::~Rabbit(){}
