// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 2 Algoritma dan Struktur Data

#include <stdio.h>
#include "liststatik.h"

int main() 
{
    ListStatik array;
    readList(&array);
    sortList(&array, true); 
    double sum = 0;
    int n = listLength(array);
    int X;
    int firstIndex = -1;

    for (int i = 0; i < n; i++) 
    {
        sum += ELMT(array, i);
    }

    double average = sum / n;

    scanf("%d", &X);

    for (int i = 0; i < n; i++) 
    {
        if (ELMT(array, i) == X) 
        {
            firstIndex = i;
            break;
        }
    }

    printf("[");
    for (int i = 0; i < n; i++) 
    {
        printf("%d", ELMT(array, i));
        if (i < n - 1) 
        {
            printf(",");
        }
    }
    printf("]\n");

    printf("Average: %.2lf\n", average);

    if (firstIndex == -1) 
    {
        printf("%d tidak ada\n", X);
    } else 
    {
        printf("%d\n", firstIndex);

        if (X == ELMT(array, n - 1)) 
        {
            printf("X maksimum\n");
        }
        if (X == ELMT(array, 0)) 
        {
            printf("X minimum\n");
        }
        if (n % 2 == 1 && X == ELMT(array, n / 2)) 
        {
            printf("X median\n");
        }
        if (n % 2 == 0 && X == ELMT(array, n / 2 - 1)) 
        {
            printf("X median\n");
        }
    }

    return 0;
}