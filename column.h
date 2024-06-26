//
// Created by maelb on 21/05/2024.
//

#ifndef CDATAFRAME_COLUMN_H
#define CDATAFRAME_COLUMN_H


// Définition d'une structure : Colonne de donnée
typedef struct{
    char *titre;
    int *T;
    int* data;
    int TL;
    int TP;
} COLUMN;

COLUMN *create_column(char* title);

int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);

int occurence_colonne(COLUMN* col, int value);

int valeur_position(COLUMN *col, int position);
int valeurs_superieures(COLUMN* col, int valeur);
int valeurs_inferieures(COLUMN *col, int valeur);
int valeurs_egales(COLUMN *col, int valeur);


#endif //CDATAFRAME_COLUMN_H
