#include "cdataframe.h"
#include <stdlib.h>
#include <stdio.h>
#define REALOC_SIZE 256

// Création d'un dataframe
FRAME *create_dataframe(char* title)
{
    FRAME *c = (COLUMN*)malloc(sizeof(COLUMN));
    c-> titre = title;
    c-> TL = 0;
    c-> TP = 0;
    c-> T = NULL;

    return c;
}
