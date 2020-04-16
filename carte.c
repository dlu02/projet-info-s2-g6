//
//  carte.c
//  
//
//  Created by Loirs Romain on 06/03/2020.

#include "carte.h"
#include "structure.h"
#include <stdio.h>


// les fonctions pour manipuler les cartes//

Type getType(carte c){
    return c.type;
}

Nom getNom(carte c){
    return c.nom;
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

//deux cartes sont égales si elles ont le meme nom, unicité des cartes personnels et actions dans les decks, pour les cartes FISE et FISA, elles n'ont pas d'identité propre. Cas à part
int carte_equal(carte c1,Nom nom){
    return c1.nom==nom;
}



/* les fonctions annexes. Elles sont utiles pour d'autres fonctions (non définis dans le header) */

/*permet d'afficher le nom d'une carte
 utilisé avec carte_print*/
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
        case Rentrée_FISE: printf("Rentrée_FISE");break;
        case Rentrée_FISA: printf("Rentrée_FISA");break;
        case Energie_verte: printf("Energie_verte");break;
        case Diplomation: printf("Diplomation");break;
        case Decharge: printf("decharge");break;
        case Recyclage: printf("Recyclage");break;
        case Zero_papier: printf("Zero_papier");break;
        case Repas_vegetarien: printf("Repas_vegetarien");break;
        case Fermeture_annuelle: printf("Fermeture_annuelle");break;
    }
}

/*permet de déterminer le cout d'une carte en fonction de son nom
  fonction utilse pour new_carte*/
long aux_code(Nom nom){
    switch(nom){
        case Fise: return 1001001; break;
        case Fisa: return 1001001; break;
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
        case Rentrée_FISE:return 3;break;
        case Rentrée_FISA:return 3;break;
        case Energie_verte: return 4;break;
        case Diplomation: return 5;break;
        case Decharge: return 5;break;
        case Recyclage: return 10;break;
        case Zero_papier: return 10;break;
        case Repas_vegetarien: return 10;break;
        case Fermeture_annuelle: return 10;break;
    }
}

/* ajoute x points de dévellopement à chacune de vos cartes FISE*/
void AE1(plateau *p,int x, char id){
    if (id=='A'){
        deck_addPt(&(p->pileFiseA),x,1);
    }
    else{
        deck_addPt(&(p->pileFiseB),x,1);
    }
}

void AE2(plateau *p,int x, char id){
    if (id=='A'){
        deck_addPt(&(p->pileFiseA),x,2);
    }
    else{
        deck_addPt(&(p->pileFiseB),x,2);
    }
}

void AA1(plateau *p,int x, char id){
    if (id=='A'){
        deck_addPt(&(p->pileFisaA),x,1);
    }
    else{
        deck_addPt(&(p->pileFisaB),x,1);
    }
}

void AA2(plateau *p,int x,char id){
    if (id=='A'){
        deck_addPt(&(p->pileFisaA),x,2);
    }
    else{
        deck_addPt(&(p->pileFisaB),x,2);
    }
}

/*retirer x*/
void RE1(plateau *p,int x,char id){
    if (id=='A'){
        deck_addPt(&(p->pileFiseB),-x,1);
    }
    else{
        deck_addPt(&(p->pileFiseA),-x,1);
    }
}

void RE2(plateau *p,int x,char id ){
    if (id=='A'){
        deck_addPt(&(p->pileFiseB),-x,2);
    }
    else{
        deck_addPt(&(p->pileFiseA),-x,2);
    }
}

void RA1(plateau *p,int x,char id){
    if (id=='A'){
        deck_addPt(&(p->pileFisaB),-x,1);
    }
    else{
        deck_addPt(&(p->pileFisaA),-x,1);
    }
}

void RA2(plateau *p,int x,char id){
    if (id=='A'){
        deck_addPt(&(p->pileFisaB),-x,2);
    }
    else{
        deck_addPt(&(p->pileFisaA),-x,2);
    }
}

void ADD(plateau *p,int x,char id){
    if (id=='A'){
       p->ADD_effetA= p->ADD_effetA+x ;
    }
    else{
        p->ADD_effetB= p->ADD_effetB+x;
    }
}

void RDD(plateau *p,int x,char id){
    if (id=='A'){
         p->RDD_effetB= p->RDD_effetB+x ;
    }
    else{
         p->RDD_effetA= p->RDD_effetA+x;
    }
}

void DR(plateau *p,int x,char id){
    if (id=='A'){
         p->piocheA= p->piocheA+x ;
    }
    else{
         p->piocheA= p->piocheA+x;
    }
}

void E(plateau *p,int x,char id){
    if (id=='A'){
         p->EA= p->EA+x ;
    }
    else{
         p->EB= p->EB+x;
    }
}

