cc=gcc -Wall -Wextra 
OBJ1= test.o structure.o carte.o 

all: test_romain

carte.o: carte.c plateau.h

structure.o: structure.c carte.h

test.o=

test_romain: $(OBJ1)
	$(cc) $^ -o $@
