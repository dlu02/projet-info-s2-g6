//
//  carte.h
//  
//
//  Created by Loirs Romain on 06/03/2020.
//

#ifndef carte_h
#define carte_h

#include <stdio.h>

typedef struct carte * carte;

/**
 \brief: calculer combien de cartes Elève une ENSIIE recevra au début de sa phase.
 \param
 
 */

/**
 \brief: ajouter une carte Élève de type FISE ou FISA au plateau de jeu d’une ENSIIE.
 \param: un une carte de type FISE ou FISA UNIQUEMENT et un plateau de jeu
 \return: nothing
*/

void carte_ajouter(carte carte,plateau plateau);

/**
 \Brief: calculer le nombre de PE disponibles par une ENSIIE après avoir posé sa ou ses nouvelles cartes Élèves.
 \param: plateau
 \return: un entier, le nombre de point PE du joueur
 */

int carte_pointPE (plateau plateau);

/**
 \Brief: une fonction pour permettre à une ENSIIE de jouer une carte de sa main
 \param: un jeu de carte (structure à préciser par la suite)
 \return: la carte sélectinné par le joueur
 */

int carte_jouer (/*cf later*/ pile);

/* signifier au plateau que le tour est terminé. Elle permettra, entre autres, de faire le calcul des DD gagnés par chaque ENSIIE à la fin du tour.*/

#endif /* carte_h */
