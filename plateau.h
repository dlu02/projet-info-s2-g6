//
//  carte.h
//  
//
//  Created by Lecomte Florian on 14/03/2020.
//

#ifndef PLATEAU_H
#define PLATEAU_H

#include carte.h

typedef struct carte 
typedef struct plateau {
    carte* mainA;
    carte* mainB;
    carte* defausseA;
    carte* defausseB;
    carte* deckA;
    carte* deckB;
    carte* sideA;
    carte* sideB;
    int tour;
} plateau;

/**
 \brief: créer un nouveau plateau vide
 \param: vide
 \return: un plateau vide
 */

plateau new_plateau();

/**
 \brief: libère les cases mémoires d'un plateau
 \param: le plateau à libérer
 \return: vide
 */

void free_plateau(plateau);

/**
 \brief: incrémente le compteur de tours, gére les cartes FISA et met à jour les espaces disponibles pour les cartes Personnels
 \param: le plateau en jeu
 \return: vide
 */

void new_tour(plateau);

/**
 \brief: calcule le nombre de carte à piocher pour une ENSIIE (A ou B)
 \param: le plateau en jeu, un char pour savoir si l'on parle de l'ENSIIE A ou B
 \return: le nombre de cartes à piocher pour une ENSIIE (A ou B)
 */

int nb_cartes(plateau, char);

/**
 \brief: permet à une ENSIIE de piocher
 \param: le plateau en jeu, un char pour signifier si c'est l'ENSIIE A ou B qui pioche
 \return: vide
 */

void pioche (plateau, char);

/**
 \brief: renvoie un booléen (entier) indiquant si la partie est finie ou non, et si oui par laquelle des deux ENSIIE
 \param: le plateau en jeu
 \return: un entier, -1 si non, 0 si égalité, 1 si ENSIIE A gagne, 2 si ENSIIE B gagne
 */

int win(plateau);



#endif



