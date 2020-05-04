//
//  carte.c
//  
//
//  Created by Loirs Romain on 06/03/2020.

#include "carte.h"
#include "structure.h"
#include <stdio.h>


//les fonctions permettant d'accéder aux différentes informations d'une carte//

Nom getNom(carte c){
    return c.nom;
}

Type getType(carte c){
    return c.type;
}

long pt_DD(carte c){
    if (c.code>999999999) return -1;
    else {
        long aux1= c.code%1000000;
        return c.code%1000;
    }
}

long pt_Dur(carte c){
    if (c.code>999999999) return -1;
    else{
        long aux= c.code%1000000;
        return aux/1000;
    }
}

long pt_nrj(carte c){
    if (c.code>999999999) return -1;
    else {
        return c.code/1000000;
    }
}

long cout(carte c){
    if (c.code>999999999) return -1;
    else return c.code;
}

int carte_equal(carte c1,Nom nom){
    return c1.nom==nom;
}

//fonctions permettant de modifier une carte//

void pt_DD_change(carte *c,long pt){
    if (pt_DD(*c)+pt<0) c->code=pt_nrj(*c)*1000000+pt_Dur(*c)*1000;
    else c->code=c->code+pt;
}

void pt_Dur_change(carte *c,long pt){
    if(pt_Dur(*c)+pt<0) c->code=pt_nrj(*c)*1000000+pt_DD(*c);
    else c->code=c->code+(pt*1000);
}

void pt_nrj_change(carte *c,long pt){
    if (pt_nrj(*c)+pt<0) c->code=pt_Dur(*c)*1000+pt_DD(*c);
    else c->code=c->code+(pt*1000000);
}

// fonctions utiles pour deck//

/**
\brief:  trouver le code d'une carte
\param: le nom d'une carte
\return: le code de la carte correspondant au nom mis en paramétre
*/
long aux_code(Nom nom){
    switch(nom){
        case Fise: return 1001001; break;
        case Fisa: return 2001001; break;
        case Lim: return 3; break;
        case Szafranski:return 3; break;
        case Faye: return 3; break;
        case Mouilleron: return 3;break;
        case Dumbrava: return 3;break;
        case Forest: return 3;break;
        case Brunel:return 3; break;
        case Bourard:return 5 ;break;
        case Watel: return 5;break;
        case Y: return 5;break;
        case Goilard:return 5 ;break;
        case Jeannas: return 5;break;
        case Merabet: return 7;break;
        case Ligozat: return 8 ;break;
        case Dubois:return 8 ;break;
        case Lejeune: return 10;break;
        case Mathias: return 10 ;break;
        case Salhab: return 15 ;break;
        case Sagna: return 15 ;break;
        case Prevel: return 2;break;
        case Cours_developpemnt_durable: return 2;break;
        case Recrutement: return 2;break;
        case Rentree_FISE:return 3;break;
        case Rentree_FISA:return 3;break;
        case Energie_verte: return 4;break;
        case Diplomation: return 5;break;
        case Decharge: return 5;break;
        case Recyclage: return 10;break;
        case Zero_papier: return 10;break;
        case Repas_vegetarien: return 10;break;
        case Fermeture_annuelle: return 10;break;
    }
}

carte carte_new(Nom carte_nom){
    carte res;
    res.nom= carte_nom;
    if (carte_nom<=1) {res.type=0;}
    else if (carte_nom<=21) {res.type=1;}
    else {res.type=2;}
    res.code=aux_code(carte_nom);
    return res;
}

