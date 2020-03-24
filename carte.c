//
//  carte.c
//  
//
//  Created by Loirs Romain on 06/03/2020.
//

#include "carte.h"
#include <stdio.h>

/* les fonctions annexes (utilise uiquement pour le dévellopeur) */

/*void AE1(plateau plateau,int x){
}

void AE2(plateau plateau,int x){
}

void AA1(plateau plateau,int x){
}

void AA2(plateau plateau,int x){
}

void RE1(plateau plateau,int x){
}

void RE2(plateau plateau,int x){
}

void RA1(plateau plateau,int x){
}

void RA2(plateau plateau,int x){
}

void ADD(plateau plateau,int x){
}

void RDD(plateau plateau,int x){
}

void DR(plateau plateau,int x){
}

void E(plateau plateau,int x){
}*/

carte carte_new(Nom carte_nom){
    carte res;
    res.nom= carte_nom;
    
    res.type=Personnel;
    res.pt_dev=1;
    res.pt_dur=1;
    res.pt_nrj=1;
    res.cout=1;
    
    return res;
    }

void NomPrint(carte c){
    switch(c.nom){
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

/* Les fonctions principales (directements utilisables par l'extérieur) */

void carte_print(carte c){
    printf("\n");
    printf("* "); NomPrint(c); printf(" *\n");
    switch(c.type){
        case Eleve:
            printf("- type: eleve\n");
            printf("- point_déveleppement_durable= %d *\n",c.pt_dev);
            printf("- point_durabilite= %d \n",c.pt_dur);
            printf("- point_energie= %d\n",c.pt_nrj);
            break;
        case Personnel:
            printf("- type: personnel\n");
            printf("- cout: %d \n",c.cout);
            break;
        case Action:
            printf("- type: action\n");
            printf("- cout: %d \n",c.cout);
            break;
    }
    printf("\n");
}



