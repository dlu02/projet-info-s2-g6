//
//  plateau.h
//  
//
//  Created by Lu Damien on 14/03/2020.
//

#ifndef INTERFACE_H
#define INTERFACE_H

#include "plateau.h"

/**
 \brief: afficher un message de début de nouveau tour
 \param: 
 \return: message de début de nouveau tour
*/
void print_new_tour();

/**
 \brief: afficher un message de début de nouvelle phase en fonction du nom de l'ENSIIE
 \param: 
 \return: message de début de nouveau tour
*/
void print_new_phase(char);

/**
 \brief: afficher le plateau p
 \param: un plateau 
 \return: affiche le plateau p
*/
void print_plateau(plateau);

/**
 \brief: demande au joueur de choisir entre une carte de sa main ou finir la phase en cours
 \param: un plateau 
 \return: son choix (en chaine de caractères)
*/
char *ask_carte_ou_fin(plateau);

/**
 \brief: affiche le gagnant du jeu ou l'égalité
 \param: un plateau 
 \return: rien
*/
void print_win_player(plateau);

#endif