/**
\brief: affiche le nom d'une carte
\param: une carte
\return: nothing
*/
void aux_NomPrint(carte c){
    switch(getNom(c)){
        case Fise: printf("fise"); break;
        case Fisa: printf("fisa"); break;
        case Lim: printf("lim"); break;
        case Szafranski:printf("Szafranski"); break;
        case Faye: printf("Faye"); break;
        case Mouilleron: printf("Mouilleron");break;
        case Dumbrava: printf("Dumbrava");break;
        case Forest: printf("Forest");break;
        case Brunel:printf("Brunel"); break;
        case Bourard:printf("Bourard") ;break;
        case Watel: printf("Watel");break;
        case Y: printf("Y");break;
        case Goilard:printf("Goilard") ;break;
        case Jeannas: printf("Jeannas");break;
        case Merabet: printf("Merabet");break;
        case Ligozat: printf("Ligozat") ;break;
        case Dubois:printf("Dubois") ;break;
        case Lejeune: printf("Lejeune");break;
        case Mathias: printf("Mathias") ;break;
        case Salhab: printf("Salhab") ;break;
        case Sagna: printf("Sagna") ;break;
        case Prevel: printf("Prevel");break;
        case Cours_developpemnt_durable: printf("cours_developpement durable");break;
        case Recrutement: printf("Recrutement");break;
        case Rentree_FISE: printf("Rentrée_FISE");break;
        case Rentree_FISA: printf("Rentrée_FISA");break;
        case Energie_verte: printf("Energie_verte");break;
        case Diplomation: printf("Diplomation");break;
        case Decharge: printf("decharge");break;
        case Recyclage: printf("Recyclage");break;
        case Zero_papier: printf("Zero_papier");break;
        case Repas_vegetarien: printf("Repas_vegetarien");break;
        case Fermeture_annuelle: printf("Fermeture_annuelle");break;
    }
}

void carte_print(carte c){
    printf("\n");
    printf("* "); aux_NomPrint(c); printf(" *\n");
    switch(c.type){
        case Eleve:
            printf("- type: eleve\n");
            printf("- point_déveleppement_durable= %ld \n",pt_DD(c));
            printf("- point_durabilite= %ld \n",pt_Dur(c));
            printf("- point_energie= %ld\n",pt_nrj(c));
            break;
        case Personnel:
            printf("- type: personnel\n");
            printf("- cout: %ld \n",cout(c));
            break;
        case Action:
            printf("- type: action\n");
            printf("- cout: %ld \n",cout(c));
            break;
    }
    printf("\n");
}



//les fonction pour coder le jeu//

/* les fonctions annexes. Elles sont utiles pour d'autres fonctions définis plus loin  */


/**
\brief: les fonctions suivantes réalise l'effet décrites dans le tableau
\param: un plateau, le nombre de points, l'id identifiant l'ENSIIE
\return: nothing
*/

//ajoute x points de dévellopement à chacune de vos cartes FISE
void AE1(plateau *p,int x, char id){
    if (id=='A'){
        deck_addPt(&(p->pileFiseA),x,1);
    }
    else{
        deck_addPt(&(p->pileFiseB),x,1);
    }
}

//Ajouter X points de Durabilité à chacune de vos cartes FISE
void AE2(plateau *p,int x, char id){
    if (id=='A'){
        deck_addPt(&(p->pileFiseA),x,2);
    }
    else{
        deck_addPt(&(p->pileFiseB),x,2);
    }
}

//Ajouter X points de dévellopement à chacune de vos cartes FISA
void AA1(plateau *p,int x, char id){
    if (id=='A'){
        deck_addPt(&(p->pileFisaA),x,1);
    }
    else{
        deck_addPt(&(p->pileFisaB),x,1);
    }
}

//Ajouter X points de Durabilité à chacune de vos cartes FISA
void AA2(plateau *p,int x,char id){
    if (id=='A'){
        deck_addPt(&(p->pileFisaA),x,2);
    }
    else{
        deck_addPt(&(p->pileFisaB),x,2);
    }
}

//Retirer X points de Durabilité à chacune des cartes FISE de l’adversaire
void RE1(plateau *p,int x,char id){
    if (id=='A'){
        deck_addPt(&(p->pileFiseB),-x,1);
    }
    else{
        deck_addPt(&(p->pileFiseA),-x,1);
    }
}

//Retirer X points de Durabilité à chacune des cartes FISE de l’adversaire
void RE2(plateau *p,int x,char id ){
    if (id=='A'){
        deck_addPt(&(p->pileFiseB),-x,2);
    }
    else{
        deck_addPt(&(p->pileFiseA),-x,2);
    }
}

