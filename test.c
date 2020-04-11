//
//  test.c
//  
//
//  Created by Loirs Romain on 24/03/2020.
//

#include "carte.h"
#include "structure.h"
#include "plateau.h"
#include <stdio.h>

int main(){
   
    /*
    carte c=carte_new(0);
    carte_print(c);
    pt_DD_change(&c,100);
    carte_print(c);
    pt_DD_change(&c,-200);
    carte_print(c);
    
    
    printf("création de cartes\n");
    deck l= deck_create();
    carte carteF= carte_new(0);
    carte carteG= carte_new(3);
    carte carteH= carte_new(28);
    pt_Dur_change(&carteF,3);
    
    deck_add_last(carteG,&l);
    deck_add_last(carteF,&l);
    deck_add_last(carteH,&l);
    
    printf("is in the deck %i\n",deck_length(l));
    
    printf("le deck\n");
    deck_print(l);
    
    
    carte delete1= deck_remove_queue(&l);
    carte delete2= deck_remove_queue(&l);
    carte delete3= deck_remove_queue(&l);
    
    
    printf("l'élément enlevé \n");
    carte delete1= deck_remove_indice(&l,2);
    carte_print(delete1);
    carte_print(delete2);
    carte_print(delete3);
    
    printf("la nouvelle liste qui doit être vide\n");
    deck_print(l);*/
     
    plateau p=new_plateau();
    deck_print(p.deckA);
    
    
    

    /*deck_print(new.deckB);
    deck_print( new.mainA);*/
    
    /*int i;
    for (i=0;i<33;i++){
        carte carte= carte_new(i);
        carte_print(carte);
    }*/
    
  return 0;
}
