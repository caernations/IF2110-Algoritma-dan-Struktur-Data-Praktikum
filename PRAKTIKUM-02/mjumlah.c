// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 2 Algoritma dan Struktur Data

#include <stdio.h>
#include "liststatik.h"

int main() 
{
    ListStatik L1, L2, L3;
    readList(&L1);
    readList(&L2);
    CreateListStatik(&L3);

    int carry = 0;
    int lenList1 = listLength(L1);
    int lenList2 = listLength(L2);
    int maxLen = (lenList1 > lenList2) ? lenList1 : lenList2;
    int i, digit1, digit2;

    for (i = 0; i < maxLen; i++) 
    {
        if (i < lenList1) 
        {
            digit1 = ELMT(L1, lenList1 - i - 1);
        } else 
        {
            digit1 = 0;
        }

        if (i < lenList2) 
        {
            digit2 = ELMT(L2, lenList2 - i - 1);
        } else 
        {
            digit2 = 0;
        }
        
        // int digit1 = (i < lenList1) ? ELMT(L1, lenList1 - i - 1) : 0;
        // int digit2 = (i < lenList2) ? ELMT(L2, lenList2 - i - 1) : 0;

        int total = digit1 + digit2 + carry;
        carry = total / 10;

        insertFirst(&L3, total % 10);
    }

    if (carry > 0) 
    {
        insertFirst(&L3, carry);
    }

    printList(L3);
    printf("\n");
    return 0;
}