//Retirer X points de Durabilité à chacune des cartes FISA de l'adversaire
void RA1(plateau *p,int x,char id){
    if (id=='A'){
         deck_addPt(&(p->pileFisaB),-x,1);
    }
    else{
        deck_addPt(&(p->pileFisaA),-x,1);
    }
}

//Retirer X points de Durabilité à chacune des cartes FISA de l’adversaire
void RA2(plateau *p,int x,char id){
    if (id=='A'){
        deck_addPt(&(p->pileFisaB),-x,2);
    }
    else{
       deck_addPt(&(p->pileFisaA),-x,2);
    }
}

//Gagner X DD de plus à la fin du tour
void ADD(plateau *p,int x,char id){
    if (id=='A'){
       p->ADD_effetA= p->ADD_effetA+x ;
    }
    else{
        p->ADD_effetB= p->ADD_effetB+x;
    }
}

//L’adversaire retranche X DD au total gagné à la fin du tour
void RDD(plateau *p,int x,char id){
    if (id=='A'){
         p->RDD_effetB= p->RDD_effetB+x ;
    }
    else{
         p->RDD_effetA= p->RDD_effetA+x;
    }
}

//Piocher X cartes de plus au début de votre phase
void DR(plateau *p,int x,char id){
    if (id=='A'){
         p->piocheA= p->piocheA+x ;
    }
    else{
         p->piocheA= p->piocheA+x;
    }
}

//Mettez en jeu X cartes Élève de plus au début de votre phase
void E(plateau *p,int x,char id){
    if (id=='A'){
         p->EA= p->EA+x ;
    }
    else{
         p->EB= p->EB+x;
    }
}
    
/**
\brief:  permet d'ajouter des effets à une nouvelle carte FISA lorsque elle est ajouté au plateau (recherche les cartes actions déjà mise en jeu et application de leur effets)
\param: une carte FISA, un plateau et l'identifiant de l'ENSIIE
\return: nothing
*/
void ajout_effet_FISA(carte *c,plateau P,char id){
     if (id=='A'){
         if(deck_carteIn(P.sideA,Faye)) pt_DD_change(c,1);
         if(deck_carteIn(P.sideA,Mouilleron)) pt_Dur_change(c,1);
         if(deck_carteIn(P.sideA,Watel)) pt_DD_change(c,1);
         if(deck_carteIn(P.sideA,Y)) pt_Dur_change(c,1);;
         if(deck_carteIn(P.sideA,Mathias)){
             pt_DD_change(c,1);
             pt_Dur_change(c,1);
         }
         if(deck_carteIn(P.sideA,Sagna)){
             pt_DD_change(c,2);
             pt_Dur_change(c,2);
         }
         if(deck_carteIn(P.sideA,Prevel)){
             pt_DD_change(c,2);
             pt_Dur_change(c,2);
         }
        
         if(deck_carteIn(P.sideB,Brunel)) pt_DD_change(c,-1);
         if(deck_carteIn(P.sideB,Bourard)) pt_Dur_change(c,-1);
         if(deck_carteIn(P.sideB,Goilard)) pt_DD_change(c,-1);
         if(deck_carteIn(P.sideB,Jeannas)) pt_Dur_change(c,-1);
         if(deck_carteIn(P.sideB,Mathias)) pt_Dur_change(c,-1);
     }
         
     else {
         if(deck_carteIn(P.sideB,Faye)) pt_DD_change(c,1);
          if(deck_carteIn(P.sideB,Mouilleron)) pt_Dur_change(c,1);
          if(deck_carteIn(P.sideB,Watel)) pt_DD_change(c,1);
          if(deck_carteIn(P.sideB,Y)) pt_Dur_change(c,1);;
          if(deck_carteIn(P.sideB,Mathias)){
              pt_DD_change(c,1);
              pt_Dur_change(c,1);
          }
          if(deck_carteIn(P.sideB,Sagna)){
              pt_DD_change(c,2);
              pt_Dur_change(c,2);
          }
          if(deck_carteIn(P.sideB,Prevel)){
              pt_DD_change(c,2);
              pt_Dur_change(c,2);
          }
         
          if(deck_carteIn(P.sideA,Brunel)) pt_DD_change(c,-1);
          if(deck_carteIn(P.sideA,Bourard)) pt_Dur_change(c,-1);
          if(deck_carteIn(P.sideA,Goilard)) pt_DD_change(c,-1);
          if(deck_carteIn(P.sideA,Jeannas)) pt_Dur_change(c,-1);
          if(deck_carteIn(P.sideA,Mathias)) pt_Dur_change(c,-1);
     }
}

