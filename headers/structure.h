//
//  structure.h
//  
//
//  Created by Loirs Romain on 22/03/2020.
//

#ifndef carte_file_h
#define carte_file_h

// Les structures et les types énumérés //

typedef enum Nom Nom;
enum Nom {
    //Nom des cartes élèves (2)
    Fise,Fisa,
    //Nom des cartes Personnels (20)
    Lim, Szafranski, Faye, Mouilleron, Dumbrava, Forest, Brunel, Bourard, Watel, Y, Goilard, Jeannas, Merabet, Ligozat, Dubois, Lejeune, Mathias, Salhab, Sagna, Prevel,
    //Nom des cartes Actions (11)
    Cours_developpemnt_durable, Recrutement, Rentree_FISE, Rentree_FISA, Energie_verte, Diplomation, Decharge, Recyclage, Zero_papier, Repas_vegetarien, Fermeture_annuelle
};

typedef enum Type Type;
enum Type {Eleve,Personnel,Action};

typedef struct carte carte;
struct carte{
    Nom nom;
    Type type;
    long code;
};

//la structure du deck
//utilisation des liste chainées

typedef struct node *deck;
struct node{
  carte carte;
  deck next;
};

//structure du plateau

typedef struct plateau {
    deck mainA, mainB;
    deck sideA, sideB;
    int nbcarteA, nbcarteB;
    deck defausseA, defausseB;
    deck deckA, deckB;
    deck pileFiseA, pileFiseB;
    deck pileFisaA, pileFisaB;
    int maxcarte; //maximum de cartes Personnel que les ENSIIE peuvent jouer
    int ddA, ddB; // points de développement durable pour chaque ENSIIE
    int nrjA, nrjB;
    // permet de modéliser les effets;
    int ADD_effetA, ADD_effetB;
    int RDD_effetA, RDD_effetB;
    int piocheA, piocheB;
    int EA, EB;  // effet E (on pioche x cartes etudiants supplémentaires au prochain tour)
    int RVA,RVB; // gerer efffet repas vegetarien
    int ZDA,ZDB; //gerer zero dechet
    int tour;    // indice de tour
    char debutEnsiie;    /* lettre 'A' ou 'B' calculée de facon aléatoire qui détermine
                          la première ENSIIE à débuter */
} plateau;



#include "carte.h"
#include <stdio.h>


/* construction du deck et destruction*/

/**
\brief: création d'un deck vide
\param: aucun
\return: un deck vide (NULL)
*/
deck deck_create();

/**
\brief: permet de libérere l'espace mémoire alouer à un deck
\param: un deck
\return:  nothing
*/
void deck_free(deck);


/*addition d'element*/

/**
\brief: permet d'ajouter une carte au dessus de la liste
\param: une carte et un deck (vide ou contenant deja des cartes)
\return:  nothing
*/
void deck_add_last(carte,deck*);

/**
\brief: permet de prendre toutes les cartes d'un deck et de les rajouter à un autre. 
\param: deux decks, le premier recevra toutes les cartes du second et le second sera vide
\return: nothing
*/
void deck_concatenate(deck*,deck*);


/*fonction de controle*/

/**
\brief: détermine si un deck vide
\param: un deck
\return: 1 si le deck contient au moins une carte et 0 si le deck ne contient aucune carte
*/
int deck_isEmpty(deck);

/**
\brief: détermine si une carte appartient au deck
\param: un deck et le nom de la carte (numero ou nom)
\return: 1 si le deck contientla carte et 0 sinon
*/
int deck_carteIn(deck, Nom);

/**
\brief: détermine la longueur du deck
\param: un deck
\return: la longueur du deck
*/
int deck_length(deck);

/**
\brief: imprime à l'écran un deck
\param: un deck.
\return:  Si le decke st vide affiche "the deck is empty" sinon affiche de deck
*/
void deck_print(deck);


/*retirer les elements*/

/**
\brief: utilisation FIFO: retire le premier élément placé dans le deck
\param: un deck contenant une carte (vérifié si le deck est non vide avant de l'utiliser)
\return:  la carte retirée
*/
carte deck_remove_head(deck*);

/**
\brief: utilisation FILO: retire le dernier élément placé dans le deck
\param: un deck contenant une carte (vérifié si le deck est non vide avant de l'utiliser)
\return:  la carte retirée
*/
carte deck_remove_queue(deck*);

/**
\brief: supprimer une carte précise du deck
\param: un deck contenant une carte (vérifié si le deck est non vide avant de l'utiliser) et le nom de la carte
\return:  la carte supprimé
*/
carte deck_remove_carte(deck*, Nom);

/**
\brief: utilisation lambda: retire le i-eme element du deck (en partant du premier element ajouté a la pile)
\param: un deck contenant une carte (vérifié si le deck est non vide avant de l'utiliser)
\return:  la carte supprimé
*/
carte deck_remove_indice(deck*, int);



/*modifier le deck*/

/**
\brief: ajouter ou retirer des points a toutes les cartes Fise ou Fisa du deck
\param: la pile a modifier, le nombre de points à ajouter ou retrancher, un numero  pour identifier les points à modifier (1- point DD, 2-point Dur, 3-point energie)
\return:  nothing
*/
void deck_addPt(deck* ,long , int);

/**
\brief: mélanger un deck
\param: un deck
\return: nothing
*/
void melanger_deck (deck*);


/*parcours d'un deck*/

/**
\brief: parcours un deck et trouve le total des points énergies
\param: un deck contenant uniquement des cartes FISE ou FISA
\return: la somme des points énergies des cartes d'un deck
*/
int deck_parcours_energie(deck,int);

/**
\brief: parcours un deck et trouve le total des points durabilité
\param: un deck contenant uniquement des cartes FISE ou FISA
\return: la somme des points durabilité des cartes d'un deck
*/
int deck_parcours_durabilite(deck);

/**
\brief: parcours un deck et trouve le total des points dévellopement durale
\param: un deck contenant uniquement des cartes FISE ou FISA
\return: la somme des points devellepement durable des cartes d'un deck
*/
int deck_parcours_devellopement(deck);




#endif /* carte_file_h */
