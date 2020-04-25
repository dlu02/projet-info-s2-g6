cc=gcc -Wall -Wextra -std=c99
OBJ1= main.o structure.o carte.o plateau.o interface.o

all: main

carte.o= carte.c structure.h

structure.o= structure.c carte.h

plateau.o= plateau.c carte.h structure.h

interface.o= interface.c plateau.h

main.o= main.c carte.h structure.h plateau.h interface.h

main: $(OBJ1)
	$(cc) $^ -o $@

clean:
	rm -rf *.o