/**
 \brief:  permet d'ajouter des effets à une nouvelle carte FISE lorsque elle est ajouté au plateau (recherche les cartes actions déjà mise en jeu et application de leur effets)
 \param: une carte FISE, un plateau et l'identifiant de l'ENSIIE
 \return: nothing
 */
void ajout_effet_FISE(carte *c,plateau P,char id){
    if (id=='A'){
        if(deck_carteIn(P.sideA,Lim))pt_DD_change(c,1);
        if(deck_carteIn(P.sideA,Szafranski))pt_Dur_change(c,1);
        if(deck_carteIn(P.sideA,Watel))pt_DD_change(c,1);
        if(deck_carteIn(P.sideA,Y))pt_Dur_change(c,1);
        if(deck_carteIn(P.sideA,Lejeune)){
            pt_DD_change(c,1);
            pt_Dur_change(c,1);
        }
        if(deck_carteIn(P.sideA,Salhab)){
            pt_DD_change(c,2);
            pt_Dur_change(c,2);
        }
        if(deck_carteIn(P.sideA,Prevel)){
            pt_DD_change(c,2);
            pt_Dur_change(c,2);
        }
    
        if(deck_carteIn(P.sideB,Dumbrava))pt_DD_change(c,-1);
        if(deck_carteIn(P.sideB,Forest))pt_Dur_change(c,-1);
        if(deck_carteIn(P.sideB,Goilard))pt_DD_change(c,-1);
        if(deck_carteIn(P.sideB,Jeannas))pt_Dur_change(c,-1);
        if(deck_carteIn(P.sideB,Lejeune))pt_Dur_change(c,-1);
    }
    else{
        if(deck_carteIn(P.sideB,Lim))pt_DD_change(c,1);
        if(deck_carteIn(P.sideB,Szafranski))pt_Dur_change(c,1);
        if(deck_carteIn(P.sideB,Watel))pt_DD_change(c,1);
        if(deck_carteIn(P.sideB,Y))pt_Dur_change(c,1);
        if(deck_carteIn(P.sideB,Lejeune)){
            pt_DD_change(c,1);
            pt_Dur_change(c,1);
        }
        if(deck_carteIn(P.sideB,Salhab)){
            pt_DD_change(c,2);
            pt_Dur_change(c,2);
        }
        if(deck_carteIn(P.sideB,Prevel)){
            pt_DD_change(c,2);
            pt_Dur_change(c,2);
        }
    
        if(deck_carteIn(P.sideA,Dumbrava))pt_DD_change(c,-1);
        if(deck_carteIn(P.sideA,Forest))pt_Dur_change(c,-1);
        if(deck_carteIn(P.sideA,Goilard))pt_DD_change(c,-1);
        if(deck_carteIn(P.sideA,Jeannas))pt_Dur_change(c,-1);
        if(deck_carteIn(P.sideA,Lejeune))pt_Dur_change(c,-1);
    }
}

/**
\brief:  supprimer  les effets d'une carte personnel lorsque celle-ci est retirée du plateau
\param: la carte personnel,  un plateau et l'identifiant de l'ENSIIE
\return: nothing
*/

