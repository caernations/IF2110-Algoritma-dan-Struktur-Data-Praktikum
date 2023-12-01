// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 3 Algoritma dan Struktur Data


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"


int main()
{
    ListDin L;
    CreateListDin(&L, 100);
    readList(&L);
    sort(&L, true);

    if (listLength(L) == 1)
    {
        printf("%d\n", 0);
    }
    else
    {
        printf("%d\n", ELMT(L, listLength(L) - 1) - ELMT(L, 0) + 1);
    }

    dealocateList(&L);
    
    return 0;
}