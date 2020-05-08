//
//  interface.h
//  
//
//  Created by Lu Damien on 14/03/2020.
//  Modified : 03/05/2020 17:00 (v9)
//

#ifndef INTERFACE_H
#define INTERFACE_H

#include "plateau.h"

/**
 \brief: afficher un message de début de nouveau tour
 \param: un plateau p
 \return: message de début de nouveau tour
*/
void print_new_tour(plateau p);

/**
 \brief: afficher un message de début de nouvelle phase en fonction du nom de l'ENSIIE
 \param:un char représentant l'ensiie
 \return: message de début de nouveau tour
*/
void print_new_phase(char);

/**
 \brief: afficher les points de développement durable de chaque ENSIIE à la fin de chaque tour
 \param: un plateau
 \return: message de début de nouveau tour
*/
void print_points_DD(plateau);

/**
 \brief: afficher le plateau p
 \param: un plateau 
 \return: affiche le plateau p
*/
void print_plateau(plateau);

/**
 \brief: demande au joueur char de choisir entre une carte de sa main ou finir la phase en cours
 \param: un plateau et le joueur concerné
 \return: le nom (entier) de la carte de son choix, -1 si la phase est finie
*/
int ask_carte_ou_fin(plateau,char);

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
#endif
