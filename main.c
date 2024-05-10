
#include "column.h"
#include <stdio.h>


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
        printf("Bienvenue dans le menu principal,\nQuelle est votre requête ?\n\n")
        printf("1. Créer une colonne\n");
        printf("2. Insérer une valeur\n);
        printf("3. Supprimer une colonne\n");
        printf("4. Afficher une colonne\n");
        printf("5. Afficher le nombre de d’occurrences de la valeur donnée\n");
        printf("6. Afficher la valeur présente à une position donnée\n");
        printf("7. Afficher le nombre de valeurs qui sont supérieures à la valeur donnée\n");
        printf("8. Afficher le nombre de valeurs qui sont inférieures à la valeur donnée\n");
        printf("9. Afficher le nombre de valeurs qui sont égales à la valeur donnée\n");
        printf("10. Quitter le menu principal\n\n");
        printf("Choix : ");
        scanf("%d", &choix);
    }
    
