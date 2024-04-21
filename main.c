
#include "column.h"
#include <stdio.h>


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
