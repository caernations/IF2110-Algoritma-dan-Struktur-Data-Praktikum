// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 2 Algoritma dan Struktur Data


#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"


int main() {
    ListStatik arr1, arr2, mergedArr;

    readList(&arr1);

    readList(&arr2);
    int i, j;
    CreateListStatik(&mergedArr);

    for (i = getFirstIdx(arr1); i <= getLastIdx(arr1); i++) {
        insertLast(&mergedArr, ELMT(arr1, i));
    }

    for (j = getFirstIdx(arr2); j <= getLastIdx(arr2); j++) {
        insertLast(&mergedArr, ELMT(arr2, j));
    }

    sortList(&mergedArr, true);

    printList(mergedArr);
    printf("\n");

    return 0;
}