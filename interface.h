#ifndef INTERFACE_H
#define INTERFACE_H

#include "plateau.h"
#include "carte.h"

/**
 \brief: afficher un message de début de nouveau tour
 \param: 
 \return: message de début de nouveau tour
*/
void print_new_tour()

/**
 \brief: afficher un message de début de nouveau tour
 \param: 
 \return: message de début de nouveau tour
*/
void new_phase()

/**
 \brief: afficher le plateau p
 \param: un plateau p
 \return: affiche le plateau p
*/
void print_plateau(plateau p);

/**
 \brief: demande au joueur de choisir entre chosiir une carte de sa main et finir la phase
 \param: un plateau p
 \return: son choix (en chaine de caractères)
*/
char *ask_carte_ou_fin(plateau p)

/**
 \brief: affiche le gagnant du jeu ou l'égalité
 \param: un plateau p
 \return: rien
*/
void win_player(plateau p)

#endif