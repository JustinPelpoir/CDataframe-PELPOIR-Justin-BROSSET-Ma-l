
#include "column.h"
#include <stdio.h>
#include "cdataframe.h"


/** 
int main()
{
    int value;
    COLUMN *c;

    printf("Valeur : ");
    scanf("%d", &value);

    c = create_column("c1");
    insert_value(c, value);

    print_col(c);

    delete_column(&c);

    return 0;
}
**/

int main() {
    int choix ;
    do while {
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
        printf("13. Afficher le nom d'une colonne\n");
        printf("14. Afficher le nombre de lignes\n");
        printf("15. Afficher le nombre de colonnes\n");
        printf("16. Afficher le nombre de cellules contenant une valeur égale à une valeur donnée\n");
        printf("17. Afficher le nombre de cellules contenant une valeur supérieure à une valeur donnée\n");
        printf("18. Afficher le nombre de cellules contenant une valeur inférieure à une valeur donnée\n");
        printf("19. Quitter le menu principal\n\n");
        printf("Choix : ");
        scanf("%d", &choix);
        if(choix==1){
            int insertion_valeur(FRAME* frame, int value);
        }
        if(choix==2){
            void affichage_dataframe(FRAME* frame);
        }
        if(choix==3){
            void affichage_ligne(FRAME* frame);
        }
        if(choix==4){
            void affichage_colonne(FRAME* frame);
        }
        if(choix==5){
            void ajouter_ligne(FRAME* frame);
        }
        if(choix==6){
            void ajouter_colonne(FRAME* frame);
        }
        if(choix==7){
            void supprimer_ligne(FRAME** frame);
        }
        if(choix==8){
            void supprimer_colonne(FRAME** frame);
        }
        if(choix==9){
            void renommer_colonne(FRAME* frame);
        }
        if(choix==10){
            void recherche_valeur(FRAME* frame, int valeur);
        }
        if(choix==11){
            void affichage_case(FRAME* frame);
        }
        if(choix==12){
            void remplacer_case(FRAME* frame);
        }
        if(choix==13){
            void affichage_nom_colonne(FRAME* frame);
        }
        if(choix==14){
            void affichage_nb_ligne(FRAME* frame);
        }
        if(choix==15){
            void affichage_nb_colonne(FRAME* frame);
        }
        if(choix==16){
            int nb_valeur_egal_frame(FRAME* frame, int valeur);
        }
        if(choix==17){
            int nb_valeur_superieur_frame(FRAME* frame, int valeur);
        }
        if(choix==18){
            int nb_valeur_inferieur_frame(FRAME* frame, int valeur);
        }
        if(choix==19){
            printf("Merci d'avoir utilisé notre service\nAu plaisir de vous revoir !\n");
            return 0;
        }
