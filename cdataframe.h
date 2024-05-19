

#ifndef PROJET_C_DATAFRAME_CDATAFRAME_H
#define PROJET_C_DATAFRAME_CDATAFRAME_H

// Définition d'une structure : Tableau de colonne de donnée
typedef struct{
    char *titre;
    int *T;
    int TL;
    int TP;
    int n_col;
    int n_ligne;
    int *col;
} FRAME;

FRAME *create_dataframe(char* title);



/* Insérer une valeur : la fonction demandera à l'utilisateur combien de valeurs à ajouter et dans quelle colonne
  Si la colonne demandée n'existe pas, la fonction fera appelle à la fonction "ajouter_colonne" pour la mettre en place
*/
int insertion_valeur(FRAME* frame, int value);



// Affichages :
void affichage_dataframe(FRAME* frame);
void affichage_ligne(FRAME* frame);
void affichage_colonne(FRAME* frame);



// Opérations usuelles :
void ajouter_ligne(FRAME* frame);
void ajouter_colonne(FRAME* frame);
void supprimer_ligne(FRAME** frame);
void supprimer_colonne(FRAME** frame);

void renommer_colonne(FRAME* frame);
void recherche_valeur(FRAME* frame, int valeur);

void affichage_case(FRAME* frame);
void remplacer_case(FRAME* frame);

void affichage_nom_colonne(FRAME* frame);
void affichage_nb_ligne(FRAME* frame);
void affichage_nb_colonne(FRAME* frame);

int nb_valeur_egal_frame(FRAME* frame, int valeur);
int nb_valeur_superieur_frame(FRAME* frame, int valeur);
int nb_valeur_inferieur_frame(FRAME* frame, int valeur);


#endif //PROJET_C_DATAFRAME_CDATAFRAME_H