//prend en paramétre une carte FISA, ajoute un effet qi la carte personnel est deja present sur le plateau
void ajout_effet_FISA(carte *c,plateau p,char id){
     if (id=='A'){
           while (p.sideA != NULL){
               switch (getNom(p.sideA->carte)){
                   case Faye: pt_DD_change(c,1);break;
                   case Mouilleron: pt_Dur_change(c,1);break;
                   case Watel:pt_DD_change(c,1);break;
                   case Y:pt_Dur_change(c,1);break;
                   case Mathias:
                       pt_DD_change(c,1);
                       pt_Dur_change(c,1);
                       break;
                   case Sagna:
                       pt_DD_change(c,2);
                       pt_Dur_change(c,2);
                       break;
                   case Prevel:
                       pt_DD_change(c,2);
                       pt_Dur_change(c,2);
                       break;
                default: break;
               }
            p.sideA=p.sideA->next;
        }
         while(p.sideB != NULL){
                 switch (getNom(p.sideB->carte)){
                     case Brunel:pt_DD_change(c,-1);break;
                     case Bourard:pt_Dur_change(c,-1);break;
                     case Goilard:pt_DD_change(c,-1);break;
                     case Jeannas:pt_Dur_change(c,-1);break;
                     case Mathias:pt_Dur_change(c,-1); break;
                     default: break;
                 }
                 p.sideB=p.sideB->next;
             }
         }
     else {
         while (p.sideB != NULL){
           switch (getNom(p.sideB->carte)){
               case Faye: pt_DD_change(c,1);break;
               case Mouilleron: pt_Dur_change(c,1);break;
               case Watel:pt_DD_change(c,1);break;
               case Y:pt_Dur_change(c,1);break;
               case Mathias:
                   pt_DD_change(c,1);
                   pt_Dur_change(c,1);
                   break;
               case Sagna:
                   pt_DD_change(c,2);
                   pt_Dur_change(c,2);
                   break;
               case Prevel:
                   pt_DD_change(c,2);
                   pt_Dur_change(c,2);
                   break;
            default: break;
           }
        p.sideB=p.sideB->next;
    }
     while(p.sideA != NULL){
             switch (getNom(p.sideB->carte)){
                 case Brunel:pt_DD_change(c,-1);break;
                 case Bourard:pt_Dur_change(c,-1);break;
                 case Goilard:pt_DD_change(c,-1);break;
                 case Jeannas:pt_Dur_change(c,-1);break;
                 case Mathias:pt_Dur_change(c,-1); break;
                 default: break;
             }
             p.sideA=p.sideA->next;
         }
     }
}


void ajout_effet_FISE(carte *c,plateau p,char id){
    if (id=='A'){
        while (p.sideA != NULL){
            switch (getNom(p.sideA->carte)){
                case Lim: pt_DD_change(c,1); break;
                case Szafranski: pt_Dur_change(c,1); break;
                case Watel:pt_DD_change(c,1);break;
                case Y:pt_Dur_change(c,1);break;
                case Lejeune:
                    pt_DD_change(c,1);
                    pt_Dur_change(c,1);
                    break;
                case Salhab:
                    pt_DD_change(c,2);
                    pt_Dur_change(c,2);
                    break;
                case Prevel:
                    pt_DD_change(c,2);
                    pt_Dur_change(c,2);
                    break;
                default: break;
            }
            p.sideA=p.sideA->next;
        }
        while(p.sideB != NULL){
            switch (getNom(p.sideA->carte)){
                case Dumbrava:pt_DD_change(c,-1);break;
                case Forest:pt_Dur_change(c,-1);break;
                case Goilard:pt_DD_change(c,-1);break;
                case Jeannas:pt_Dur_change(c,-1);break;
                case Lejeune:pt_Dur_change(c,-1); break;
                default: break;
            }
            p.sideB=p.sideB->next;
        }
    }
    else{
        while (p.sideB != NULL){
            switch (getNom(p.sideB->carte)){
                case Lim: pt_DD_change(c,1); break;
                case Szafranski: pt_Dur_change(c,1); break;
                case Watel:pt_DD_change(c,1);break;
                case Y:pt_Dur_change(c,1);break;
                case Lejeune:
                    pt_DD_change(c,1);
                    pt_Dur_change(c,1);
                    break;
                case Salhab:
                    pt_DD_change(c,2);
                    pt_Dur_change(c,2);
                    break;
                case Prevel:
                    pt_DD_change(c,2);
                    pt_Dur_change(c,2);
                    break;
                default: break;
            }
            p.sideB=p.sideB->next;
        }
        while(p.sideA != NULL){
            switch (getNom(p.sideA->carte)){
                case Dumbrava:pt_DD_change(c,-1);break;
                case Forest:pt_Dur_change(c,-1);break;
                case Goilard:pt_DD_change(c,-1);break;
                case Jeannas:pt_Dur_change(c,-1);break;
                case Lejeune:pt_Dur_change(c,-1); break;
                default: break;
            }
            p.sideA=p.sideA->next;
        }
    }
}

