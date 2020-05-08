cc=gcc -Wall -Wextra -std=c99
H_DIR= headers

all: ./bin/main

./obj/carte.o: ./src/carte.c ./headers/structure.h
	$(cc) -o $@ -c $< -I $(H_DIR)

./obj/structure.o: ./src/structure.c ./headers/carte.h
	$(cc) -o $@ -c $< -I $(H_DIR)

./obj/plateau.o: ./src/plateau.c ./headers/carte.h ./headers/structure.h
	$(cc) -o $@ -c $< -I $(H_DIR)

./obj/interface.o: ./src/interface.c ./headers/plateau.h
	$(cc) -o $@ -c $< -I $(H_DIR)

./obj/main.o: ./src/main.c ./headers/carte.h ./headers/structure.h ./headers/plateau.h ./headers/interface.h
	$(cc) -o $@ -c $< -I $(H_DIR)

./bin/main: ./obj/carte.o ./obj/main.o ./obj/interface.o ./obj/carte.o ./obj/structure.o ./obj/plateau.o
	$(cc) $^ -o $@