void retire_carte_personnel(carte c, plateau *p, char id) {
    switch(getNom(c)){
        case Lim: AE1(p,-1,id); break;
        case Szafranski: AE2(p,-1,id); break;
        case Faye: AA1(p,-1,id);break;
        case Mouilleron:AA2(p,-1,id);break;
        case Dumbrava:RE1(p,-1,id);break;
        case Forest:RE2(p,-1,id);break;
        case Brunel:RA1(p,-1,id); break;
        case Bourard:RA2(p,-1,id) ;break;
        case Watel:
            AE1(p,-1,id);
            AA1(p,-1,id);
            break;
        case Y:
            AE2(p,-1,id);
            AA2(p,-1,id);
            break;
        case Goilard:
            RE1(p,-1,id);
            RA1(p,-1,id);
            break;
        case Jeannas:
            RE2(p,-1,id);
            RA2(p,-1,id);
            break;
        case Merabet:
            DR(p,-2,id);
            break;
        case Ligozat:
            ADD(p,-2,id);
            DR(p,-1,id);
            E(p,-1,id);
            break;
        case Dubois:
            RDD(p,-2,id);
            DR(p,-1,id);
            E(p,-1,id);
            break;
        case Lejeune:
            AE1(p,-1,id);
            AE2(p,-1,id);
            RE2(p,-1,id);
            RDD(p,-1,id);
            break;
        case Mathias:
            AA1(p,-1,id);
            AA2(p,-1,id);
            RA2(p,-1,id);
            RDD(p,-1,id);
            break;
        case Salhab:
            AE1(p,-2,id);
            AE2(p,-2,id);
            E(p,-1,id);
            break;
        case Sagna:
            AA1(p,-2,id);
            AA2(p,-2,id);
            E(p,-1,id);
            break;
        case Prevel:
            AE1(p,-2,id);
            AE2(p,-2,id);
            AA1(p,-2,id);
            AA2(p,-2,id);
            ADD(p,-1,id);
            RDD(p,-1,id);
            DR(p,-1,id);
            E(p,-2,id);
            break;
        default:
            printf("n'est pas une carte personnel");
    };
    if(id=='A') {
        deck_add_last(c,&(p->defausseA));
    }
    else {
        deck_add_last(c,&(p->defausseB));
    };
}


    
    
/* Les fonctions utiles pour coder le jeu (accessibles depuis le header) */

int pioche_eleve(plateau p, char id){
    if (id=='A'){
        return p.piocheA;
    }
    else {
        return p.piocheB;
    }
}


void carte_ajouter(Nom nom, plateau *p, char id) {
    carte carte=carte_new(nom);
    if (id=='A'){
        if (nom==Fise){
            ajout_effet_FISE(&carte,*p,id);
            deck_add_last(carte,&(p->pileFiseA));
        }
        else if (nom==Fisa){
            ajout_effet_FISA(&carte,*p,id);
            deck_add_last(carte,&(p->pileFisaA));
        }
        else 
            printf ("Ce n'est pas une carte élève");
    }
    else {
        if (nom==Fise){
            ajout_effet_FISE(&carte,*p,id);
            deck_add_last(carte,&(p->pileFiseB));
        }
        else if (nom==Fisa){
            ajout_effet_FISA(&carte,*p,id);
            deck_add_last(carte,&(p->pileFisaB));
        }
        else 
            printf ("Ce n'est pas une carte élève");
    }

}


