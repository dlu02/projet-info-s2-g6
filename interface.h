//
//  plateau.h
//  
//
//  Created by Lu Damien on 14/03/2020.
//  Modified : 10/04/2020 17:58 (v2)
//

#ifndef INTERFACE_H
#define INTERFACE_H

#include "plateau.h"

/**
 \brief: afficher un message de début de nouveau tour
 \param: 
 \return: message de début de nouveau tour
*/
void print_new_tour(plateau p);

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
 \brief: demande au joueur A de choisir entre une carte de sa main ou finir la phase en cours
 \param: un plateau 
 \return: son choix (en chaine de caractères)
*/
char *ask_carte_ou_finA(plateau);

/**
 \brief: demande au joueur B de choisir entre une carte de sa main ou finir la phase en cours
 \param: un plateau 
 \return: son choix (en chaine de caractères)
*/
char *ask_carte_ou_finB(plateau);

/**
 \brief: affiche le gagnant du jeu ou l'égalité
 \param: un plateau 
 \return: rien
*/
void print_win_player(plateau);

/**
 * brief : demande au joueur qui recoit une nouvelle carte eleve s'il souhaite ajouter une carte fise ou fisa
 * param : rien
 * return : fise ou fisa
 */
Nom ajout_fise_fisa();

/**
 * brief : compte le nombre de points énergie du joueur A
 * param : un plateau
 * return : le nombre de points énergie du joueur A
 */
int count_PE_A(plateau);

/**
 * brief : compte le nombre de points énergie du joueur B
 * param : un plateau
 * return : le nombre de points énergie du joueur B
 */
int count_PE_B(plateau);
#endif
