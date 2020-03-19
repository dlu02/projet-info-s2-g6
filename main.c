//  main.c
//  Created by Decouty Rémi on 15/03/2020.

#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	plateau p = new_plateau();  // initalise le plateau ainsi que les différentes piles de cartes

	while (win(p) == -1) {	// tant qu'il n'y a pas de gagnant 
		
		print_new_tour();	// message de nouveau tour
		new_tour(p);	// mise à jour du compteur de tours, etc.

		for (int i=0;i<2;i++) {		// 2 phases par tour

			print_new_phase(p.debutEnsiie); // message de nouvelle phase (une par ENSIIE)
			int nbPioche = nb_cartes(p);

			for (int j=0;j<nbPioche;j++)
				pioche(p);	// chaque ENSIIE pioche nbPioche cartes par phase

			print_plateau(p); 	// affiche l'état du jeu

			if (strcmp(ask_carte_ou_fin(p),"fin")) 	   	// si l'on saisit "fin"
				continue;
			
			else if (strcmp(ask_carte_ou_fin(p),"jouer")) 		// si l'on saisit "jouer"
				carte_jouer(p);				// on joue la carte sur le plateau 
			
		}
		carte_fin(p);	// fin du tour
	}

	print_win_player(p);	// affiche le gagnant de la partie 
	free_plateau (p); // libère la mémoire occupée par le plateau

	return 0;
}