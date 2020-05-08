#include "interface.h"
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"time.h"
#include <unistd.h>

void print_new_tour(plateau p){
	printf("\n---------------------------------------------------------------------------------\n");
	printf("\t\t\t\tTour %i commencé\n",p.tour);
	printf("---------------------------------------------------------------------------------\n\n");
	sleep(2);
}

void print_new_phase( char c){
	if (c=='A') {
		printf("\n\n C'est au tour de l'ENSIIE A de jouer\n\n");
		printf("---------------------------------------------------------------------------------\n\n");
		sleep(2);
	}
	else {
		printf("\n\nC'est au tour de l'ENSIIE B de jouer\n\n");
		printf("---------------------------------------------------------------------------------\n\n");
        sleep(2);
	}
}

void print_points_DD(plateau p){
	printf("Nombre de points DD pour l'ENSIIE A : %i\n",p.ddA);
	printf("Nombre de points DD pour l'ENSIIE B : %i\n\n",p.ddB);
}

void print_plateau(plateau p){

	if(p.debutEnsiie == 'A') {
		printf("Nombre de cartes dans la main de l'ENSIIE A : %i\n",p.nbcarteA);
		printf("Nombre de points d'énergie pour l'ENSIIE A: %i\n\n",p.nrjA);
        if((p.tour)%2==1) {
            printf("Pile FISA de l'ENSIIE A : \n");
            deck_print(p.pileFisaA);
        }
		printf("Pile FISE de l'ENSIIE A : \n");
		deck_print(p.pileFiseA);
		printf("\n");
		printf("Cartes en jeu de l'ENSIIE A : \n");
		deck_print(p.sideA);
		printf("Cartes en jeu de l'ENSIIE B : \n");
		deck_print(p.sideB);
		printf("\n");
		printf("Main de l'ENSIIE A : \n");
		deck_print(p.mainA);
	}
	else {
		printf("Nombre de cartes dans la main de l'ENSIIE B : %i\n",p.nbcarteB);
		printf("Nombre de points d'énergie pour l'ENSIIE B: %i\n\n",p.nrjB);
        if((p.tour)%2==1) {
            printf("Pile FISA de l'ENSIIE B : \n");
            deck_print(p.pileFisaB);
        }
		printf("Pile FISE de l'ENSIIE B : \n");
		deck_print(p.pileFiseB);
		printf("\n");
		printf("Cartes en jeu de l'ENSIIE A : \n");
		deck_print(p.sideA);
		printf("Cartes en jeu de l'ENSIIE B : \n");
		deck_print(p.sideB);
		printf("\n");
		printf("Main de l'ENSIIE B : \n");
		deck_print(p.mainB);
	}

}

