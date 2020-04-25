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
		deck m=p.deckA;
		deck n=p.deckA;
		while (m!=NULL){
			if (cout(m->carte)>(p.EA)){
				deck_remove_carte(&n,getNom(m->carte));
			}
			m=m->next;
		}
		if (n==NULL){
			printf("Vous ne pouvez que finir la phase. \n");
			return -1;
		}
		else{
			printf("Votre choix de cartes possibles est : \n");
			deck_print(n);
			while (1){
				int carte_choisie;
				printf("Choisissez un numéro de carte parmi le choix possible : ");
				int ask=scanf("%d",&carte_choisie);
				if (ask==1){
					if (deck_carteIn(n,carte_choisie)==1){
						int i=0;
						while (n!=NULL){
							if (i==carte_choisie){
								return getNom(n->carte);
							}
							n=n->next;
							i=i+1;
						}
					}
					else{
						printf("Choix incorrect, veuillez recommencer");
					}
				}
				else{
					printf("Problème de saisie, veuillez recommencer.");
				}
			}
		}
	}
	else{
		deck m=p.deckB;
		deck n=p.deckB;
		while (m!=NULL){
			if (cout(m->carte)>(p.EB)){
				deck_remove_carte(&n,getNom(m->carte));
			}
			m=m->next;
		}
		if (n==NULL){
			printf("Vous ne pouvez que finir la phase. \n");
			return -1;
		}
		else{
			printf("Votre choix de cartes possibles est : \n");
			deck_print(n);
			while (1){
				int carte_choisie;
				printf("Choisissez un numéro de carte parmi le choix possible : ");
				int ask=scanf("%d",&carte_choisie);
				if (ask==1){
					if (deck_carteIn(n,carte_choisie)==1){
						int i=0;
						while (n!=NULL){
							if (i==carte_choisie){
								return getNom(n->carte);
							}
							n=n->next;
							i=i+1;
						}
					}
					else{
						printf("Choix incorrect, veuillez recommencer");
					}
				}
				else{
					printf("Problème de saisie, veuillez recommencer.");
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
	}
}

