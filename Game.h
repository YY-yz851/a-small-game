#ifndef _GAME_H_
#define _GAME_H_
#include <list>
#include<vector>
#include "Gui.h"
#include "Item.h"
using namespace std;
class Animal;
class Grass;

class Game {
    Gui gui;
    list <Animal*> animals;
    vector<Grass*> grass;
    size_t count;
    bool running;
public:
    Game(int tigers,int wolves,int rabbits);
    ~Game() ;
    void paintAt(size_t r, size_t c, char x);
    void printMsg(size_t r, size_t c, const char* s);
    void initGrass();
    void addAnimal(Item::TYPE type);
    void addAnimals(Item::TYPE type,int n);
    Grass* getGrass(size_t r,size_t c);
    Animal* findAnimal(size_t r,size_t c,int range,Item::TYPE type);
    void update();
    void updateGrass(int c,size_t count);
    void updateAnimals(int c,size_t count);
    void removeDeadAnimals();
    int countType(Item::TYPE type);
    void draw();
    bool isRunning() const {return running;}
};
#endif
