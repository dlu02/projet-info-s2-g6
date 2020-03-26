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
    long code;
};

#include "plateau.h"




//les fonctions permettant d'accéder aux différentes informations d'une carte//

/**
 \brief:  obtenir le nom de la carte
 \param: une carte
 \return: le nom de la carte
*/

Nom getNom(carte);

/**
 \brief:  retourne le type d'une carte
 \param: une carte
 \return: le type de la carte
*/

Type getType(carte);

/**
 \brief:  obtenir les point developement durable à partir du code d'une carte.
 \param: une carte de type élève.
 \return: les points developpement durable d'une carte. -1 en cas de pb
*/

long pt_DD(carte);

/**
 \brief:  obtenir les point durabilité  à partir du code d'une carte.
 \param: une carte de type élève.
 \return: les points durablilité d'une carte. -1 en cas de pb
*/

long pt_Dur(carte);

/**
 \brief:  obtenir les point énergie à partir du code d'une carte.
 \param: une carte de type élève.
 \return: les points énergie d'une carte. -1 en cas de pb
*/

long pt_nrj(carte);

/**
 \brief:  obtenir le cout à partir du code d'une carte
 \param: une carte de type personnel ou action
 \return: les points developpement durable. -1 en cas de pb
*/

long cout(carte);






//fonctions permettant de modifier une carte//

/**
 \brief: modifie(ajouter ou soustraire) en place les points développement durables d'une carte.
 \param: une carte de type élève et les points à soustraire ou additionner
 \return: nothing. si le nombre de point Développement durable est négatif, remet à 0.
*/

void pt_DD_change(carte*,long);

/**
 \brief: modifie(ajouter ou soustraire) en place les points durabilité d'une carte.
 \param: une carte de type élève et les points à soustraire ou additionner
 \return: nothing. si le nombre de point durabilité est négatif, remet à 0.
*/

void pt_Dur_change(carte*,long);

/**
 \brief:  modifie(ajouter ou soustraire) en place les énérgie d'une carte.
 \param: une carte de type élève et les points à soustraire ou additionner
 \return: nothing. si le nombre de point énérgie est négatif, remet à 0.
*/

void pt_nrj_change(carte*,long);






// fonctions utiles en particulier pour deck //

/**
 \brief:  créer une nouvelle carte
 \param: le nom de la carte (soit le nom déterminié dans le type énuméré, soit un entier compirs entre 0 et 32 comrpis)
 \return: la carte désirée
*/

carte carte_new(Nom);

/**
\Brief: afficher une carte en fonction de son type
\param: une carte
\return: nothing
*/

void carte_print(carte);





// fonctions utiles pour coder le jeu//


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



#endif 
