// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Prapraktikum 3 Algoritma dan Struktur Data


#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "boolean.h"


void CreateListDin(ListDin *l, int capacity)
{
    BUFFER(*l) = (int*) malloc(capacity * sizeof(int));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}


void dealocateList(ListDin *l)
{
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}


int listLength(ListDin l)
{
    return NEFF(l);
}


IdxType getFirstIdx(ListDin l)
{
    return 0;
}


IdxType getLastIdx(ListDin l)
{
    return NEFF(l) - 1;
}


boolean isIdxValid(ListDin l, IdxType i)
{
    return (i >= 0 && i < CAPACITY(l));
}


boolean isIdxEff(ListDin l, IdxType i)
{
    return (i >= 0 && i < NEFF(l));
}


boolean isEmpty(ListDin l)
{
    return (NEFF(l) == 0);
}


boolean isFull(ListDin l)
{
    return (NEFF(l) == CAPACITY(l));
}


void readList(ListDin *l)
{
    int n, i;
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY(*l)) 
    {
        scanf("%d", &n);
    }

    NEFF(*l) = n;

    if (n != 0)
    {
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &ELMT(*l, i));
        }
    }
}


void printList(ListDin l)
{
    int i;
    printf("[");
    if (listLength(l) != 0) 
    {
        for (i = 0; i < listLength(l) - 1; i++) 
        {
            printf("%d,", ELMT(l, i));
        }
        printf("%d", ELMT(l, i));
    }
    printf("]");
}


ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    ListDin l3;
    int i;

    CreateListDin(&l3, CAPACITY(l1));
    NEFF(l3) = NEFF(l1);
    for (i = 0; i < listLength(l1); i++) 
    {
        if (plus) 
        {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        } else 
        {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l3;
}


boolean isListEqual(ListDin l1, ListDin l2)
{
   int i = 0;
   if (listLength(l1) == listLength(l2))
   {
      while (ELMT(l1, i) == ELMT(l2, i) && i != listLength(l1))
      {
          i++;
      }
      return (i == listLength(l1));
   }
   else 
   {
      return false;
   }
}


IdxType indexOf(ListDin l, ElType val)
{
    IdxType i = 0;
    boolean found = false;

    while (!found && i < NEFF(l)) 
    {
        if (ELMT(l, i) == val) 
        {
            found = true;
        } else 
        {
            i++;
        }
    }

    if (found) 
    {
        return i;
    } else 
    {
        return IDX_UNDEF;
    }
}


void extremeValues(ListDin l, ElType *max, ElType *min)
{
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);

    for (i = 1; i < NEFF(l); i++) 
    {
        if (ELMT(l, i) > *max) 
        {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) 
        {
            *min = ELMT(l, i);
        }
    }
}


void copyList(ListDin lIn, ListDin *lOut)
{
    int i;
    dealocateList(lOut);
    CreateListDin(lOut, CAPACITY(lIn));
    for (i = 0; i < NEFF(lIn); i++) 
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
}


ElType sumList(ListDin l)
{
    int i;
    ElType sum = 0;

    for (i = 0; i < NEFF(l); i++) 
    {
        sum += ELMT(l, i);
    }

    return sum;
}


int countVal(ListDin l, ElType val)
{
    int i;
    int count = 0;

    for (i = 0; i < listLength(l); i++) 
    {
        if (ELMT(l, i) == val) 
        {
            count++;
        }
    }

    return count;
}


void sort(ListDin *l, boolean asc)
{
    int i;
    int j;
    ElType temp;

    for (i = 0; i < NEFF(*l) - 1; i++) 
    {
        for (j = i + 1; j < NEFF(*l); j++) 
        {
            if (asc) 
            {
                if (ELMT(*l, i) > ELMT(*l, j)) 
                {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            } else 
            {
                if (ELMT(*l, i) < ELMT(*l, j)) 
                {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}


void insertLast(ListDin *l, ElType val)
{
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l)++;
}


void deleteLast(ListDin *l, ElType *val)
{
    *val = ELMT(*l, NEFF(*l) - 1);
    NEFF(*l)--;
}


void expandList(ListDin *l, int num)
{
    ListDin temp;
    CreateListDin(&temp, CAPACITY(*l));
    copyList(*l, &temp);
    int tempNeff = NEFF(*l);
    dealocateList(l);
    CreateListDin(l, CAPACITY(temp) + num);
    NEFF(*l) = tempNeff;
   
    int i;
    for (i = 0; i < listLength(temp); i++) 
    {
        ELMT(*l, i) = ELMT(temp, i);
    }
}


void shrinkList(ListDin *l, int num)
{
    ListDin temp;
    CreateListDin(&temp, CAPACITY(*l));
    copyList(*l, &temp);
    int tempNeff = NEFF(*l);

    CreateListDin(l, CAPACITY(temp) - num);

    NEFF(*l) = tempNeff;
    if(CAPACITY(temp) - num < NEFF(*l))
    {
        NEFF(*l) = CAPACITY(temp) - num;
    }
   
    int i;
    for (i = 0; i < listLength(temp); i++) 
    {
      ELMT(*l, i) = ELMT(temp, i);
    }
}


void compressList(ListDin *l)
{
    shrinkList(l, CAPACITY(*l) - NEFF(*l));
}