//  main.c
//  Created by Decouty Rémi on 15/03/2020.

#include "interface.h"
#include "plateau.h"
#include "carte.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	plateau p = new_plateau();  // initalise le plateau ainsi que les différentes piles de cartes

	while (win(p) == -1) {
        
		new_tour(&p);
        print_new_tour(p);

		for (int i=0;i<2;i++) {		// 2 phases par tour

			print_new_phase(p.debutEnsiie); // message de nouvelle phase (une par ENSIIE)
            //pioche(&p,p.debutEnsiie);
            print_plateau(p);
            
            if (i!=1){
                if(p.debutEnsiie=='A'){
                    p.debutEnsiie='B';
                    
                }
                else
                    p.debutEnsiie='A';
            }

        }
    }

	print_win_player(p);	// affiche le gagnant de la partie 
	free_plateau (p); // libère la mémoire occupée par le plateau

	return 0;
}
