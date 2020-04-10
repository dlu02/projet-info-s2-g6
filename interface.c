#include "interface.h"
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_new_tour(plateau p){
	printf("Tour %i commencé\n",p->tour);
}

void print_new_phase(char c){
	if (c=='A'){
		printf("C'est au tour de l'ENSIIE A de jouer\n");
	}
	else{
		printf("C'est au tour de l'ENSIIE B de jouer\n")
	}
}

void print_plateau(plateau p){
	printf("Tour %i\n",p->tour);
	printf("Nombre de points DD pour l'ENSIIE A : %i\n",p->ddA);
	printf("Nombre de points DD pour l'ENSIIE B : %i\n",p->ddB);
	printf("Nombre de points énergie pour l'ENSIIE A: %i\n",count_PE_A(p));
	printf("Nombre de points énergie pour l'ENSIIE B: %i\n",count_PE_A(p));
	printf("Nombre de cartes pour l'ENSIIE A : %i\n",p->nbcarteA);
	printf("Nombre de cartes pour l'ENSIIE B : %i\n",p->nbcarteB);
	printf("Deck de l'ENSIIE A : \n");
	deck_print(p->deckA);
	printf("Deck de l'ENSIIE B : \n");
	deck_print(p->deckB);
}

char *ask_carte_ou_fin_A(plateau p){ //pour ENSIIE A
	deck m=p->deckA;
	deck n=p->deckA;
	while (m!=NULL){
		if (cout(m->carte)>(p->peA)){ //peX est le nombre de points d'énergie de l'ENSIIE X
			deck_remove_carte(&n,getNom(m->carte));
		}
		m=m->next;
	}
	printf("Votre choix de cartes possibles est : \n");
	deck_print(n);
	if (n==NULL){
		printf("Vous ne pouvez que finir la phase. \n");
		return "fin_phase";
	}
	else{
		char buf[256];
		char string[256];
		printf("Choisissez une carte parmi le choix possible : ");
		fgets(buf, 256, stdin);
		sscanf(buf,"%s",string);
		while (n!=NULL){
			if (strcmp(string,getNom(n->carte))==0){
				return ((string) getNom(n->carte));
			}
			n=n->next;
		}
	}
}

char *ask_carte_ou_fin_B(plateau p){ //pour ENSIIE B
	deck m=p->deckB;
	deck n=p->deckB;
	while (m!=NULL){
		if (cout(m->carte)>(p->peB)){ //peX est le nombre de points d'énergie de l'ENSIIE X
			deck_remove_carte(&n,getNom(m->carte));
		}
		m=m->next;
	}
	printf("Votre choix de cartes possibles est : \n");
	deck_print(n);
	if (n==NULL){
		printf("Vous ne pouvez que finir la phase. \n");
		return "fin_phase";
	}
	else{
		char buf[256];
		char string[256];
		printf("Choisissez une carte parmi le choix possible : ");
		fgets(buf, 256, stdin);
		sscanf(buf,"%s",string);
		while (n!=NULL){
			if (strcmp(string,getNom(n->carte))==0){
				return ((string) getNom(n->carte));
			}
			n=n->next;
		}
	}
}

void print_win_player(plateau p){
	if ((p->tour)<30){
		if ((p->ddA) >= 20){
			if ((p->ddB) >= 20){
				if ((p->ddA)>(p->ddB)){
					printf("L'ENSIIE A a gagné !");
				}
				else{
					printf("L'ENSIIE B a gagné !");
				}
			}
			else{
				printf("L'ENSIIE A a gagné !");
			}
		}
		else{
			if ((p->ddB)>=20){
				printf("L'ENSIIE B a gagné !");
			}
			else{
				if ((p->ddB)>(p->ddA)){
					printf("L'ENSIIE B a gagné !");
				}
				else{
					printf("L'ENSIIE A a gagné !");
				}
			}
		}
	}
	else{
		printf("Partie nulle !");
	}
}

Nom ajout_fise_fisa(){
	Nom nom;
	while (1){
		char buf[256];
		char string[256];
		printf("Voulez-vous tirer une carte FISE ou FISA ? Répondre fise ou fisa : ");
		fgets(buf, 256, stdin);
		sscanf(buf,"%s",string);
		if (strcmp(string,"fise")==0){
			nom=Fise;
			return nom;
		}
		if (strcmp(string,"fisa")==0){
			nom=Fisa;
			return nom;
		}
	}
}

int count_PE_A(plateau p){  //permet de compter les points énergie du joueur A sur le plateau p
	int i=0;
	while ((p->deckA)->next!=NULL){
		i=i+pt_nrj((p->deckA)->carte);
		p->deckA=(p->deckA)->next;
	}
	return i;
}

int count_PE_B(plateau p){  //permet de compter les points énergie du joueur A sur le plateau p
	int i=0;
	while ((p->deckB)->next!=NULL){
		i=i+pt_nrj((p->deckB)->carte);
		p->deckB=(p->deckB)->next;
	}
	return i;
}