void aux_action(carte c){
    switch(getNom(c)) {
        case Cours_developpemnt_durable: printf("cours_developpement durable");break;
        case Recrutement: printf("Recrutement");break;
        case Rentrée_FISE: printf("Rentrée_FISE");break;
        case Rentrée_FISA: printf("Rentrée_FISA");break;
        case Energie_verte: printf("Energie_verte");break;
        case Diplomation: printf("Diplomation");break;
        case Decharge: printf("Decharge");break;
        case Recyclage: printf("Recyclage");break;
        case Zero_papier: printf("Zero_papier");break;
        case Repas_vegetarien: printf("Repas_vegetarien");break;
        case Fermeture_annuelle: printf("Fermeture_annuelle");break;
    };
}



    
    
/* Les fonctions principales (accessibles depuis le header) */

carte carte_new(Nom carte_nom){
    carte res;
    res.nom= carte_nom;
    if (carte_nom<=1) {res.type=0;}
    else if (carte_nom<=21) {res.type=1;}
    else {res.type=2;}
    res.code=aux_code(carte_nom);
    return res;
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







//a voir avec Florian
int pioche_eleve(plateau p, char id){
    if (id=='A'){
        return p.piocheA;
    }
    else {
        return p.piocheB;
    }
}




void carte_ajouter(Nom nom, plateau *p, char id){
    carte carte=carte_new(nom);
    if (id=='A'){
        if (nom==Fise){
            ajout_effet_FISE(&carte,*p,'A');
            deck_add_last(carte,&(p->pileFiseA));
        }
        else if (nom==Fisa){            ajout_effet_FISA(&carte,*p,'A');
            deck_add_last(carte,&(p->pileFisaA));
        
        }
        else printf ("ce n'est pas une carte eleve");
    }
    else{
        if (nom==Fise){
            ajout_effet_FISE(&carte,*p,'B');
            deck_add_last(carte,&(p->pileFiseB));
        }
        else if (nom==Fisa){
            ajout_effet_FISA(&carte,*p,'B');
            deck_add_last(carte,&(p->pileFisaB));
        }
        else printf ("ce n'est pas une carte eleve");
    }
}





int carte_pointPE(plateau p, char id){
    if (id=='A'){
        return p.nrjA;
    }
    else{
        return p.nrjB;
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
        deck_add_last(c,p->defausseA);
    }
    else {
        deck_add_last(c,p->defausseB);
    };
}

void carte_action(carte c, plateau *p, char id) {
    switch(getNom(c)) {
        case Cours_developpemnt_durable:
            if(id=='A') {
                p->ddA+=1;
            }
            else {
                p->ddB+=1;
            };
            break;
        case Recrutement:
            if(id=='A') {
                deck_add_last(deck_remove_head(p->deckA),&(p->mainA));
            }
            else {
                deck_add_last(deck_remove_head(p->deckB),&(p->mainB));
            }
            break;
        case Rentrée_FISE: 
            carte_ajouter(Fise,p,id);
            break;
        case Rentrée_FISA: 
            carte_ajouter(Fise,p,id);
            break;
        case Energie_verte:
            if(id=='A') {
                p->nrjA+=6;
            }
            else {
                p->nrjB+=6;
            };
            break;
        case Diplomation:
            if(id=='A') {
                deck_remove_head(&(p->pileFiseB));
                deck_remove_head(&(p->pileFisaB));
            }
            else {
                deck_remove_head(&(p->pileFiseA));
                deck_remove_head(&(p->pileFisaA));
            };
            break;
        case Decharge:
            if(id=='A') {
                deck_add_last(deck_remove_head(&(p->sideB)),&(p->defausseB));
            }
            else {
                deck_add_last(deck_remove_head(&(p->sideA)),&(p->defausseA));
            };
            break;
        case Recyclage:
            
        case Zero_papier: printf("Zero_papier");break;
        case Repas_vegetarien: printf("Repas_vegetarien");break;
        case Fermeture_annuelle: printf("Fermeture_annuelle");break;
    }
}

void carte_jouer(carte c, plateau *p, char id){
    switch(getType(c)){
        case Personnel:
            if(id=='A') {
                if(cout(c)<=p->nrjA) {
                    deck_add_last(c,p->sideA);
                    if(deck_length(p->sideA)>p->nbcarteA) {
                        retire_carte_personnel(deck_remove_head(p->sideA),p,id);
                    };
                    p->nrjA-=cout(c);
                };
            }
            else {
                if(cout(c)<=p->nrjB) {
                    deck_add_last(c,p->sideB);
                    if(deck_length(p->sideB)>p->nbcarteB) {
                        retire_carte_personnel(deck_remove_head(p->sideB),p,id);
                    };
                    p->nrjB-=cout(c);
                };
            };
            carte_personnel(c,p,id);
            break;
        case Action:
            if(id=='A') {
                if(cout(c)<=p->nrjA) {
                    deck_add_last(c,p->defausseA);
                };
                p->nrjA-=cout(c);
            }
            else {
                if(cout(c)<=p->nrjB) {
                    deck_add_last(c,p->defausseB);
                };
                p->nrjB=-cout(c);
            };
            carte_action(c,p,id);
            break;
        default: printf("carte non reconnu"); break;
    };
}



void carte_fin(plateau *p) {

}




