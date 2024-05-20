
#include "column.h"
#include <stdio.h>
#include "cdataframe.h"

int main() {
    int boucle=1;
    int choix ;
    int val;
    int limite;
    int col;
    int row;
    char nouveau_nom[50];
    do{
        // Affichage du menu
        printf("\n----------Menu Principal----------\n");
        printf("Bienvenue dans le menu principal,\nQuelle est votre requête ?\n\n");
        printf("1. Insérer une valeur\n");
        printf("2. Afficher le dataframe\n");
        printf("3. Afficher une partie des lignes\n");
        printf("4. Afficher un partie des colonnes\n");
        printf("5. Ajouter une ligne\n");
        printf("6. Ajouter une colonne\n");
        printf("7. Supprimer une ligne\n");
        printf("8. Supprimer une colonne\n"); 
        printf("9. Renommer une colonne\n");
        printf("10. Rechercher une valeur\n");
        printf("11. Afficher une case\n");
        printf("12. Remplacer une case\n");
        printf("13. Afficher les noms des colonnes\n");
        printf("14. Afficher le nombre de lignes\n");
        printf("15. Afficher le nombre de colonnes\n");
        printf("16. Afficher le nombre de cellules contenant une valeur égale à une valeur donnée\n");
        printf("17. Afficher le nombre de cellules contenant une valeur supérieure à une valeur donnée\n");
        printf("18. Afficher le nombre de cellules contenant une valeur inférieure à une valeur donnée\n");
        printf("19. Quitter le menu principal\n\n");
        printf("Choix : ");
        scanf("%d", &choix);
        if(choix==1){
            void insertion_valeur(frame);
        }
        if(choix==2){
            void affichage_dataframe(frame);
        }
        if(choix==3){
            printf("Jusqu'à quelle ligne voulez-vous afficher votre dataframe ?");
            scanf("%d", &limite);
            void affichage_ligne(frame, limite);
        }
        if(choix==4){
            printf("Jusqu'à quelle colonne voulez-vous afficher votre dataframe ?");
            scanf("%d", &limite);
            void affichage_colonne(frame, limite);
        }
        if(choix==5){
            void ajouter_ligne(frame);
        }
        if(choix==6){
            void ajouter_colonne(frame);
        }
        if(choix==7){
            void supprimer_ligne(frame);
        }
        if(choix==8){
            void supprimer_colonne(frame);
        }
        if(choix==9){
            printf("Quelle colonne voulez-vous renommer ?");
            scanf("%d", &col);
            printf("Comment voulez-vous la renommer ?");
            scanf("%s", nouveau_nom);
            void renommer_colonne(frame, col, nouveau_nom);
        }
        if(choix==10){
            printf("Quelle valeur voulez-vous rechercher ?");
            scanf("%d", val);
            void recherche_valeur(frame, int val);
        }
        if(choix==11){
            printf("Dans quelle colonne se situe la case que vous voulez afficher ?");
            scanf("%d", &col);
            printf("Dans quelle ligne se situe la case que vous voulez afficher ?");
            scanf("%d", &row);
            void affichage_case(frame, col, row);
        }
        if(choix==12){
            printf("Dans quelle colonne se situe la case que vous voulez remplacer ?");
            scanf("%d", &col);
            printf("Dans quelle ligne se situe la case que vous voulez remplacer ?");
            scanf("%d", &row);
            printf("Quelle valeur voulez-vous mettre dans cette case ?");
            scanf("%d", &val);
            void remplacer_case(frame, col, row, val);
        }
        if(choix==13){
            void affichage_nom_colonne(frame);
        }
        if(choix==14){
            void affichage_nb_ligne(frame);
        }
        if(choix==15){
            void affichage_nb_colonne(frame);
        }
        if(choix==16){
            printf("Quelle valeur voulez-vous pour faire cette recherche ?");
            scanf("%d", &val);
            int nb_valeur_egal_frame(frame, valeur);
        }
        if(choix==17){
            printf("Quelle valeur voulez-vous pour faire cette recherche ?");
            scanf("%d", &val);
            int nb_valeur_superieur_frame(frame, valeur);
        }
        if(choix==18){
            printf("Quelle valeur voulez-vous pour faire cette recherche ?");
            scanf("%d", &val);
            int nb_valeur_inferieur_frame(frame, valeur);
        }
        if(choix==19){
            printf("Merci d'avoir utilisé notre service\nAu plaisir de vous revoir !\n");
            boucle=0;
            // Liberer la mémoire du dataframe
            for (int i = 0; i < dataframe->TP; i++) {
                free(dataframe->titre[i]);
                free(dataframe->cols[i]->titre);
                free(dataframe->cols[i]->T);
                free(dataframe->cols[i]);
            }
            free(dataframe->cols);
            free(dataframe->titre);
            free(dataframe);
        }
        else{
            printf("Désolé cette commande n'existe pas, veuillez réessayer... \n");
        }
    }while(boucle==1)
