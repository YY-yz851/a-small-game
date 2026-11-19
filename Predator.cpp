#include"Predator.h"
#include"Game.h"
Predator::Predator(Game* g,int r,int c,int maxhp,int rng)
    :Animal(g,r,c,maxhp),range(rng){}
    Animal* Predator::findPrey(TYPE type) {
        return game->findAnimal(row,col,range,type);
    }
    void Predator::eat(Animal* prey,int gain){
        row=prey->row;
        col=prey->col;
        prey->hp=0;
        heal(gain);
    }
