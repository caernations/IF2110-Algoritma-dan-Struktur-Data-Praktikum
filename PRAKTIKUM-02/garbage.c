// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 2 Algoritma dan Struktur Data

#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik rumah, perjalanan;
    CreateListStatik(&rumah);
    CreateListStatik(&perjalanan);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int val;
        scanf(" %d", &val);
        insertLast(&rumah, val);
    }

    scanf(" %d", &n);

    for (int i = 0; i < n; i++)
    {
        int val;
        scanf(" %d", &val);
        insertLast(&perjalanan, val);
    }

    insertFirst(&perjalanan, 0);

    int sum = 0;

    for (int i = 1; i <= 3; i++)
    {
        int idx = 0;
        while (indexOf(rumah, i) != IDX_UNDEF)
        {
            sum += ELMT(perjalanan, idx);
            if (ELMT(rumah, idx) == i)
            {
                sum += 1;
                ELMT(rumah, idx) = 0;
            }
            idx++;
            if (indexOf(rumah, i) == IDX_UNDEF)
            {
                for (int i = 0; i < idx; i++)
                {
                    sum += ELMT(perjalanan, i);
                }
            }
        }
    }

    printf("%d\n", sum);
}