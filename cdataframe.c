#include <stdlib.h>
#include <stdio.h>
#include "column.h"
#include "cdataframe.h"
#define REALOC_SIZE 256

// Création d'un dataframe
FRAME *create_dataframe(char* title)
{
    FRAME *c = (FRAME*)malloc(sizeof(FRAME));
    c-> titre = title;
    c-> TL = 0;
    c-> TP = 0;
    c-> T = NULL;

    return c;
}


int insertion_valeur(FRAME* frame, int value){
    int nb_val;
    int num_col = -1;
    int val;
    printf("Combien de valeurs voulez-vous ajouter ?");
    scanf(" %d", &nb_val);
    do{
        printf("Dans quelle colonne voulez-vous ajouter vos valeurs ?");
        scanf(" %d", &num_col);
    }while(num_col < 0 || num_col > TL);
    if(frame[num_col] == NULL){
        ajouter_colonne(FRAME* frame);
        }
    else{
        for(int i=0; i<nb_val; i++){
            printf("Quelle valeur voulez-vous ajouter");
            scanf(" %d", &val);
            inserer_valeur(frame[num_col], val);
        }
    }
