//
//  structure.h
//  
//
//  Created by Loirs Romain on 22/03/2020.
//

#ifndef carte_file_h
#define carte_file_h

#include <stdio.h>
#include "carte.h"

//la structure du deck
// utilisation des liste chainées (utilisation FIFO et FILO)

typedef struct node *deck;
struct node{
  carte carte;
  deck next;
};

// les fonctions

/**
\brief: création d'un deck vide
\param: aucun
\return: un deck vide (NULL)
*/

deck deck_create();

/**
\brief: détermine si un deck vide
\param: un deck
\return: 0 si le deck contient au moins une carte et 1 si le deck ne contient aucune carte
*/

int deck_isEmpty(deck);

/**
\brief: permet de libérere l'espace mémoire alouer à un deck
\param: un deck
\return:  nothing
*/

void deck_free(deck);

/**
\brief: permet d'ajouter une carte au dessus de la liste
\param: une carte et un deck (vide ou contenant deja des cartes)
\return:  nothing
*/
void deck_add_last(carte,deck*);

/**
\brief: utilisation FIFO: retire le premier élément placé dans le deck
\param: un deck contenant une carte (vérifié si le deck est non vide avant de l'utiliser)
\return:  la carte retiré"
*/
carte deck_remove_head(deck*);

/**
\brief: utilisation FILO: retire le dernier élément placé dans le deck
\param: un deck contenant une carte (vérifié si le deck est non vide avant de l'utiliser)
\return:  la carte retiirée
*/
carte deck_remove_queue(deck*);

/**
\brief: utilisation lambda: retire le i-eme element du deck (en partant du premier element ajouté a la pile)
\param: un deck contenant une carte (vérifié si le deck est non vide avant de l'utiliser)
\return:  la carte supprimé
*/

carte deck_remove_indice(deck*, int);

/**
\brief: supprimer une carte précise du deck
\param: un deck contenant une carte (vérifié si le deck est non vide avant de l'utiliser) et le nom de la carte
\return:  la carte supprimé
*/

carte deck_remove_carte(deck*, Nom);

/**
\brief: imprime à l'écran un deck
\param: un deck.
\return:  Si le decke st vide affiche "the deck is empty" sinon affiche de leck
 
*/
void deck_print(deck);

#endif /* carte_file_h */
