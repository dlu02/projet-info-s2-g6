//
//  carte.h
//  
//
//  Created by Loirs Romain on 06/03/2020.
//

#ifndef CARTE_H
#define CARTE_H

// Les structures et les types énumérés //

typedef enum Nom Nom;
enum Nom {
    //Nom des cartes élèves (2)
    Fise,Fisa,
    //Nom des cartes Personnels (20)
    Lim, Szafranski, Faye, Mouilleron, Dumbrava, Forest, Brunel, Bourard, Watel, Y, Goilard, Jeannas, Merabet, Ligozat, Dubois, Lejeune, Mathias, Salhab, Sagna, Prevel,
    //Nom des cartes Actions (11)
    Cours_developpemnt_durable, Recrutement, Rentrée_FISE, Rentrée_FISA, Energie_verte, Diplomation, Decharge, Recyclage, Zero_papier, Repas_vegetarien, Fermeture_annuelle
};

typedef enum Type Type;
enum Type {Eleve,Personnel,Action};

typedef struct carte carte;
struct carte{
    Nom nom;
    Type type;
    //carte Eleve
    int pt_dev;
    int pt_dur;
    int pt_nrj;
    // carte personnel et action
    int cout;
};

#include "plateau.h"

//les fonctions//

/**
 \brief: création d'une nouvelle carte
 \param: un entier qui corre
 \return: le nombre de carte à piocher par la personne.
*/

carte carte_new(Nom);

/**
 \brief: calculer combien de cartes Elève une ENSIIE recevra au début de sa phase. (utile pour la carte personnels avec effet DR)
 \param: historique des cartes joué au tour précédent. Bonne idée?
 \return: le nombre de carte à piocher par la personne.
 */

int pioche_eleve(plateau);

/**
 \brief: ajouter une carte Élève de type FISE ou FISA au plateau de jeu d’une ENSIIE.
 \param: une carte de type FISE ou FISA UNIQUEMENT et un plateau de jeu p
 \return: nothing
*/

void carte_ajouter(carte,plateau);

/**
 \Brief: calculer le nombre de PE disponibles par ENSIIE après avoir posé sa ou ses nouvelles cartes Élèves.
 \param: le plateau 
 \return: un entier, le nombre de point PE du joueur
 */

int carte_pointPE(plateau);

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

void carte_jouer(plateau);

/**
 \Brief: signifier au plateau que le tour est terminé. Elle permettra, entre autres, de faire le calcul des DD gagnés par chaque ENSIIE à la fin du tour.
 \param: un plateau p
 \return: nothing
 */
 
void carte_fin(plateau);

/**
 \Brief: afficher une carte en fonction de son type
 \param: une carte
 \return: nothing
 */

void carte_print(carte);

/**
 \Brief: afficher une pile de carte
 \param: une pile de carte
 \return: nothing
 */


#endif 
