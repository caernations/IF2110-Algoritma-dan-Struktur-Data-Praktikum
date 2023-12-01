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
    int query;
    int type;
    
    CreateListDin(&L, 0);
    scanf("%d", &query);

    for (int i = 0; i < query; i++)
    {
        scanf("%d", &type);
        if (type == 1)
        {
            int x;
            scanf("%d", &x);
            if (CAPACITY(L) == 0)
            {
                expandList(&L, 1);
            }
            else if (isFull(L))
            {
                expandList(&L, (CAPACITY(L) * 2) - CAPACITY(L));
            }
            insertLast(&L, x);
        }
        else if (type == 2)
        {
            ElType temp;
            deleteLast(&L, &temp);
            int kapasitas = CAPACITY(L) / 2;
            if (listLength(L) <= CAPACITY(L) / 2)
            {
                shrinkList(&L, kapasitas);
            }
        }
        else if (type == 3)
        {
            printf("%d ", CAPACITY(L));
            printList(L);
            printf("\n");
        }
    }

    return 0;
}