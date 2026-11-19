#include "Game.h"
#include <cstdlib>
#include <ctime>
#include<cstring>
#include"Wolf.h"
#include "Rabbit.h"
#include "Tiger.h"
#include"Grass.h"
#include<sstream>
#include<string>

Game::Game(int tigers,int wolves,int rabbits) {
    count = 0;
    running=true;
    initGrass();
    addAnimals(Item::TIGER,tigers);
    addAnimals(Item::WOLF,wolves);
    addAnimals(Item::RABBIT,rabbits);
}

Game::~Game(){
   gui.end();
   list<Animal*>::iterator it;
   for(it=animals.begin();it!=animals.end();it++){
    delete *it;
   } 
   animals.clear();
   for(size_t i=0;i<grass.size();i++){
    delete grass[i];
   }
   grass.clear();

}
void Game::initGrass(){
    for(int r=0;r<MAXROW;r++){
        for(int c=0;c<MAXCOL;c++){
            grass.push_back(new Grass(this,r,c));
        }
    }
}
void Game::addAnimal(Item:: TYPE type){
    int r=randomBetween(0,MAXROW-1);
    int c=randomBetween(0,MAXCOL-1);
    Animal* a=0;
    if(type==Item::TIGER) a=new Tiger(this,r,c);
    else if (type==Item::WOLF) a=new Wolf(this,r,c);
    else if(type==Item::RABBIT) a=new Rabbit(this,r,c);
    if(a!=0) animals.push_back(a);
}
void Game::addAnimals(Item::TYPE type,int n){
    for(int i=0;i<n;i++){
        addAnimal(type);
    }
}
Grass* Game ::getGrass(size_t r,size_t c){
    return grass[r*MAXCOL+c];
}
Animal* Game::findAnimal(size_t r,size_t c,int range,Item::TYPE type){
    vector<Animal*> found;
    list<Animal*>::iterator it;
    for(it=animals.begin();it!=animals.end();it++){
        Animal*a=*it;
        if(a->isDead()) continue;
        if(a->getType()!=type) continue;
        int dr=(int)a->row-(int)r;
        if(dr<0) dr=-dr;
        int dc=(int)a->col-(int)c;
        if(dc<0) dc=-dc;
        if(dr<=range&&dc<=range) found.push_back(a);
    }
    if(found.size()==0) return 0;
    return found[randomBetween(0,(int)found.size()-1)];
}
void Game::update(){
    count++;
    int c=gui.get();
    if(c=='q'){
        running=false;
        return;
    }
    if(c=='a'){
        if(randomBetween(0,1)==0) addAnimal(Item::WOLF);
        else addAnimal(Item::TIGER);
    }
    if(c=='d'){
        addAnimal(Item::RABBIT);
    }
    updateGrass(c,count);
    updateAnimals(c,count);
    removeDeadAnimals();
    draw();
    gui.redraw();
}
void Game::updateGrass(int c,size_t count){
    for(size_t i=0;i<grass.size();i++){
        grass[i]->update(c,count);
    }
}

void Game::updateAnimals(int c, size_t count) {
    list<Animal*>::iterator bi = animals.begin();
    while (bi != animals.end() ) {
        if((*bi)->isDead()){
        ++bi;
        continue;
                }
                (*bi)->update(c,count);
                ++bi;
    }
}
void Game::removeDeadAnimals(){
    list<Animal*>::iterator it=animals.begin();
    while(it!=animals.end()){
        if((*it)->isDead()){
            delete *it;
            it=animals.erase(it);
        }
        else{
            ++it;
        }
    }
}
void Game::draw(){
    for(size_t i=0;i<grass.size();i++){
        grass[i]->print();
    }
    list<Animal*> ::iterator it=animals.begin();
    while(it!=animals.end()){
        (*it)->print();
        ++it;
    }
    ostringstream os;
    os<<"Day: "<<(int)count<<"  Tiger: "<<countType(Item::TIGER)<<"  Wolf: "<<countType(Item::WOLF)<<"  Rabbit: "<<countType(Item::RABBIT)<<"    a:add predator  d:add rabbit  q:quit";
    string line=os.str();
    while(line.size()<MAXCOL){
          line=line+' ';
    }
    printMsg(MAXROW,0,line.c_str());
}
int Game::countType(Item::TYPE type){
    int n=0;
    list<Animal*>::iterator it=animals.begin();
    while(it!=animals.end()){
        if((*it)->getType()==type&&(*it)->isDead()==false){
            ++n;
        }
        ++it;
    }
    return n;
}

void Game::paintAt(size_t r, size_t c, char x) {
    gui.paintat(r, c, x);
}
void Game::printMsg(size_t r, size_t c, const char* s) {
    gui.printMsg(r, c, s);
}

