#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "column.h"
#include "cdataframe.h"
#define REALLOC_SIZE 256

/* ############################ Alimentation ############################ */

// Création d'un dataframe
FRAME* create_dataframe(char* title) {
    FRAME* c = (FRAME*)malloc(sizeof(FRAME));
    c->titre = strdup(title); // Duplique le titre pour éviter les problèmes de mémoire
    c->TL = 0; // Initialisation de la taille logique
    c->TP = 0; // Initialisation de la taille physique (nombre de colonnes)
    c->T = NULL; // Tableau des données (tableau de tableaux)
    c->num_col = NULL; // Pointeur vers les numéros de colonnes
    c->num_ligne = NULL; // Pointeur vers les numéros de lignes
    c->col = NULL;

    return c;
}

// Fonction pour insérer des valeurs dans une colonne du DataFrame
void insertion_valeur(FRAME* frame) {
    int nb_val;
    int val;
    int num_col;
    printf("Combien de valeurs voulez-vous ajouter ? ");
    scanf_s("%d", &nb_val);
    do {
        printf("Dans quelle colonne voulez-vous ajouter vos valeurs ? ");
        scanf_s("%d", &num_col);
    } while (num_col < 0 || num_col >= frame->TP); // Vérifie que la colonne existe
    if (frame->num_col == NULL || frame->TP == 0) {
        ajouter_colonne(frame); // Ajoute une colonne si aucune n'existe
    }
    for (int i = 0; i < nb_val; i++) {
        printf("Quelle valeur voulez-vous ajouter ? ");
        scanf_s("%d", &val);
        insert_value(frame->col[num_col], val); // Insère la valeur dans la colonne spécifiée
    }
}

// Fonction pour remplir le DataFrame avec des données en dur
void remplir_dataframe_en_dur(FRAME* frame) {
    // Ajouter des colonnes
    ajouter_colonne(frame);
    ajouter_colonne(frame);
    ajouter_colonne(frame);

    // Insérer des valeurs dans les colonnes
    insert_value(frame->col[0], 10);
    insert_value(frame->col[0], 20);
    insert_value(frame->col[0], 30);

    insert_value(frame->col[1], 40);
    insert_value(frame->col[1], 50);
    insert_value(frame->col[1], 60);

    insert_value(frame->col[2], 70);
    insert_value(frame->col[2], 80);
    insert_value(frame->col[2], 90);
}

/* ############################ Affichage ############################ */

// Fonction pour afficher le DataFrame
void affichage_dataframe(FRAME* frame) {
    printf("Titre: %s\n", frame->titre);
    for (int col = 0; col < frame->TP; col++) {
        printf("Colonne %d: ", col);
        for (int row = 0; row < frame->TL; row++) {
            printf("%d ", frame->T[col][row]); // Affiche les valeurs de la colonne
        }
        printf("\n");
    }
}

// Fonction pour afficher une partie des lignes du DataFrame selon une limite fournie par l’utilisateur
void affichage_ligne(FRAME* frame, int limite) {
    if (limite > frame->TL) {
        printf("La limite dépasse le nombre total de lignes disponibles.\n");
        return;
    }

    printf("Affichage des %d premières lignes :\n", limite);
    for (int i = 0; i < frame->TP; i++) {
        printf("%s\t", frame->col[i]->titre); // Affiche les titres des colonnes
    }
    printf("\n");

    for (int i = 0; i < limite; i++) {
        for (int j = 0; j < frame->TP; j++) {
            if ((i < frame->TL) && (frame->T[j] != NULL)) {
                printf("%d\t", frame->T[j][i]); // Affiche les valeurs de chaque ligne jusqu'à la limite
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}

// Fonction pour afficher une partie des colonnes du DataFrame selon une limite fournie par l’utilisateur
void affichage_colonne(FRAME* frame, int limite) {
    if (limite > frame->TP) {
        printf("La limite dépasse le nombre total de colonnes disponibles.\n");
        return;
    }

    printf("Affichage des %d premières colonnes :\n", limite);
    for (int i = 0; i < limite; i++) {
        printf("Colonne %d (%s) :\n", i, frame->col[i]->titre); // Affiche le titre de chaque colonne
        print_col(frame->col[i]); // Affiche les valeurs de la colonne
    }
}

/* ############################ Opérations Usuelles ############################ */

// Fonction pour ajouter une ligne au DataFrame
void ajouter_ligne(FRAME* frame) {
    for (int i = 0; i < frame->TP; i++) {
        int val;
        printf("Quelle valeur voulez-vous ajouter ?");
        scanf_s("%d", &val);
        insert_value(frame->col[i], val); // Insère la valeur dans chaque colonne
    }
}

// Fonction pour supprimer une ligne du DataFrame
void supprimer_ligne(FRAME* frame) {
    int n_ligne;
    do {
        printf("Quelle ligne voulez-vous supprimer ?");
        scanf_s("%d", &n_ligne);
    } while (n_ligne < 0);

    for (int i = 0; i < frame->TP; i++) {
        if (n_ligne < frame->col[i]->TL) {
            for (int j = n_ligne; j < frame->col[i]->TL - 1; j++) {
                frame->col[i]->data[j] = frame->col[i]->data[j + 1]; // Décale les valeurs pour supprimer la ligne
            }
            frame->col[i]->TL--; // Décrémente la taille logique
        }
    }
}

// Fonction pour ajouter une colonne au DataFrame
void ajouter_colonne(FRAME* frame) {
    if (frame == NULL) {
        return;
    }
    char title[50];
    int nb_val;
    printf("Quel est le titre de la colonne ?");
    scanf("%s", title);
    COLUMN* col = create_column(title); // Crée une nouvelle colonne
    if (col == NULL) {
        printf("Désolé, nous n'avons pas pu créer la colonne\n");
        return;
    }

    printf("Entrez le nombre de valeurs à insérer dans la colonne: ");
    scanf_s("%d", &nb_val);
    for (int j = 0; j < nb_val; j++) {
        int val;
        printf("Entrez la valeur pour la ligne %d: ", j + 1);
        scanf_s("%d", &val);
        insert_value(col, val); // Insère les valeurs dans la nouvelle colonne
    }

    frame->col = realloc(frame->col, (frame->TP + 1) * sizeof(COLUMN*)); // Réalloue de la mémoire pour ajouter la nouvelle colonne
    if (frame->col == NULL) {
        printf("Désolé, la réallocation de mémoire n'a pas abouti\n");
        return;
    }

    frame->col[frame->TP] = col; // Ajoute la nouvelle colonne au DataFrame
    frame->TP++; // Incrémente le nombre de colonnes
}

// Fonction pour supprimer une colonne du DataFrame
void supprimer_colonne(FRAME* frame) {
    int n_col;
    do {
        printf("Quel est le numéro de la colonne à supprimer ? ");
        scanf_s("%d", &n_col);
    } while (n_col < 0);

    if (frame == NULL || n_col < 0) {
        return;
    } else if (n_col >= frame->TP) {
        printf("Désolé, colonne non trouvée\n");
        return;
    }

    delete_column(&(frame->col[n_col])); // Libère la mémoire allouée pour la colonne

    for (int i = n_col; i < frame->TP - 1; i++) {
        frame->col[i] = frame->col[i + 1]; // Décale les colonnes pour supprimer celle spécifiée
    }
    frame->TP--; // Décrémente le nombre de colonnes
}
