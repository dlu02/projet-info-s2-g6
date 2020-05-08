//
//  structure.c
//
//
//  Created by Loirs Romain on 22/03/2020.
//

#include "carte.h"

#include <stdlib.h>
#include <stdio.h>
#include"time.h"
#include <unistd.h>




/* construction du deck et destruction*/

deck deck_create(){
  return NULL;
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

/**
\brief: ajouter une carte au sommet d'un deck. La fonction créer la node contenant la carte.
\param: une carte et un deck
\return:  un deck contentant la carte
*/
deck deck_cons(carte x,deck l){
    deck res;
    res= (deck) malloc(sizeof(struct node));
    res->carte=x;
    res->next=l;
    return res;
}

/**
\brief: ajouter une carte au sommet d'un deck
\param: une carte et un deck
\return:  nothing
*/
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


/*fonction de contrôle*/

int deck_isEmpty(deck l){
  return l==NULL;
}

int deck_carteIn(deck l, Nom nom){
    while (l != NULL){
        if (carte_equal(l->carte,nom)) return 1;
        l=l->next;
    }
    return 0;
}

int deck_length(deck l){
    int i=0;
    while (l != NULL){
        i++;
        l=l->next;
    }
    return i;
}

void deck_print(deck l){
    if (deck_isEmpty(l)){
        printf("the deck is empty\n");
    }
    else{
        deck curl=l;
        int i=0;
        while(!deck_isEmpty(curl)){
            printf("carte n° %i",i);
            i++;
            carte_print(curl->carte);
            curl=curl->next;
        }
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

carte deck_remove_queue(deck *l)
    {
        carte res;

        /* Si la liste contient un seul élément */
        if((*l)->next == NULL)
        {
            /* On le libère et on retourne NULL (la liste est maintenant vide) */
            return deck_remove_head(l);
        }

        /* Si la liste contient au moins deux éléments */
        deck tmp = *l;
        deck ptmp = *l;
        /* Tant qu'on n'est pas au dernier élément */
        while(tmp->next != NULL)
        {
            /* ptmp stock l'adresse de tmp */
            ptmp = tmp;
            /* On déplace tmp (mais ptmp garde l'ancienne valeur de tmp */
            tmp = tmp->next;
        }
        /* A la sortie de la boucle, tmp pointe sur le dernier élément, et ptmp sur
        l'avant-dernier. On indique que l'avant-dernier devient la fin de la liste
        et on supprime le dernier élément */
        ptmp->next = NULL;
        res=tmp->carte;
        free(tmp);
        return res;
    }

carte deck_remove_carte(deck *l, Nom nom){
    carte res;

    if (carte_equal((*l)->carte,nom)){
        res=deck_remove_head(l);
        return res;
    }

        /* Si la liste contient au moins deux éléments */
    deck tmp = *l;
    deck ptmp = *l;
    deck nxt= *l;
        /* Tant qu'on n'est pas au dernier élément */
    while(tmp->next != NULL && !carte_equal((tmp->carte),nom))
        {
            /* ptmp stock l'adresse de tmp */
            ptmp = tmp;
            /* On déplace tmp (mais ptmp garde l'ancienne valeur de tmp */
            tmp = tmp->next;
            nxt= tmp->next;
        }
        /* A la sortie de la boucle, tmp pointe sur le dernier élément, et ptmp sur
        l'avant-dernier. On indique que l'avant-dernier devient la fin de la liste
        et on supprime le dernier élément */
    ptmp->next = nxt;
    res=tmp->carte;
    free(tmp);
    return res;
}

carte deck_remove_indice(deck *l, int indice){
    carte res;

    if (indice==0){
        res=deck_remove_head(l);
        return res;
    }

        /* Si la liste contient au moins deux éléments */
    deck tmp = *l;
    deck ptmp = *l;
    deck nxt= *l;
    int i=0;
        /* Tant qu'on n'est pas au dernier élément */
    while(tmp->next != NULL && i!=indice)
        {
            /* ptmp stock l'adresse de tmp */
            i++;
            ptmp = tmp;
            /* On déplace tmp (mais ptmp garde l'ancienne valeur de tmp */
            tmp = tmp->next;
            nxt= tmp->next;
        }
        /* A la sortie de la boucle, tmp pointe sur le dernier élément, et ptmp sur
        l'avant-dernier. On indique que l'avant-dernier devient la fin de la liste
        et on supprime le dernier élément */
    ptmp->next = nxt;
    res=tmp->carte;
    free(tmp);
    return res;
}

void deck_concatenate(deck *l1,deck *l2){
    deck tmp = *l2;
    while(tmp != NULL){
        carte aux=deck_remove_head(&tmp);
        deck_add_last(aux,l1);
        tmp=tmp->next;
    }
}


/* modifier le deck */

void deck_addPt(deck *l,long pt, int id){
    deck tmp = *l;
    switch(id){
        case 1:
            while (tmp != NULL){
                pt_DD_change(&(tmp->carte),pt);
                tmp=tmp->next;
            }
            break;
        case 2:
            while (tmp != NULL){
                pt_Dur_change(&(tmp->carte),pt);
                tmp=tmp->next;
            }
            break;
        case 3:
            while (tmp != NULL){
                pt_nrj_change(&(tmp->carte),pt);
                tmp=tmp->next;
            }
            break;
        default:
            printf("id non reconnu\n");
   }
}


/**
\brief:  obtenir un nombre eniter aléatoirement compris entre deux entiers
\param: les deux entiers
\return:  une nombre aléatoire entier
*/
int alea (int a, int b){
    int res;
    srand(time(NULL));
    sleep(1);
    res= rand()%(b-a)+a;
    return res;
}

void melanger_deck (deck *res) {
    printf(" \n *Veuillez patienter, nous mélangeons votre deck* \n ");
    for (int i=0;i<30;i++){
        int aux=alea(0,30);
        carte caux= deck_remove_indice(res,aux);
        deck_add_last(caux,res);
        printf("-");
        fflush(stdout);
    }
    printf("\n");
}


/*parcours d'un deck*/

int deck_parcours_energie(deck l,int value){
    int res=0;
        while (l != NULL){
            res += value;
            l=l->next;
        }
    return res;
}

int deck_parcours_durabilite(deck l){
    int res=0;
        while (l != NULL){
            res=res+pt_Dur(l->carte);
            l=l->next;
        }
    return res;
}

int deck_parcours_devellopement(deck l){
    int res=0;
        while (l != NULL){
            res=res+pt_DD(l->carte);
            l=l->next;
        }
    return res;
}