void carte_personnel(carte c,plateau *p,char id){
        switch(getNom(c)){
            case Lim: AE1(p,1,id); break;
            case Szafranski: AE2(p,1,id); break;
            case Faye: AA1(p,1,id);break;
            case Mouilleron:AA2(p,1,id);break;
            case Dumbrava:RE1(p,1,id);break;
            case Forest:RE2(p,1,id);break;
            case Brunel:RA1(p,1,id); break;
            case Bourard:RA2(p,1,id) ;break;
            case Watel:
                AE1(p,1,id);
                AA1(p,1,id);
                break;
            case Y:
                AE2(p,1,id);
                AA2(p,1,id);
                break;
            case Goilard:
                RE1(p,1,id);
                RA1(p,1,id);
                break;
            case Jeannas:
                RE2(p,1,id);
                RA2(p,1,id);
                break;
            case Merabet:
                DR(p,2,id);
                break;
            case Ligozat:
                ADD(p,2,id);
                DR(p,1,id);
                E(p,1,id);
                break;
            case Dubois:
                RDD(p,2,id);
                DR(p,1,id);
                E(p,1,id);
                break;
            case Lejeune:
                AE1(p,1,id);
                AE2(p,1,id);
                RE2(p,1,id);
                RDD(p,1,id);
                break;
            case Mathias:
                AA1(p,1,id);
                AA2(p,1,id);
                RA2(p,1,id);
                RDD(p,1,id);
                break;
            case Salhab:
                AE1(p,2,id);
                AE2(p,2,id);
                E(p,1,id);
                break;
            case Sagna:
                AA1(p,2,id);
                AA2(p,2,id);
                E(p,1,id);
                break;
            case Prevel:
                AE1(p,2,id);
                AE2(p,2,id);
                AA1(p,2,id);
                AA2(p,2,id);
                ADD(p,1,id);
                RDD(p,1,id);
                DR(p,1,id);
                E(p,2,id);
                break;
            default:
                printf("n'est pas une carte personnel");
        }
    }

void carte_action(carte *c, plateau *p, char id){
    if (id=='A'){
        switch(getNom(*c)) {
            case Cours_developpemnt_durable:
                p->ddA=p->ddA+1;
                break;
            case Rentree_FISE:
                carte_ajouter(Fise, p, 'A');
                break;
            case Rentree_FISA:
                if((p->tour)%2==1) carte_ajouter(Fisa, p, 'A');
                break;
            case Energie_verte:
                p->nrjA=p->nrjA+6;
                break;
            case Diplomation:
                if (deck_isEmpty(p->pileFiseB)){
                    printf ("vous ne pouvez pas retirer de carte FISE au platau de l'adversaire\n");
                }
                else{
                    carte carteFISE= deck_remove_head(&(p->pileFiseB));
                    deck_add_last(carteFISE,&(p->defausseB));
                }
                if((p->tour)%2==1){
                    if (deck_isEmpty(p->pileFisaB)){
                        printf ("vous ne pouvez pas retirer de carte FISA au platau de l'adversaire\n");
                    }
                    else{
                        carte carteFISA= deck_remove_head(&(p->pileFisaB));
                        deck_add_last(carteFISA,&(p->defausseB));
                    }
                }
                break;
            case Decharge:
                if (deck_isEmpty(p->sideB)){
                    printf ("vous ne pouvez pas retirer de carte personnel au platau de l'adversaire\n");
                }
                else{
                    carte cartePerso= deck_remove_head(&(p->sideB));
                    deck_add_last(cartePerso,&(p->defausseB));
                }
                break;
            case Recyclage:
                deck_add_last(*c,&(p->deckA));
                deck_concatenate(&(p->deckA),&(p->defausseA));
                melanger_deck(&(p->deckA));
                break;
            case Zero_papier:
                p->ZDA=p->ZDA+1;
                AE1(p,1,'A');
                AA1(p,1,'A');
                break;
            case Repas_vegetarien:
                p->RVA=p->RVA+1;
                AE2(p,1,'A');
                AA2(p,1,'A');
                break;
            case Fermeture_annuelle:
                deck_concatenate(&(p->defausseA),&(p->pileFisaA));
                if((p->tour)%2==1)deck_concatenate(&(p->defausseA),&(p->pileFiseA));
                deck_concatenate(&(p->defausseB),&(p->pileFisaB));
                if((p->tour)%2==1)deck_concatenate(&(p->defausseB),&(p->pileFiseB));
                break;
            case Recrutement:
                ;carte aux= deck_remove_queue(&(p->deckA));
                deck_add_last(aux,&(p->mainA));
                break;
            default: printf("n'est pas une carte action");break;
        }
    }
    else{
        switch(getNom(*c)){
            case Cours_developpemnt_durable:
                p->ddB=p->ddB+1;
                break;
            case Recrutement:
                ;carte aux=deck_remove_queue(&(p->deckB));
                deck_add_last(aux,&(p->mainB));
                break;
            case Rentree_FISE:
                carte_ajouter(Fise, p, 'B');
                break;
            case Rentree_FISA:
                if((p->tour)%2==1)carte_ajouter(Fisa,p,'B');
                break;
            case Energie_verte:
                p->nrjB=p->nrjB+6;
                break;
            case Diplomation:
                if (deck_isEmpty(p->pileFiseA)){
                    printf ("vous ne pouvez pas retirer de carte FISE au platau de l'adversaire\n");
                }
                else{
                    carte carteFISE= deck_remove_head(&(p->pileFiseA));
                    deck_add_last(carteFISE,&(p->defausseA));
                }
                if((p->tour)%2==1){
                    if (deck_isEmpty(p->pileFisaA)){
                        printf ("vous ne pouvez pas retirer de carte FISA au platau de l'adversaire\n");
                    }
                    else{
                        carte carteFISA= deck_remove_head(&(p->pileFisaA));
                        deck_add_last(carteFISA,&(p->defausseA));
                    }
                }
                break;
            case Decharge:
                if (deck_isEmpty(p->sideA)){
                    printf ("vous ne pouvez pas retirer de carte personnel au platau de l'adversaire\n");
                }
                else{
                    carte cartePerso= deck_remove_head(&(p->sideA));
                    deck_add_last(cartePerso,&(p->defausseA));
                }
                break;
            case Recyclage:
                deck_add_last(*c,&(p->deckB));
                deck_concatenate(&(p->deckB),&(p->defausseB));
                melanger_deck(&(p->deckB));
                break;
            case Zero_papier:
                p->ZDB=p->ZDB+1;
                AE1(p,1,'B');
                AA1(p,1,'B');
                break;
            case Repas_vegetarien:
                p->RVB=p->RVB+1;
                AE2(p,1,'B');
                AA2(p,1,'B');
                break;
            case Fermeture_annuelle:
                if((p->tour)%2==1)deck_concatenate(&(p->defausseA),&(p->pileFisaA));
                deck_concatenate(&(p->defausseA),&(p->pileFiseA));
                if((p->tour)%2==1) deck_concatenate(&(p->defausseB),&(p->pileFisaB));
                deck_concatenate(&(p->defausseB),&(p->pileFiseB));
                break;
            default: printf("n'est pas une carte action");break;
        }
    }
}


