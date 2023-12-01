// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 3 Algoritma dan Struktur Data

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "boolean.h"

void deleteAt(ListDin *L, int idx)
{
    int i;
    for (i = idx; i < listLength(*L) - 1; i++)
    {
        ELMT(*L, i) = ELMT(*L, i + 1);
    }
    NEFF(*L)--;
}

void deleteEl(ListDin *L, int num)
{
    int i = 0;
    while (i < listLength(*L))
    {
        if (ELMT(*L, i) < num)
        {
            deleteAt(L, i);
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int C, Q;
    ListDin L;
    scanf("%d", &C);
    CreateListDin(&L, C);
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++)
    {
        int query;
        scanf("%d", &query);
        if (query == 1)
        {
            int num;
            scanf("%d", &num);
            deleteEl(&L, num);
            insertLast(&L, num);
        }
        else if (query == 2)
        {
            printf("%d\n", listLength(L));
            printList(L);
            printf("\n");
        }
    }

    return 0;
}