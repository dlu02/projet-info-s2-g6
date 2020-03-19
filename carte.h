//
//  carte.h
//  
//
//  Created by Loirs Romain on 06/03/2020.
//

#ifndef carte_h
#define carte_h

#include <stdio.h>
#include "plateau.h"

typedef struct carte * carte;

typedef struct carte_pile * carte_pile;

/**
 \brief: calculer combien de cartes Elève une ENSIIE recevra au début de sa phase. (utile pour la carte personnels avec effet DR)
 \param: historique des cartes joué au tour précédent. Bonne idée?
 \return: le nombre de carte à piocher par la personne.
 */

int carte_piocher(carte_pile carte_pile);

/**
 \brief: ajouter une carte Élève de type FISE ou FISA au plateau de jeu d’une ENSIIE.
 \param: une carte de type FISE ou FISA UNIQUEMENT et un plateau de jeu
 \return: nothing
*/

void carte_ajouter(carte carte, plateau plateau);

/**
 \Brief: calculer le nombre de PE disponibles par une ENSIIE après avoir posé sa ou ses nouvelles cartes Élèves.
 \param: plateau
 \return: un entier, le nombre de point PE du joueur
 */

int carte_pointPE (plateau plateau);

/**
 \brief: réalise l'action décrite par une carte personnel
 \param: une carte personnel
 \return: nothing
 */

void carte_personnel( carte carte);

/**
 \Brief: une fonction pour permettre à une ENSIIE de jouer une carte de sa main
 \param: un jeu de carte (structure à préciser par la suite)
 \return: la carte sélectinné par le joueur
 */

carte carte_jouer (/*cf later*/ carte_pile pile);

/**
 \Brief: signifier au plateau que le tour est terminé. Elle permettra, entre autres, de faire le calcul des DD gagnés par chaque ENSIIE à la fin du tour.
 \param: un plateau
 \return: les points DD gagné par un joueur
 */
 
int carte_fin(plateau plateau);

/**
 \Brief: afficher une carte en fonction de son type
 \param: une carte
 \return: nothing
 */

void carte_print_carte(carte carte);

/**
 \Brief: afficher une pile de carte
 \param: une pile de carte
 \return: nothing
 */

void carte_print_pile(carte_pile carte_pile);


#endif /* carte_h */
