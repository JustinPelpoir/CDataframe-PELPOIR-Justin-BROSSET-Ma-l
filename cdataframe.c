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
        insert_value(frame->col[i], val);
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

void ajouter_colonne(FRAME* frame){
    if(frame==NULL){
        return 0;
    }
    char title[50];
    int nb_val;
    printf("Quel est le titre de la colonne ?");
    scanf(" %s", title);
        COLUMN* column = create_column(title);
    if (column == NULL) {
        printf("Désolé, nous n'avons pas pu créer la colonne\n");
        return 0;
    }

    printf("Entrez le nombre de valeurs à insérer dans la colonne: ");
    scanf("%d", &nb_val);
    for (int j = 0; j < nb_val; j++) {
        int val;
        printf("Entrez la valeur pour la ligne %d: ", j + 1);
        scanf("%d", &val);
        insert_value(column, val);
    }

    frame->columns = realloc(frame->columns, (frame->num_col + 1) * sizeof(COLUMN*));
    if (cdataframe->col == NULL) {
        printf("Désolé, la réallocation de mémoire n'a pas aboutit\n");
        return 0;
    }

    frame->col[frame->num_col] = col;
    cdataframe->num_col++;
}

void print_num_raw(CDataframe* cdataframe) {
    if (cdataframe == NULL) {
        printf("ERREUR");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < cdataframe->num_columns; i++) {
        printf("Nombre de ligne de la colonne %s : %d", cdataframe->columns[i]->name, cdataframe->columns[i]->TL);
    }
}

