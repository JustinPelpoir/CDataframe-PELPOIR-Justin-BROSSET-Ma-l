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
            insert_value(frame[num_col], val);
        }
    }



void ajouter_ligne(FRAME* frame){
    for(int i=0 ; i<frame->num_col ; i++){
        int val;
        printf("Quelle valeur voulez-vous ajouter ?");
        scanf(" %d", &val);
        insertion_valeur(FRAME* frame, val);
    }
}

void supprimer_ligne(FRAME** frame){
    int n_ligne;
    do{
        printf("Quelle ligne voulez-vous supprimer ?");
        scanf(" %d", &n_ligne);
    }(while(n_ligne<0);

    for(int i=0 ; i<frame->num_col ; i++){
        if(n_ligne<frame->col[i]->TL){
            for(int j=n_ligne ; j<frame->col[i]->TL-1 ; j++){
                frame->col[i]->data[j]=frame->col[i]->data[j+1];
            }
            frame->col[i]->TL--;
        }
    }
}
