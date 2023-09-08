// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 1 Algoritma dan Struktur Data


#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"


void CreateListStatik(ListStatik *l)
{
    int i;

    for (i = 0; i < CAPACITY; i++)
    {
        ELMT(*l, i) = MARK;
    }
}


int listLength(ListStatik l)
{
    int i;
    int count;
    count = 0;

    for (i = 0 ; i < CAPACITY ; i++)
    {
        if (ELMT(l, i) != MARK)
            count++;
    }
    return count;
}


IdxType getFirstIdx(ListStatik l)
{
    return IDX_MIN;
}


IdxType getLastIdx(ListStatik l)
{
    return listLength(l) - 1;
}


boolean isIdxValid(ListStatik l, IdxType i)
{
    return ((i >= IDX_MIN) && (i <= (CAPACITY - 1)));
}


boolean isIdxEff(ListStatik l, IdxType i)
{
    return (i >= 0 && i <= listLength(l) - 1);
}


boolean isEmpty(ListStatik l)
{
    return (listLength(l) == 0);
}


boolean isFull(ListStatik l)
{
    return (listLength(l) == CAPACITY);
}


void readList(ListStatik *l)
{
    int n; 
    int i;

    CreateListStatik(l);
    scanf("%d", &n);

    while (n < 0 || n > CAPACITY) 
    {
        scanf(" %d", &n);
    }

    for (i = 0; i < n; i++)
    {
        scanf(" %d", &ELMT(*l, i));
    }
}


void printList(ListStatik l)
{
    int i;
    printf("[");
    
    for (i = 0; i < listLength(l); i++) 
    {
        printf("%d", ELMT(l, i));
        if (i < listLength(l) - 1)
            printf(",");
    }

    printf("]");
}


ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus)
{
    ListStatik l;
    int i;
    CreateListStatik(&l);

    for (i = 0; i < listLength(l1); i++) 
    {
        if (plus) {
            ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
        } else {
            ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    return l;
}


boolean isListEqual(ListStatik l1, ListStatik l2)
{

    boolean equal = true;
    int i = 0;

    if (listLength(l1) != listLength(l2)) {
        equal = false;
    } else {
        while (equal && i < listLength(l1)) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                equal = false;
            }
            i++;
        }
    }

    return equal;
}


int indexOf(ListStatik l, ElType val)
{
    int i = 0;
    boolean found = false;

    while (!found && i < listLength(l)) 
    {
        if (ELMT(l, i) == val) {
            found = true;
        } else {
            i++;
        }
    }

    if (found) {
        return i;
    } else {
        return IDX_UNDEF;
    }
}


void extremeValues(ListStatik l, ElType *max, ElType *min)
{
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);

    for (i = 1; i < listLength(l); i++) 
    {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}


void insertFirst(ListStatik *l, ElType val)
{
    int i;

    for (i = listLength(*l); i > 0; i--) 
    {
        ELMT(*l, i) = ELMT(*l, i - 1);
    }

    ELMT(*l, 0) = val;
}


void insertAt(ListStatik *l, ElType val, IdxType idx)
{
    int i;

    for (i = listLength(*l); i > idx; i--) 
    {
        ELMT(*l, i) = ELMT(*l, i - 1);
    }

    ELMT(*l, idx) = val;
}


void insertLast(ListStatik *l, ElType val)
{
    ELMT(*l, listLength(*l)) = val;
}


void deleteFirst(ListStatik *l, ElType *val)
{
    int i;

    if (!isEmpty(*l)){
        *val = ELMT(*l, 0);
        
        for (i = 0; i < listLength(*l) - 1; i++)
        {
            ELMT(*l, i) = ELMT(*l, i + 1);
            }
        }

        ELMT(*l, listLength(*l) - 1) = MARK;
}


void deleteAt(ListStatik *l, ElType *val, IdxType idx)
{
    int i;

    if (!isEmpty(*l)){
        *val = ELMT(*l, idx);

        for (i = idx; i < listLength(*l) - 1; i++)
        {
            ELMT(*l, i) = ELMT(*l, i + 1);
            }
        }
        ELMT(*l, listLength(*l) - 1) = MARK;
}


void deleteLast(ListStatik *l, ElType *val)
{
    if (!isEmpty(*l)){
        *val = ELMT(*l, listLength(*l) - 1);
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}


void sortList(ListStatik *l, boolean asc)
{
    int i;
    int j;
    ElType temp;

    for (i = 0; i < listLength(*l) - 1; i++) 
    {
        for (j = i + 1; j < listLength(*l); j++) 
        {
            if (asc) {
                if (ELMT(*l, i) > ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            } else {
                if (ELMT(*l, i) < ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}

