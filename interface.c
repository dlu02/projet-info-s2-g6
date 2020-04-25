#include "interface.h"
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_new_tour(plateau p){
	printf("Tour %i commencé\n",p.tour);
}

void print_new_phase(char c){
	if (c=='A'){
		printf("C'est au tour de l'ENSIIE A de jouer\n");
	}
	else{
		printf("C'est au tour de l'ENSIIE B de jouer\n");
	}
}

void print_plateau(plateau p){
	//printf("Tour %i\n",p.tour);
	//printf("Nombre de points DD pour l'ENSIIE A : %i\n",p.ddA);
	//printf("Nombre de points DD pour l'ENSIIE B : %i\n",p.ddB);

	if(p.debutEnsiie == 'A') {
		printf("Nombre de cartes dans la main de l'ENSIIE A : %i\n",p.nbcarteA);
		//printf("Nombre de points énergie pour l'ENSIIE A: %i\n",p.nrjA);
		printf("Main de l'ENSIIE A : \n");
		deck_print(p.mainA);
	}
	else {
		printf("Nombre de cartes dans la main de l'ENSIIE B : %i\n",p.nbcarteB);
		//printf("Nombre de points énergie pour l'ENSIIE B: %i\n",p.nrjB);
		printf("Main de l'ENSIIE B : \n");
		deck_print(p.mainB);
	}
}

int ask_carte_ou_fin(plateau p,char c){
	if (c=='A'){
		deck m=p.mainA;
		deck res=deck_create();
		while (m!=NULL){
			if (cout(m->carte)>(p.EA)){
				deck_add_last(m->carte,&res);
			}
			m=m->next;
		}
		if (res==NULL){
			printf("Vous ne pouvez que finir la phase. \n");
			return -1;
		}
		else{
			printf("Votre choix de cartes possibles est : \n");
			deck_print(res);
			while (1){
				int n;
				printf("Choisissez un numéro de carte parmi le choix possible.\n");
				printf("Si vous ne voulez pas jouer de carte, saisir -1. Votre choix : ");
				int ask=scanf("%d",&n);
				if (ask==1){
					if (n==-1){
						return -1;
					}
					if ((n>=0) && (n<deck_length(res))){
						int i=0;
						while (res!=NULL){
							if (i==n){
								return getNom(res->carte);
							}
							res=res->next;
							i=i+1;
						}
					}
					else{
						printf("Choix incorrect, veuillez recommencer.\n");
					}
				}
				else{
					printf("Problème de saisie, veuillez recommencer.\n");
				}
			}
		}
	}
	else{
		deck m=p.mainB;
		deck res=deck_create();
		while (m!=NULL){
			if (cout(m->carte)>(p.EB)){
				deck_add_last(m->carte,&res);
			}
			m=m->next;
		}
		if (res==NULL){
			printf("Vous ne pouvez que finir la phase. \n");
			return -1;
		}
		else{
			printf("Votre choix de cartes possibles est : \n");
			deck_print(res);
			while (1){
				int n;
				printf("Choisissez un numéro de carte parmi le choix possible.\n");
				printf("Si vous ne voulez pas jouer de carte, saisir -1. Votre choix : ");
				int ask=scanf("%d",&n);
				if (ask==1){
					if (n==-1){
						return -1;
					}
					if ((n>=0) && (n<deck_length(res))){
						int i=0;
						while (res!=NULL){
							if (i==n){
								return getNom(res->carte);
							}
							res=res->next;
							i=i+1;
						}
					}
					else{
						printf("Choix incorrect, veuillez recommencer.\n");
					}
				}
				else{
					printf("Problème de saisie, veuillez recommencer.\n");
				}
			}
		}
	}
}

void print_win_player(plateau p){
	if ((p.tour)<30){
		if ((p.ddA) >= 20){
			if ((p.ddB) >= 20){
				if ((p.ddA)>(p.ddB)){
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
			if ((p.ddB)>=20){
				printf("L'ENSIIE B a gagné !");
			}
			else{
				if ((p.ddB)>(p.ddA)){
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
		printf("\n");
	}
}

