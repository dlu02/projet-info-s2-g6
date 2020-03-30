cc=gcc -Wall -Wextra 
OBJ1= test.o structure.o carte.o  plateau.o

all: test_romain

carte.o: carte.c plateau.h

structure.o: structure.c carte.h

plateau.o: plateau.c structure.h

test.o= test.c carte.h structure.h plateau.h

test_romain: $(OBJ1)
	$(cc) $^ -o $@
