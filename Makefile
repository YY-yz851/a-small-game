CC = g++
CCFLAGS = -g
CCLIBS = -lncurses

OBJS = main.o Gui.o Game.o Item.o Grass.o Animal.o Predator.o Rabbit.o Wolf.o Tiger.o

mygame: $(OBJS)
	$(CC) $(CCFLAGS) -o mygame $(OBJS) $(CCLIBS)

main.o: main.cpp
	$(CC) $(CCFLAGS) -c -o main.o main.cpp

Gui.o: Gui.cpp Gui.h
	$(CC) $(CCFLAGS) -c -o Gui.o Gui.cpp

Game.o: Game.cpp Game.h
	$(CC) $(CCFLAGS) -c -o Game.o Game.cpp

Item.o: Item.cpp Item.h
	$(CC) $(CCFLAGS) -c -o Item.o Item.cpp

Grass.o: Grass.cpp Grass.h
	$(CC) $(CCFLAGS) -c -o Grass.o Grass.cpp

Animal.o: Animal.cpp Animal.h
	$(CC) $(CCFLAGS) -c -o Animal.o Animal.cpp

Predator.o: Predator.cpp Predator.h
	$(CC) $(CCFLAGS) -c -o Predator.o Predator.cpp

Rabbit.o: Rabbit.cpp Rabbit.h
	$(CC) $(CCFLAGS) -c -o Rabbit.o Rabbit.cpp

Wolf.o: Wolf.cpp Wolf.h
	$(CC) $(CCFLAGS) -c -o Wolf.o Wolf.cpp

Tiger.o: Tiger.cpp Tiger.h
	$(CC) $(CCFLAGS) -c -o Tiger.o Tiger.cpp

clean:
	rm -rf mygame *.o
