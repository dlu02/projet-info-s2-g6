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

    pioche(&p,'A');
    pioche(&p,'A');
    pioche(&p,'B');
    pioche(&p,'B');

	while (win(p) == -1) {	// tant qu'il n'y a pas de gagnant 
		
		new_tour(&p);	// mise à jour du compteur de tours, etc.
		print_new_tour(p);	// message de nouveau tour

		for (int i=0;i<2;i++) {		// 2 phases par tour

			print_new_phase(p.debutEnsiie); // message de nouvelle phase (une par ENSIIE)
			pioche(&p,p.debutEnsiie);	// chaque ENSIIE pioche nbPioche cartes par phase
			

			print_plateau(p); 	// affiche l'état du jeu
            
            /*
            // j'ai un seg fault à cette endroit
            int numero_carte= ask_carte_ou_fin(p,p.debutEnsiie);
            
            while (numero_carte!=-1){ //une Ensiie peut jouer autant de carte de son deck qu'elle le désire.
                
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
                    // controle de la validité de la saisie dans ask_carte_ou_fin donc pas de else utile ici.
                }
                
                else{
                }
            }
             */


			if (i == 0) {
				if (p.debutEnsiie == 'A')
					p.debutEnsiie = 'B';
				else
					p.debutEnsiie = 'A';
			}

		}
		//carte_fin(&p);	// fin du tour (compter les points)
	}

	print_win_player(p);	// affiche le gagnant de la partie 
	free_plateau (p); // libère la mémoire occupée par le plateau

	return 0;
}