int ask_carte_ou_fin(plateau p,char c) {
	if (c=='A'){  //cas ENSIIE A
		deck m=p.mainA;
		deck res=deck_create();   //création du deck des choix possibles
		while (m!=NULL) {
			if (cout(m->carte)<=(p.nrjA)){
				deck_add_last(m->carte,&res); //chaque carte ayant un PE < à celui du joueur est ajoutée dans le deck
			}
			m=m->next;
		}
		if (res==NULL) {  // si aucune carte n'est dans le deck des choix possibles
			print_plateau(p);
			printf("Vous ne pouvez que finir la phase car vous n'avez que %d PE  !!! . \n\n",p.nrjA);
			return -1;
		}
		else{  //si il y a au moins une carte dans le deck des choix possibles
			printf("Vous avez %d PE, votre choix de cartes possible est donc : \n",p.nrjA);
			deck_print(res);  //affichage de ce deck
			while (1) {
				char buf[256];
				int n;
				printf("Choisissez un numéro de carte parmi le choix possible.\n");
				printf("Si vous ne voulez pas jouer de carte, saisir -1. Votre choix : ");
				fgets(buf, 256, stdin);  //récupération de la saisie de l'utilisateur
				int ask=sscanf(buf,"%d",&n);  //analyse en entier
				if (ask==1) {  //si la saisie est un entier
					if (n==-1) {  //cas ou le joueur veut finir la phase
						return -1;
					}
					if ((n>=0) && (n<deck_length(res))){  //cas où le numéro saisi est bien valable
						int i=0;
						while (res!=NULL){  //recherche de la carte numéro n dans le deck des choix possibles, qui doit forcément y être présente de par les vérifications effectuées
							if (i==n){
								return getNom(res->carte); //on retourne la carte trouvée
							}
							res=res->next;
							i=i+1;
						}
					}
					else {
						printf("Choix incorrect, veuillez recommencer.\n");  //cas où le numéro saisi est invalide
					}
				}
				else {
					printf("Problème de saisie, veuillez recommencer.\n");  //cas où la saisie ne s'est pas bien passée (pb de type typiquement)
				}
			}
		}
	}
	else { //cas ENSIIE B
		deck m=p.mainB;
		deck res=deck_create();   //création du deck des choix possibles
		while (m!=NULL) {
			if (cout(m->carte)<=(p.nrjB)){
				deck_add_last(m->carte,&res); //chaque carte ayant un PE < à celui du joueur est ajoutée dans le deck
			}
			m=m->next;
		}
		if (res==NULL) {  // si aucune carte n'est dans le deck des choix possibles
			print_plateau(p);
			printf("Vous ne pouvez que finir la phase car vous n'avez que %d PE  !!! . \n\n",p.nrjB);
			return -1;
		}
		else{  //si il y a au moins une carte dans le deck des choix possibles
			printf("Vous avez %d PE, votre choix de cartes possible est donc : \n",p.nrjB);
			deck_print(res);  //affichage de ce deck
			while (1) {
				char buf[256];
				int n;
				printf("Choisissez un numéro de carte parmi le choix possible.\n");
				printf("Si vous ne voulez pas jouer de carte, saisir -1. Votre choix : ");
				fgets(buf, 256, stdin);  //récupération de la saisie de l'utilisateur
				int ask=sscanf(buf,"%d",&n);  //analyse en entier
				if (ask==1) {  //si la saisie est un entier
					if (n==-1) {  //cas ou le joueur veut finir la phase
						return -1;
					}
					if ((n>=0) && (n<deck_length(res))){  //cas où le numéro saisi est bien valable
						int i=0;
						while (res!=NULL){  //recherche de la carte numéro n dans le deck des choix possibles, qui doit forcément y être présente de par les vérifications effectuées
							if (i==n){
								return getNom(res->carte); //on retourne la carte trouvée
							}
							res=res->next;
							i=i+1;
						}
					}
					else {
						printf("Choix incorrect, veuillez recommencer.\n");  //cas où le numéro saisi est invalide
					}
				}
				else {
					printf("Problème de saisie, veuillez recommencer.\n");  //cas où la saisie ne s'est pas bien passée (pb de type typiquement)
				}
			}
		}
	}
}

void print_win_player(plateau p){  //retourne le gagnant du jeu selon les conditions
	if ((p.tour)<30){
		if ((p.ddA) >= 20){
			if ((p.ddB) >= 20){
				if ((p.ddA)>(p.ddB)){
					printf("L'ENSIIE A a gagné ! \n\n");
				}
				else{
					printf("L'ENSIIE B a gagné !\n\n");
				}
			}
			else{
				printf("L'ENSIIE A a gagné !\n\n");
			}
		}
		else{
			if ((p.ddB)>=20){
				printf("L'ENSIIE B a gagné !\n\n");
			}
			else{
				if ((p.ddB)>(p.ddA)){
					printf("L'ENSIIE B a gagné !\n\n");
				}
				else{
					printf("L'ENSIIE A a gagné !\n\n");
				}
			}
		}
	}
	else{
		printf("Partie nulle !\n\n");
	}
}

Nom ajout_fise_fisa(){
	Nom nom;
	while (1){
		char buf[256];
		char string[256]; //variable contenant la saisie de l'utilisateur
		printf("Voulez-vous tirer une carte FISE ou FISA ? Répondre fise ou fisa : ");
		fgets(buf, 256, stdin);  //récupération de la saisie de l'utilisateur
		int stat=sscanf(buf,"%s",string);  //analyse de la saisie de l'utilisateur en string
		if (stat==1){ //si cela se passe bien (si la saisie est bien un string)
			if (strcmp(string,"fise")==0 || strcmp(string,"FISE")==0){ //si la saisie est "fise" ou "FISE"
				nom=Fise;
				return nom;  //on retourne le nom Fise
			}
			if (strcmp(string,"fisa")==0 || strcmp(string,"FISA")==0){  //si la saisie est "fisa" ou "FISA"
				nom=Fisa;
				return nom; //on retourne le nom Fisa
			}
			printf("Saisie incorrecte, veuillez recommencer. \n"); //sinon toute autre saisie est incorrecte
		}
		else {
			printf("Problème de saisie, veuillez recommencer. \n");  //cas où la saisie n'est pas un string
		}
		printf("\n");
	}
}
