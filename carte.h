//
//  carte.h
//  
//
//  Created by Loirs Romain on 06/03/2020.
//

#ifndef CARTE_H
#define CARTE_H

#include "structure.h"

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

/**
 \brief:  test pour reconnaitre une carte
 \param: une  carte et un nom
 \return: retrun 1 si c'est la bonne carte et 0 sinon. Si ce sont deux cartes Fise ou Fisa différentes, la fonctions renvoie tout de même 1.
*/

int carte_equal(carte,Nom);
    






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
 \param: le plateau de jeu
 \return: le nombre de carte à piocher par la personne.
 */

int pioche_eleve(plateau, char);

/**
 \brief: ajouter une carte Élève de type FISE ou FISA au plateau de jeu d’une ENSIIE.
 \param: une carte de type FISE ou FISA UNIQUEMENT et un plateau de jeu p, un char A  ou B pour identifier l'ENSIIE
 \return: ajoute la carte
*/

void carte_ajouter(Nom, plateau*, char);

/**
 \Brief: calculer le nombre de PE disponibles par ENSIIE après avoir posé sa ou ses nouvelles cartes Élèves.
 \param: le plateau 
 \return: un entier, le nombre de point PE du joueur
 */

int carte_pointPE(plateau, char);

/**
 \brief: réalise l'action décrite par une carte personnel
 \param: une carte personnel, le plateau de jeu, l'id du joueur
 \return: nothing
 */

void carte_personnel(carte,plateau*,char );

/**
 \Brief: une fonction pour permettre à une ENSIIE de jouer une carte de sa main
 \param: un plateau et une carte appartenant a la main du joueur
 \return: nothing
 */

void carte_jouer(carte, plateau, char);

/**
 \Brief: signifier au plateau que le tour est terminé. Elle permettra, entre autres, de faire le calcul des DD gagnés par chaque ENSIIE à la fin du tour.
 \param: un plateau p
 \return: les point DD
 */
 
void carte_fin(plateau);



#endif 
