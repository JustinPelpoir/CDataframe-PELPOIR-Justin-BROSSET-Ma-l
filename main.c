
#include "column.h"
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int boucle = 1;
    int choix;
    int val;
    int limite;
    int col;
    int row;
    char nouveau_nom[50];

    // Initialisation du dataframe
    FRAME* frame = create_dataframe("Mon DataFrame");

    do {
        // Affichage du menu
        printf("\n----------Menu Principal----------\n");
        printf("Bienvenue dans le menu principal,\nQuelle est votre requête ?\n\n");
        printf("1. Insérer une valeur\n");
        printf("2. Remplir le dataframe en dur\n");
        printf("3. Afficher le dataframe\n");
        printf("4. Afficher une partie des lignes\n");
        printf("5. Afficher une partie des colonnes\n");
        printf("6. Ajouter une ligne\n");
        printf("7. Ajouter une colonne\n");
        printf("8. Supprimer une ligne\n");
        printf("9. Supprimer une colonne\n");
        printf("10. Renommer une colonne\n");
        printf("11. Rechercher une valeur\n");
        printf("12. Afficher une case\n");
        printf("13. Remplacer une case\n");
        printf("14. Afficher les noms des colonnes\n");
        printf("15. Afficher le nombre de lignes\n");
        printf("16. Afficher le nombre de colonnes\n");
        printf("17. Afficher le nombre de cellules contenant une valeur égale à une valeur donnée\n");
        printf("18. Afficher le nombre de cellules contenant une valeur supérieure à une valeur donnée\n");
        printf("19. Afficher le nombre de cellules contenant une valeur inférieure à une valeur donnée\n");
        printf("20. Quitter le menu principal\n\n");
        printf("Choix : ");
        scanf_s("%d", &choix);

        switch (choix) {
            case 1:
                insertion_valeur(frame);
                break;
            case 2:
                remplir_dataframe_en_dur(frame);
                break;
            case 3:
                affichage_dataframe(frame);
                break;
            case 4:
                printf("Jusqu'à quelle ligne voulez-vous afficher votre dataframe ? ");
                scanf_s("%d", &limite);
                affichage_ligne(frame, limite);
                break;
            case 5:
                printf("Jusqu'à quelle colonne voulez-vous afficher votre dataframe ? ");
                scanf_s("%d", &limite);
                affichage_colonne(frame, limite);
                break;
            case 6:
                ajouter_ligne(frame);
                break;
            case 7:
                ajouter_colonne(frame);
                break;
            case 8:
                supprimer_ligne(frame);
                break;
            case 9:
                supprimer_colonne(frame);
                break;
            case 10:
                printf("Quelle colonne voulez-vous renommer ? ");
                scanf_s("%d", &col);
                printf("Comment voulez-vous la renommer ? ");
                scanf_s("%s", nouveau_nom);
                renommer_colonne(frame, col, nouveau_nom);
                break;
            case 11:
                printf("Quelle valeur voulez-vous rechercher ? ");
                scanf_s("%d", &val);
                recherche_valeur(frame, val);
                break;
            case 12:
                printf("Dans quelle colonne se situe la case que vous voulez afficher ? ");
                scanf_s("%d", &col);
                printf("Dans quelle ligne se situe la case que vous voulez afficher ? ");
                scanf_s("%d", &row);
                affichage_case(frame, col, row);
                break;
            case 13:
                printf("Dans quelle colonne se situe la case que vous voulez remplacer ? ");
                scanf_s("%d", &col);
                printf("Dans quelle ligne se situe la case que vous voulez remplacer ? ");
                scanf_s("%d", &row);
                printf("Quelle valeur voulez-vous mettre dans cette case ? ");
                scanf_s("%d", &val);
                remplacer_case(frame, col, row, val);
                break;
            case 14:
                affichage_noms_colonnes(frame);
                break;
            case 15:
                affichage_nb_ligne(frame);
                break;
            case 16:
                affichage_nb_colonne(frame);
                break;
            case 17:
                printf("Quelle valeur voulez-vous pour faire cette recherche ? ");
                scanf_s("%d", &val);
                printf("Nombre de cellules contenant la valeur égale : %d\n", nb_valeur_egal_frame(frame, val));
                break;
            case 18:
                printf("Quelle valeur voulez-vous pour faire cette recherche ? ");
                scanf_s("%d", &val);
                printf("Nombre de cellules contenant une valeur supérieure : %d\n", nb_valeur_superieur_frame(frame, val));
                break;
            case 19:
                printf("Quelle valeur voulez-vous pour faire cette recherche ? ");
                scanf_s("%d", &val);
                printf("Nombre de cellules contenant une valeur inférieure : %d\n", nb_valeur_inferieur_frame(frame, val));
                break;
            case 20:
                printf("Merci d'avoir utilisé notre service\nAu plaisir de vous revoir !\n");
                boucle = 0;
                // Libérer la mémoire du dataframe
                if (frame != NULL){
                    for (int i = 0; i < frame->TP; i++) {
                        free(frame->col[i]->titre);
                        free(frame->col[i]->T);
                        free(frame->col[i]);
                    }
                    free(frame->col);
                    free(frame->titre);
                    free(frame);
                }
                break;
            default:
                printf("Désolé cette commande n'existe pas, veuillez réessayer...\n");
                break;
        }
    } while (boucle == 1);

    return 0;
}
