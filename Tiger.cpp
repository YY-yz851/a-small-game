#include"Tiger.h"
#include"Game.h"
Tiger::Tiger(Game* g,int r,int c):
Predator(g,r,c,7,3){}
void Tiger::update(int c,size_t count){
    Animal* prey=findPrey(RABBIT);
    if(prey!=0){
        eat(prey,1);
        return;
    }
    Animal* wolf=findPrey(WOLF);
    if(wolf!=0&&randomBetween(1,3)==1){
        eat(wolf,2);
        return;
    }
    jump(3);
    hp=hp-1;
    return;
}
void Tiger::print(){
    game->paintAt(row,col,'T');
}
Tiger::~Tiger(){}