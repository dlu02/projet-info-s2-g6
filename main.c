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
		updateEnergy(&p);	// mis à jour du compteur d'ENSIIE

		for (int i=0;i<2;i++) {		// 2 phases par tour

			print_new_phase(p.debutEnsiie); // message de nouvelle phase (une par ENSIIE)
			pioche(&p,p.debutEnsiie);	// chaque ENSIIE pioche nbPioche cartes par phase

			print_plateau(p); 	// affiche l'état du jeu

            //jouer une carte FISE ou FISA au choix
            Nom eleve = ajout_fise_fisa();
            carte_ajouter(eleve, &p, p.debutEnsiie);
            updateEnergy(&p);

            //jouer les cartes de la main
            int numero_carte = ask_carte_ou_fin(p,p.debutEnsiie);

            while (numero_carte != -1) { 	// une Ensiie peut jouer autant de cartes dans sa main

                if (p.debutEnsiie =='A'){
                    carte c = deck_remove_carte(&(p.mainA), numero_carte);
                    carte_jouer(c,&p,p.debutEnsiie);
                }

                else {
                    carte c = deck_remove_carte(&(p.mainB), numero_carte);
                    carte_jouer(c,&p,p.debutEnsiie);
                }

             // initialise à 0 la valeur de durabilité ou le nombre de points DD de la carte, si ceux-ci sont négatifs
                numero_carte = ask_carte_ou_fin(p,p.debutEnsiie);
            }

			if (i == 0) {
				if (p.debutEnsiie == 'A')
					p.debutEnsiie = 'B';
				else
					p.debutEnsiie = 'A';
			}

		}

		carte_fin(&p);
		print_points_DD(p);	// affiche les points DD de chaque ENSIIE à la fin de chaque tour

	}

	print_win_player(p);	// affiche le gagnant de la partie
	free_plateau (p); // libère la mémoire occupée par le plateau

	return 0;
}
