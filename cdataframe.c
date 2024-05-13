#include "cdataframe.h"
#include <stdlib.h>
#include <stdio.h>
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
    int num_col;
    printf("Combien de valeurs voulez-vous ajouter ?");
    
}
