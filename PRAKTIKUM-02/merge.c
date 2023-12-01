// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 2 Algoritma dan Struktur Data


#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"


int main() {
    ListStatik array1, array2, arrayMerged;

    readList(&array1);

    readList(&array2);
    int i, j;
    CreateListStatik(&arrayMerged);

    for (i = getFirstIdx(array1); i <= getLastIdx(array1); i++) {
        insertLast(&arrayMerged, ELMT(array1, i));
    }

    for (j = getFirstIdx(array2); j <= getLastIdx(array2); j++) {
        insertLast(&arrayMerged, ELMT(array2, j));
    }

    sortList(&arrayMerged, true);

    printList(arrayMerged);
    printf("\n");

    return 0;
}