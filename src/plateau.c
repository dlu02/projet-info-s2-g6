#include"plateau.h"
#include"stdlib.h"
#include"time.h"
#include <unistd.h>



void remplir_deck(deck *res) {
    int i;
    for (i=0;i<33;i++){

        carte c=carte_new(i);

        if(i == 0 || i == 1){   // carte eleves, elles ne sont pas dans le deck
            continue;
        }
        else if (i==22 || i==23){
            deck_add_last(c,res);
            deck_add_last(c,res);
            deck_add_last(c,res);
        }
        else if (i==24 || i==25 || i==26 || i==27){
            deck_add_last(c,res);
            deck_add_last(c,res);
        }
        else if (i==28){
            deck_add_last(c,res);
            deck_add_last(c,res);
            deck_add_last(c,res);
            deck_add_last(c,res);
        }
        else deck_add_last(c,res);
    }
}


plateau new_plateau() {
    plateau new;
    new.deckA = deck_create();
    new.deckB = deck_create();
    remplir_deck(&(new.deckA));
    melanger_deck(&(new.deckA));
    remplir_deck(&(new.deckB));
    melanger_deck(&(new.deckB));
    new.mainA = deck_create();
    new.mainB =  deck_create();
    new.defausseA = deck_create();
    new.defausseB = deck_create();
    new.pileFisaA = deck_create();
    new.pileFisaB = deck_create();
    new.pileFiseA = deck_create();
    new.pileFiseB = deck_create();
    new.nbcarteA = 0;
    new.nbcarteB = 0;
    new.sideA = deck_create();
    new.sideB = deck_create();
    new.tour = 0;
    new.ddA = 0;
    new.ddB = 0;
    new.maxcarte = 1;
    srand(time(NULL));
    new.nrjA=0;
    new.nrjB=0;
    new.ADD_effetA=0;
    new.ADD_effetB=0;
    new.RDD_effetA=0;
    new.RDD_effetB=0;
    new.piocheA=1;
    new.piocheB=1;
    new.EA=1;
    new.EB=1;
    new.RVA=0;
    new.RVB=0;
    new.ZDA=0;
    new.ZDB=0;
    if (rand()%2==0) {new.debutEnsiie = 'A';} else {new.debutEnsiie = 'B';};
    return new;
}

void free_plateau(plateau p) {
    deck_free(p.mainA);
    deck_free(p.mainB);
    deck_free(p.defausseA);
    deck_free(p.defausseB);
    deck_free(p.deckA);
    deck_free(p.deckB);
    deck_free(p.pileFisaB);
    deck_free(p.pileFisaA);
    deck_free(p.pileFiseA);
    deck_free(p.pileFiseB);
}

int nb_cartes(plateau p, char ensiie) {
    int res = 1;
    if (ensiie=='A') {
        res=p.piocheA;
        if(deck_carteIn(p.sideA,Prevel)){
            res+=1;
        }
        if(deck_carteIn(p.sideA,Dubois)){
            res+=1;
        }
        if(deck_carteIn(p.sideA,Ligozat)){
            res+=1;
        }
        if(deck_carteIn(p.sideA,Merabet)){
            res+=1;
        }
    }
    else {
        res=p.piocheB;
        if(deck_carteIn(p.sideB,Prevel)){
            res+=1;
        }
        if(deck_carteIn(p.sideB,Dubois)){
            res+=1;
        }
        if(deck_carteIn(p.sideB,Ligozat)){
            res+=1;
        }
        if(deck_carteIn(p.sideB,Merabet)){
            res+=1;
        }
    }
    return res;
}

void pioche(plateau *p, char ensiie) {
    int nb= nb_cartes(*p,ensiie);
    if (ensiie=='A') {
        for (int i=1;i<=nb;i++) {
            if (!deck_isEmpty(p->deckA)){
                carte c= deck_remove_head(&(p->deckA));
                deck_add_last(c,&(p->mainA));
                p->nbcarteA++;;
            }
        }
    }
    else {
        for (int i=1;i<=nb;i++){
             if (!deck_isEmpty(p->deckB)){
                 carte c= deck_remove_head(&(p->deckB));
                 deck_add_last(c,&(p->mainB));
                 p->nbcarteB++;;
             }
        }
    }
}


void updateEnergy (plateau *p){

    if(p->debutEnsiie == 'A'){
        if(p->tour % 2 == 0)   // tour pair
            p->nrjA = deck_parcours_energie(p->pileFiseA,1);
        else 
            p->nrjA = deck_parcours_energie(p->pileFiseA,1) + deck_parcours_energie(p->pileFisaA,2);
        
    }

    else {
        
       if(p->tour % 2 == 0)    // tour pair
            p->nrjB = deck_parcours_energie(p->pileFiseB,1);
         else 
            p->nrjB =  deck_parcours_energie(p->pileFiseB,1) + deck_parcours_energie(p->pileFisaB,2);
    }
}

void setDefaultValueEleves(plateau *p) {

    deck fiseA = p->pileFiseA;
    deck fiseB = p->pileFiseB;
    deck fisaA = p->pileFisaA;
    deck fisaB = p->pileFisaB;
    
    carte c;

    while(!deck_isEmpty(fiseA)){

        c = fiseA->carte;
        if(pt_DD(c) < 0)
            pt_DD_change(&c,0);

        if(pt_Dur(c) < 0)
            pt_Dur_change(&c,0);

        fiseA=fiseA->next;
    }

    while(!deck_isEmpty(fiseB)){

        c = fiseB->carte;

        if(pt_DD(c) < 0)
            pt_DD_change(&c,0);

        if(pt_Dur(c) < 0)
            pt_Dur_change(&c,0);

        fiseB=fiseB->next;
    }

   while(!deck_isEmpty(fisaA)){

        c = fisaA->carte;

        if(pt_DD(c) < 0)
            pt_DD_change(&c,0);

        if(pt_Dur(c) < 0)
            pt_Dur_change(&c,0);

        fisaA=fisaA->next;
    }

    while(!deck_isEmpty(fisaB)){

        c = fisaB->carte;

        if(pt_DD(c) < 0)
            pt_DD_change(&c,0);

        if(pt_Dur(c) < 0)
            pt_Dur_change(&c,0);

        fisaB=fisaB->next;
    }


}

void new_tour(plateau *p) {
    p->tour++;
    if (p->tour==6) {
        p->maxcarte++;
    }
    if (p->tour==11) {
        p->maxcarte++;
    }
}

int win(plateau p) {

    if(p.ddA >= 20 || p.ddB >= 20 || p.tour==30 ) 
        return 1;
      
    return -1;
}
