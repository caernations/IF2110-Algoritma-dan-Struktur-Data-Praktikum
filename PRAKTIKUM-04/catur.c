// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 4 Algoritma dan Struktur Data


#include <stdio.h>
#include "boolean.h"
#include "matrix.h"


int main() 
{
    Matrix papancatur;
    readMatrix(&papancatur, 8, 8);

    int black = 0;
    int white = 0;

    for (int i = 0; i < ROW_EFF(papancatur); i++) 
    {
        for (int j = 0; j < COL_EFF(papancatur); j++) 
        {
            if (i % 2 == 0) 
            {
                if (j % 2 == 0 && ELMT(papancatur, i, j) == 1) 
                {
                    black++;
                } 
                else if (j % 2 != 0 && ELMT(papancatur, i, j) == 1) 
                {
                    white++;
                }
            } 
            else 
            {
                if (j % 2 == 0 && ELMT(papancatur, i, j) == 1) 
                {
                    white++;
                } 
                else if (j % 2 != 0 && ELMT(papancatur, i, j) == 1) 
                {
                    black++;
                }
            }
        }
    }

    printf("%d %d\n", black, white);

    return 0;
}