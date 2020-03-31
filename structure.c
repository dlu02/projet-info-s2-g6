//
//  structure.c
//  
//
//  Created by Loirs Romain on 22/03/2020.
//

#include "carte.h"

#include <stdlib.h>
#include <stdio.h>




/* construction du deck et destrcution*/

deck deck_create(){
  return NULL;
}

int deck_isEmpty(deck l){
  return l==NULL;
}

deck deck_cons(carte x,deck l){
    deck res;
    res= (deck) malloc(sizeof(struct node));
    res->carte=x;
    res->next=l;
    return res;
}

void deck_free(deck l){
    deck tmp;
    while (l != NULL){
        tmp=l->next;
        free(l);
        l=tmp;
    }
}




/*addition d'element*/

void deck_add(carte x,deck *l){
    *l = deck_cons(x,*l);
}


void deck_add_last(carte x,deck *l){
    deck q;
    if (*l==NULL){
        *l=deck_cons(x,NULL);
    }
    else{
        q=*l;
        while (q->next != NULL){
            q=q->next;
        }
        q->next=deck_cons(x,NULL);
    }
}





/*retirer des elements*/

carte deck_remove_head(deck *l){
    carte res= (*l)->carte;
    deck tmp= (*l)->next;
    free(*l);
    *l = tmp;
    return res;
}

carte deck_remove_queue(deck *l){
    carte res;
    return res;
}

carte deck_remove_carte(deck *l, Nom nom){
    
}

carte deck_remove_indice(deck *l, int indice){
    
}



/*afficher le deck*/

void deck_print(deck l){
    if (deck_isEmpty(l)){
        printf("the deck is empty\n");
    }
    else{
        deck curl=l;
        int i=0;
        while(!deck_isEmpty(curl)){
            printf("carte n° %i",i);
            i=i+1;
            carte_print(curl->carte);
            curl=curl->next;
        }
    }
}





