
#ifndef PROJET_C_DATAFRAME_CDATAFRAME_H
#define PROJET_C_DATAFRAME_CDATAFRAME_H

// Définition d'une structure : Tableau de colonne de donnée
typedef struct{
    char* titre;
    int** T;
    int TL;
    int TP;
    int* num_col;
    int* num_ligne;
    COLUMN **col;
} FRAME;

// Alimentation :
FRAME* create_dataframe(char* title);
void insertion_valeur(FRAME* frame);
void remplir_dataframe_en_dur(FRAME* frame);


// Affichages :
void affichage_dataframe(FRAME* frame);
void affichage_ligne(FRAME* frame, int limite);
void affichage_colonne(FRAME* frame, int limite);


// Opérations usuelles :
void ajouter_ligne(FRAME* frame);
void ajouter_colonne(FRAME* frame);
void supprimer_ligne(FRAME* frame);
void supprimer_colonne(FRAME* frame);

void renommer_colonne(FRAME* frame, int col, const char* nouveau_nom);
void recherche_valeur(FRAME* frame, int valeur);

void affichage_case(FRAME* frame, int col, int row);
void remplacer_case(FRAME* frame, int col, int row, int val);

void affichage_noms_colonnes(FRAME* frame);
void affichage_nb_ligne(FRAME* frame);
void affichage_nb_colonne(FRAME* frame);

int nb_valeur_egal_frame(FRAME* frame, int valeur);
int nb_valeur_superieur_frame(FRAME* frame, int valeur);
int nb_valeur_inferieur_frame(FRAME* frame, int valeur);


#endif //PROJET_C_DATAFRAME_CDATAFRAME_H
