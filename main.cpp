#include <ncurses.h>
#include "Gui.h"
#include <sys/time.h>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <cstddef>
#include "Game.h"
using namespace std;


int main(int argc,char* argv[])
{
    int Tigers=atoi(argv[1]);
    int Wolves=atoi(argv[2]);
    int Rabbits=atoi(argv[3]);

    srand(time(0));
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t oldTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    time_t currentTime =  oldTime;
    Game game(Tigers,Wolves,Rabbits);
    while (game.isRunning()) {
        gettimeofday(&time_now, NULL);
        currentTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
        if (currentTime - oldTime < 60) {usleep(22);continue;}
        game.update();
        oldTime = currentTime;
    }
    return 0;
}
