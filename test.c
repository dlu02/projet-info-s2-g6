//
//  test.c
//  
//
//  Created by Loirs Romain on 24/03/2020.
//

#include "carte.h"
#include "structure.h"
#include <stdio.h>

int main(){
   
    carte c=carte_new(0);
    carte_print(c);
    pt_DD_change(&c,100);
    carte_print(c);
    pt_DD_change(&c,-200);
    carte_print(c);
    
    /*
    printf("création de cartes");
    deck l= deck_create();
    carte carteF= carte_new(0);
    carte carteG= carte_new(3);
    carte carteH= carte_new(28);
    carte_print(carteF);
    carte_print(carteG);
    carte_print(carteH);
    
    pt_Dur_change(&carteF,3);
    
    deck_add_last(carteF,&l);
    deck_add_last(carteG,&l);
    deck_add_last(carteH,&l);
    
    printf("la  liste\n");
    deck_print(l);
    
    carte delete1= deck_remove_head(&l);
    carte delete2= deck_remove_head(&l);
    carte delete3= deck_remove_head(&l);
    
    
    printf("les éléments enlevés un par un \n");
    carte_print(delete1);
    carte_print(delete2);
    carte_print(delete3);
    printf("la nouvelle liste qui doit être vide\n");
    deck_print(l);
     
    
    
    int i;
    for (i=0;i<33;i++){
        carte carte= carte_new(i);
        carte_print(carte);
    }*/
    
  return 0;
}
