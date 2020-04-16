cc=gcc -Wall -Wextra 
OBJ1= main.o structure.o carte.o plateau.o interface.o

all: test_romain

carte.o= carte.c structure.h

structure.o= structure.c carte.h

plateau.o= plateau.c carte.h structure.h

interface.o= interface.c plateau.h

main.o= main.c carte.h structure.h plateau.h interface.h

test_romain: $(OBJ1)
	$(cc) $^ -o $@

clean:
	rm -rf *.o