// la carte est préalablement extraite de la main
void carte_jouer(carte c, plateau *p, char id){
    switch(getType(c)){
        
        case Personnel:
            if(id=='A') {
                if(cout(c) <= p->nrjA) {
                    deck_add_last(c,&(p->sideA));
                    carte_personnel(c,p,id);
                    int nbCardsPerso = 0;
                    deck d = p->sideA;
                    while(d != NULL) {
                        if(getType((d->carte)) == Personnel)    /* le plateau ne doit contenir que des cartes personnels, mais il est utile de vérifier 
                                                                cette condition au cas ou l'on rajoute un nouveau type de carte par la suite dans le jeu */

                            nbCardsPerso++;         // on récupère le nombre de cartes personnelles que l'on a jouée sur le plateau
                        d= d -> next;
                    }
                    if(nbCardsPerso > p->maxcarte) {
                        retire_carte_personnel(deck_remove_head(&(p->sideA)),p,id);         // on retire alors la plus ancienne carte perso déjà posée
                    }
                    p->nrjA-=cout(c);
                    p->nbcarteA --;
                }
                else {
                    printf("\nVous ne pouvez pas jouer cette carte : pas assez d'énergie !!! \n\n");
                    deck_add_last(c,&(p->mainA));   // on remet la carte dans la main de l'ENSIIE A
                }
            }
            else {
                if(cout(c) <= p->nrjB) {
                    deck_add_last(c,&(p->sideB));
                    carte_personnel(c,p,id);
                    int nbCardsPerso = 0;
                    deck d = p->sideB;
                    while(d != NULL) {
                        if(getType((d->carte)) == Personnel)
                            nbCardsPerso++;
                        d= d -> next;
                    }
                    if(nbCardsPerso > p->maxcarte) {
                        retire_carte_personnel(deck_remove_head(&(p->sideB)),p,id);
                    }
                    p->nrjB-=cout(c);
                    p->nbcarteB --;                             
                }
                else {
                    printf("\nVous ne pouvez pas jouer cette carte : pas assez d'énergie !!! \n\n");
                    deck_add_last(c,&(p->mainB));
                }
            };

            break;
       
        case Action:
            if(id=='A') {
                if(cout(c)<=p->nrjA) {
                    deck_add_last(c,&(p->defausseA));
                    p->nrjA-=cout(c);
                    p->nbcarteA --;
                    carte_action(&c,p,id);
                }
                else {
                    printf("\nVous ne pouvez pas jouer cette carte : pas assez d'énergie !!! \n\n");
                    deck_add_last(c,&(p->mainA));
                }
            }
            else {
                if(cout(c)<=p->nrjB) {
                    deck_add_last(c,&(p->defausseB));
                    p->nrjB=-cout(c);
                    p->nbcarteB --;
                    carte_action(&c,p,id);
                }
                else {
                    printf(" \nVous ne pouvez pas jouer cette carte : pas assez d'énergie  !!! \n\n");
                    deck_add_last(c,&(p->mainB));
                }
            }
            break;
        default: printf("Carte non reconnu\n"); break;
    };
                                               
}
                                            
