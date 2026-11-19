#include"Wolf.h"
#include"Game.h"
Wolf::Wolf(Game* g,int r,int c):
Predator(g,r,c,5,2){}
void Wolf::update(int c,size_t count){
    Animal*prey=findPrey(RABBIT);
    if(prey!=0){
        eat(prey,1);
    }
    else{
        jump(2);
        hp=hp-1;
    }
}
    void Wolf::print(){
        game->paintAt(row,col,'W');
    }

    Wolf::~Wolf(){}

