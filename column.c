

#include "column.h"
#include <stdlib.h>
#include <stdio.h>
#define REALOC_SIZE 256

// Création d'une colonnne de donnée
COLUMN *create_column(char* title)
{
    COLUMN *c = (COLUMN*)malloc(sizeof(COLUMN));
    c-> titre = title;
    c-> TL = 0;
    c-> TP = 0;
    c-> T = NULL;

    return c;
}


// Insertion d'une valeur dans une colonne
int insert_value(COLUMN* col, int value)
{
    if(col-> TP == col-> TL)  // Cas où il n'y a pas d'espace disponible dans le tableau : Allocation de cases supplémentaires
    {

        if(col-> T == NULL)  // Tableau inexistant : allocation initiale
            col-> T = (int*) malloc(REALOC_SIZE * sizeof(int));
        else
        {
            // Tableau existant mais pas d'espace libre : réallocation
            col-> T = (int*) realloc(col-> T, (col-> TP + REALOC_SIZE)*sizeof(int));

            // Si la réallocation de mémoire échoue
            if(col-> T == NULL)
                return 0;
        }
    }

    // Ajout de la valeur dans le tableau
    col-> T[col-> TL] = value;
    col->TL++;

    return 1;
}


// Supprimer une colonne : libérer l'espace allouée à une colonne et son tableau de valeur
void delete_column(COLUMN **col)
{
    free((*col)-> T);
    free((*col)-> titre);
    free(*col);

}


// Afficher le contenu d'une colonne
void print_col(COLUMN* col)
{
    // Si la Taille Logique vaut 0 -> si la colonne est vide
    if(col-> TL == 0)
        printf("La colonne %s est vide", col->titre);

    // Si la colonne n'est pas vide -> affichage une par une des valeurs
    else
        for(int i=0; i < col-> TL; i++)
        {
            printf("[%d]  %d \n", i, col-> T[i]);
        }
}


// Trouver le nb d'occurrences d'une valeur en paramètre dans une colonne
int occurence_colonne(COLUMN* col, int value)
{
    int occurrence=0;  // Compte les occurrences

    for(int i=0; i < col-> TL; i++)
    {
        // Pour chaque case non vide de la colonne, si la valeur est égale à la valeur recherchée -> incrémentation
        if(col-> T[i] == value)
            occurrence++;
    }

    return occurrence;
}


// Trouver la valeur à une position donnée en paramètre dans une colonne
int valeur_position(COLUMN *col, int position)
{
    int valeur;

    // Si la position donnée est plus grande que la taille de la colonne -> cette position n'existe pas : pas de valeur
    if (position >= col->TL)
        printf("Cette position n'existe pas");

    // La position existe dans la colonne : extraire la valeur à cette position dans la colonne
    else
    {
        valeur = col-> T[position];
    }

    return valeur;
}


// Trouver le nombre de valeurs supérieures à une valeur donnée en paramètre
int valeurs_superieures(COLUMN *col, int valeur)
{
    int nb=0;  // Compte le nb de valeurs supérieures à celle en paramètre

    for(int i=0; i < col-> TL; i++)
    {
        // Pour chaque case non vide de la colonne, si la valeur est supérieure à la valeur recherchée -> incrémentation
        if(col-> T[i] > valeur)
            nb++;
    }

    return nb;
}


// Trouver le nombre de valeurs inférieures à une valeur donnée en paramètre
int valeurs_inferieures(COLUMN *col, int valeur)
{
    int nb=0;  // Compte le nb de valeurs inférieures à celle en paramètre

    for(int i=0; i < col-> TL; i++)
    {
        // Pour chaque case non vide de la colonne, si la valeur est inférieure à la valeur recherchée -> incrémentation
        if(col-> T[i] < valeur)
            nb++;
    }

    return nb;
}


// Trouver le nombre de valeurs égales à une valeur donnée en paramètre
int valeurs_egales(COLUMN *col, int valeur)
{
    int nb=0;  // Compte le nb de valeurs égales à celle en paramètre

    for(int i=0; i < col-> TL; i++)
    {
        // Pour chaque case non vide de la colonne, si la valeur est égale à la valeur recherchée -> incrémentation
        if(col-> T[i] == valeur)
            nb++;
    }

    return nb;
}