void carte_fin(plateau *p) {
    
    int aux_FISE_dur_B=deck_parcours_durabilite(p->pileFiseB);
    int aux_FISE_dev_B=deck_parcours_devellopement(p->pileFiseB);
    int aux_FISE_dur_A=deck_parcours_durabilite(p->pileFiseA);
    int aux_FISE_dev_A=deck_parcours_devellopement(p->pileFiseA);
    
    int aux_FISA_dur_B=0;
    int aux_FISA_dev_B=0;
    int aux_FISA_dur_A=0;
    int aux_FISA_dev_A=0;
    
    if((p->tour)%2==1){
    int aux_FISA_dur_B=deck_parcours_durabilite(p->pileFisaB);
    int aux_FISA_dev_B=deck_parcours_devellopement(p->pileFisaB);
    int aux_FISA_dur_A=deck_parcours_durabilite(p->pileFisaA);
    int aux_FISA_dev_A=deck_parcours_devellopement(p->pileFisaA);
    }
    
    int add_A = aux_FISE_dev_A + aux_FISA_dev_A + p->ADD_effetA;
    int sous_A = aux_FISE_dur_B + aux_FISA_dur_B + p->RDD_effetA;
    
    int add_B = aux_FISE_dev_B + aux_FISA_dev_B + p->ADD_effetB;
    int sous_B = aux_FISE_dur_A + aux_FISA_dur_A + p->RDD_effetB;
    

    if((add_A - sous_A > add_B - sous_B) && (add_A - sous_A > 0)) {
        p->ddA += (add_A - sous_A);
        printf("\nL'ENSIIE A a gagné %d points de DD lors du tour numéro %d !!! \n\n",add_A - sous_A,p->tour);
    }
    else if ((add_A - sous_A < add_B - sous_B) && (add_B - sous_B > 0)) {
        p->ddB += (add_B - sous_B);
        printf("\nL'ENSIIE B a gagné %d points de DD lors du tour numéro %d !!! \n\n",add_B - sous_B,p->tour);
    }
    else if ((add_A - sous_A == add_B - sous_B) && (add_A - sous_A > 0)){
        p->ddA += (add_A - sous_A);
        p->ddB += (add_B - sous_B);
        printf("\nChaque ENSIIE a gagné %d points de DD lors du tour numéro %d !!! \n\n",add_A - sous_A,p->tour);
    }
    else
        printf("\nAucune ENSIIE n'a gagné de points de DD lors du tour numéro %d !!! \n\n",p->tour);
    
    p->nrjA=0;
    p->nrjB=0;
}




