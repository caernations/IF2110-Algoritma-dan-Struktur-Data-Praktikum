// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 6 Algoritma dan Struktur Data


#include <stdio.h>
#include "stack.h"


void SortirKeranjang(Stack *S1, Stack *S2)
{
    Stack TempStack;
    CreateEmpty(&TempStack); 

    infotype X, Y;

    while (!IsEmpty(*S1))
    {
        Pop(S1, &X); 
        if (IsEmpty(TempStack) || X >= InfoTop(TempStack))
        {
            Push(&TempStack, X); 
        }
        else
        {
            while (!IsEmpty(TempStack) && X < InfoTop(TempStack))
            {
                Pop(&TempStack, &Y); 
                Push(S1, Y); 
            }
            Push(&TempStack, X);
        }
    }


    while (!IsEmpty(TempStack))
    {
        Pop(&TempStack, &X);
        Push(S2, X);
    }
}