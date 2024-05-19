#include <stdlib.h>
#include <stdio.h>
#include "column.h"
#include "cdataframe.h"
#define REALOC_SIZE 256

// Création d'un dataframe
FRAME* create_dataframe(char* title) {
    FRAME* c = (FRAME*)malloc(sizeof(FRAME));
    c->titre = strdup(title); // Duplique le titre pour éviter les problèmes de mémoire
    c->TL = 0;
    c->TP = 0;
    c->T = NULL;
    c->num_col = NULL;
    c->num_ligne = NULL;

    return c;
}


// Fonction pour insérer des valeurs dans une colonne du DataFrame
void insertion_valeur(FRAME* frame) {
    int nb_val;
    int val;
    int num_col;
    printf("Combien de valeurs voulez-vous ajouter ? ");
    scanf("%d", &nb_val);
    do {
        printf("Dans quelle colonne voulez-vous ajouter vos valeurs ? ");
        scanf("%d", &num_col);
    } while (num_col < 0 || num_col >= frame->TP);
    if (frame->num_col == NULL || frame->TP == 0) {
        ajouter_colonne(frame);
    }
    for (int i = 0; i < nb_val; i++) {
        printf("Quelle valeur voulez-vous ajouter ? ");
        scanf("%d", &val);
        insert_value(frame, num_col, val);
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
    COLUMN* col = create_column(title);
    if (col == NULL) {
        printf("Désolé, nous n'avons pas pu créer la colonne\n");
        return 0;
    }

    printf("Entrez le nombre de valeurs à insérer dans la colonne: ");
    scanf("%d", &nb_val);
    for (int j = 0; j < nb_val; j++) {
        int val;
        printf("Entrez la valeur pour la ligne %d: ", j + 1);
        scanf("%d", &val);
        insert_value(col, val);
    }

    frame->col = realloc(frame->col, (frame->num_col + 1) * sizeof(COLUMN*));
    if (frame->col == NULL) {
        printf("Désolé, la réallocation de mémoire n'a pas aboutit\n");
        return 0;
    }

    frame->col[frame->num_col] = col;
    frame->num_col++;
}

void delete_column(FRAME* frame) {
    int n_col;
    do {
        printf("Quel est le numero de la colonne à supprimer ? ");
        scanf("%d", &n_col);
    } while (n_col < 0);

    if (frame == NULL || n_col < 0) {
        return 0;
    } else if (n_col >= frame->num_col) {
        printf("Désolé, colonne non trouvé");
        return 0;
    }

    // Libérer la mémoire allouée pour la colonne à l'index spécifié
    delete_column(&(frame->col[n_col]));

    // Décaler les colonnes restantes vers la gauche pour remplir l'espace laissé par la suppression
    for (int i = n_col; i < frame->num_col - 1; i++) {
        frame->col[i] = frame->col[i + 1];
    }

    // Réduire le nombre de colonnes dans le dataframe
    frame->num_col--;
}

void affichage_nb_ligne(FRAME* frame) {
    if (frame == NULL) {
        return 0;
    }

    for (int i = 0; i < frame->num_col; i++) {
        printf("Il y a %d lignes dans cette colonne.", frame->col[i]->TL);
    }
}

int nb_valeur_inferieur_frame(FRAME* frame, int valeur){
    int ct=0;
    if(frame==NULL){
        return 0;
    }
    for(int i=0 ; i<frame->num_col ; i++){
        ct+=valeurs_inferieures(frame->col[i], valeur);
    }
}
