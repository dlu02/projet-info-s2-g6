//
//  carte.h
//  
//
//  Created by Loirs Romain on 06/03/2020.
//

#ifndef CARTE_H
#define CARTE_H

#include "plateau.h"

typedef struct plateau p;

typedef struct {
	int numero;
	char *nom;
	int cout;
	char *effet; 
} carte;


typedef carte *carte_pile;

/**
 \brief: calculer combien de cartes Elève une ENSIIE recevra au début de sa phase. (utile pour la carte personnels avec effet DR)
 \param: historique des cartes joué au tour précédent. Bonne idée?
 \return: le nombre de carte à piocher par la personne.
 */

int pioche_eleve(carte_pile);

/**
 \brief: ajouter une carte Élève de type FISE ou FISA au plateau de jeu d’une ENSIIE.
 \param: une carte de type FISE ou FISA UNIQUEMENT et un plateau de jeu p
 \return: nothing
*/

void carte_ajouter(carte,p);

/**
 \Brief: calculer le nombre de PE disponibles par ENSIIE après avoir posé sa ou ses nouvelles cartes Élèves.
 \param: le plateau 
 \return: un entier, le nombre de point PE du joueur
 */

int carte_pointPE(p);

/**
 \brief: réalise l'action décrite par une carte personnel
 \param: une carte personnel
 \return: nothing
 */

void carte_personnel(carte);

/**
 \Brief: une fonction pour permettre à une ENSIIE de jouer une carte de sa main
 \param: un jeu de carte (structure à préciser par la suite)
 \return: nothing
 */

void carte_jouer(p);

/**
 \Brief: signifier au plateau que le tour est terminé. Elle permettra, entre autres, de faire le calcul des DD gagnés par chaque ENSIIE à la fin du tour.
 \param: un plateau p
 \return: nothing
 */
 
void carte_fin(p);

/**
 \Brief: afficher une carte en fonction de son type
 \param: une carte
 \return: nothing
 */

void carte_print_carte(carte);

/**
 \Brief: afficher une pile de carte
 \param: une pile de carte
 \return: nothing
 */

void carte_print_pile(carte_pile);


#endif 
