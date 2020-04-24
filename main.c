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
            pioche(&p,p.debutEnsiie);
            print_plateau(p);
            
            // j'ai un seg fault à cette endroit
            int numero_carte= ask_carte_ou_fin(p,p.debutEnsiie);
            
            while (numero_carte!=-1){
                
                if (p.debutEnsiie=='A'){
                    //si on demande une carte FISE ou FISA
                    if(numero_carte==Fise || numero_carte==Fisa){
                        carte_ajouter(numero_carte,&p,p.debutEnsiie); //ok
                    }
                    //si on veut jouer une carte de la main
                    else if (deck_carteIn(p.mainA, numero_carte)){
                        carte c= deck_remove_indice(&(p.mainA), numero_carte);
                        carte_jouer(c,&p,p.debutEnsiie);
                    }
                }
                
                else{
                }
            }
                    
            if (i!=1){
                if(p.debutEnsiie=='A'){
                    p.debutEnsiie='B';
                    
                }
                else
                    p.debutEnsiie='A';
            }

        }
    }
    carte_fin(&p);
	print_win_player(p);	// affiche le gagnant de la partie 
	free_plateau (p); // libère la mémoire occupée par le plateau

	return 0;
}
