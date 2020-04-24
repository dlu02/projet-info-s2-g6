#include"plateau.h"
#include"stdlib.h"
#include"time.h"
#include <unistd.h>



void remplir_deck(deck *res) {
    int i;
    for (i=0;i<33;i++){
        carte c=carte_new(i);
        if (i==22 || i==23){
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
    pioche(&new,'A');
    pioche(&new,'A');
    pioche(&new,'B');
    pioche(&new,'B');
    srand(time(NULL));
    new.nrjA=0;
    new.nrjB=0;
    new.ADD_effetA=0;
    new.ADD_effetB=0;
    new.RDD_effetA=0;
    new.RDD_effetB=0;
    new.piocheA=1;
    new.piocheB=1;
    new.EA=0;
    new.EB=0;
    new.RVA=0;
    new.RVB=0;
    new.ZDA=0;
    new.ZDB=0;
    if (rand()%2==0) {new.debutEnsiie = 'A';} else {new.debutEnsiie = 'B';};
    return new;
}



    
    /*d = deck_create();
    int compteur = (31+32)/2;
    long long p = 2*3*5*7*11*13*17*19*23*29*31*37*41*43*47*53*59*61*67*71*73*79*83*89*97*101*103*107;
    //produit des 31 premiers nombres premiers, afin de savoir si on a déjà la carte dans le deck ou non
    while (compteur!=0) {
        srand(time(NULL));
        int pointeur=rand()%31;
        switch (pointeur) {
            case 0: if (p%2==0) {deck_add_last(carte_new(2),&d); p/=2;compteur-=1;} break;
            case 1: if (p%3==0) {deck_add_last(carte_new(3),&d); p/=3;compteur-=2;} break;
            case 2: if (p%5==0) {deck_add_last(carte_new(4), &d); p/=5;compteur-=3;} break;
            case 3: if (p%7==0) {deck_add_last(carte_new(5), &d); p/=7;compteur-=4;} break;
            case 4: if (p%11==0) {deck_add_last(carte_new(6), &d); p/=11;compteur-=5;} break;
            case 5: if (p%13==0) {deck_add_last(carte_new(7), &d); p/=13;compteur-=6;} break;
            case 6: if (p%17==0) {deck_add_last(carte_new(8), &d); p/=17;compteur-=7;} break;
            case 7: if (p%19==0) {deck_add_last(carte_new(9),&d); p/=19;compteur-=8;} break;
            case 8: if (p%23==0) {deck_add_last(carte_new(10), &d); p/=23;compteur-=9;} break;
            case 9: if (p%29==0) {deck_add_last(carte_new(11), &d); p/=29;compteur-=10;} break;
            case 10: if (p%31==0) {deck_add_last(carte_new(12), &d); p/=31;compteur-=11;} break;
            case 11: if (p%37==0) {deck_add_last(carte_new(13), &d); p/=37;compteur-=12;} break;
            case 12: if (p%41==0) {deck_add_last(carte_new(14), &d); p/=41;compteur-=13;} break;
            case 13: if (p%43==0) {deck_add_last(carte_new(15), &d); p/=43;compteur-=14;} break;
            case 14: if (p%47==0) {deck_add_last(carte_new(16), &d); p/=47;compteur-=15;} break;
            case 15: if (p%53==0) {deck_add_last(carte_new(17), &d); p/=53;compteur-=16;} break;
            case 16: if (p%59==0) {deck_add_last(carte_new(18), &d); p/=59;compteur-=17;} break;
            case 17: if (p%61==0) {deck_add_last(carte_new(19), &d); p/=61;compteur-=18;} break;
            case 18: if (p%67==0) {deck_add_last(carte_new(20), &d); p/=67;compteur-=19;} break;
            case 19: if (p%71==0) {deck_add_last(carte_new(21), &d); p/=71;compteur-=20;} break;
            case 20: if (p%73==0) {deck_add_last(carte_new(22), &d); p/=73;compteur-=21;} break;
            case 21: if (p%79==0) {deck_add_last(carte_new(23), &d); p/=79;compteur-=22;} break;
            case 22: if (p%83==0) {deck_add_last(carte_new(24), &d); p/=83;compteur-=23;} break;
            case 23: if (p%89==0) {deck_add_last(carte_new(25), &d); p/=89;compteur-=24;} break;
            case 24: if (p%97==0) {deck_add_last(carte_new(26), &d); p/=97;compteur-=25;} break;
            case 25: if (p%101==0) {deck_add_last(carte_new(27), &d); p/=101;compteur-=26;} break;
            case 26: if (p%103==0) {deck_add_last(carte_new(28), &d); p/=103;compteur-=27;} break;
            case 27: if (p%107==0) {deck_add_last(carte_new(29), &d); p/=107;compteur-=28;} break;
            case 28: if (p%109==0) {deck_add_last(carte_new(30), &d); p/=109;compteur-=29;} break;
            case 29: if (p%113==0) {deck_add_last(carte_new(31), &d); p/=113;compteur-=30;} break;
            case 30: if (p%127==0) {deck_add_last(carte_new(32), &d); p/=127;compteur-=31;} break;
        }
    }*/

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
    if (ensiie=='A') {
        int res=p.piocheA;
        /*if(deck_carteIn(p.sideA,Prevel)){
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
        }*/
        /*while(p.sideA!=NULL) {
            if(getNom(p.sideA->carte)==Prevel) {
                res+=1;
            };
            if(getNom(p->sideA->carte)==Dubois) {
                res+=1;
            };
            if(getNom(p->sideA->carte)==Ligozat) {
                res+=1;
            };
            if(getNom(p->sideA->carte)==Merabet) {
                res+=2;
            };
        }*/
    }
    else {
        int res=p.piocheB;
        /*if(deck_carteIn(p.sideB,Prevel)){
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
        }*/
        /*while(p->sideB!=NULL) {
            if(getNom(p->sideB->carte)==Prevel) {
                res+=1;
            };
            if(getNom(p->sideB->carte)==Dubois) {
                res+=1;
            };
            if(getNom(p->sideB->carte)==Ligozat) {
                res+=1;
            };
            if(getNom(p->sideB->carte)==Merabet) {
                res+=2;
            }
        }*/
    }
    return res;
}

void pioche(plateau *p, char ensiie) {
    int nb= nb_cartes(*p,ensiie);
    if (ensiie=='A') {
        for (int i=0;i<nb;i++) {
            if (!deck_isEmpty(p->deckA)){
                carte c= deck_remove_head(&(p->deckA));
                deck_add_last(c,&(p->mainA));
            }
        };
    }
    else {
        for (int i=0;i<nb;i++){
             if (!deck_isEmpty(p->deckA)){
                 carte c= deck_remove_head(&(p->deckB));
                 deck_add_last(c,&(p->mainB));
             }
        }
    }
}


void new_tour(plateau *p) {
    p->tour+=1;
    if (p->tour==6) {
        p->maxcarte+=1;
    };
    if (p->tour==11) {
        p->tour+=1;
    };
    pioche(p,'A');
    pioche(p,'B');
}

int win(plateau p) {
    if(p.ddA==20) {
        return 1;
    };
    if(p.ddB==20) {
        return 2;
    }
    if(p.tour==30) {
        return 0;
    }
    return -1;
}
