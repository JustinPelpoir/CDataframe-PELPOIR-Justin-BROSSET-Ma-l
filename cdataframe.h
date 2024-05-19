

#ifndef PROJET_C_DATAFRAME_CDATAFRAME_H
#define PROJET_C_DATAFRAME_CDATAFRAME_H

// Définition d'une structure : Tableau de colonne de donnée
typedef struct{
    char *titre;
    int *T;
    int TL;
    int TP;
    int *num_col;
    int *num_ligne;
} FRAME;

FRAME *create_dataframe(char* title);



/* Insérer une valeur : la fonction demandera à l'utilisateur combien de valeurs à ajouter et dans quelle colonne
  Si la colonne demandée n'existe pas, la fonction fera appelle à la fonction "ajouter_colonne" pour la mettre en place
*/
int insertion_valeur(FRAME* frame, int value);



// Affichages :
void affichage_dataframe(FRAME* frame); // A faire
void affichage_ligne(FRAME* frame);// A faire
void affichage_colonne(FRAME* frame);// A faire



// Opérations usuelles :
void ajouter_ligne(FRAME* frame);
void ajouter_colonne(FRAME* frame);
void supprimer_ligne(FRAME** frame);
void supprimer_colonne(FRAME** frame);// A faire

void renommer_colonne(FRAME* frame);// A faire
void recherche_valeur(FRAME* frame, int valeur);// A faire

void affichage_case(FRAME* frame);// A faire
void remplacer_case(FRAME* frame);// A faire

void affichage_nom_colonne(FRAME* frame);// A faire
void affichage_nb_ligne(FRAME* frame);
void affichage_nb_colonne(FRAME* frame);// A faire

int nb_valeur_egal_frame(FRAME* frame, int valeur);// A faire
int nb_valeur_superieur_frame(FRAME* frame, int valeur);// A faire
int nb_valeur_inferieur_frame(FRAME* frame, int valeur);


#endif //PROJET_C_DATAFRAME_CDATAFRAME_H
