#include <stdio.h>
#include <stdlib.h>

#include "stacklinked.h"

Address newNode(ElType x)
{
    Address P = (Address)malloc(sizeof(ElType));
    if (P != NULL)
    {
        INFO(P) = x;
        NEXT(P) = NULL;
        return P;
    }
    else
    {
        return NULL;
    }
}

boolean isEmpty(Stack s)
{
    return (ADDR_TOP(s) == NULL);
}

int length(Stack s)
{
    Address P = ADDR_TOP(s);
    int count = 0;
    while (P != NULL)
    {
        count++;
        P = NEXT(P);
    }
    return count;
}

void CreateStack(Stack *s)
{
    ADDR_TOP(*s) = NULL;
}

void DisplayStack(Stack s)
{
    if (isEmpty(s))
    {
        printf("[]");
    }
    else
    {
        Address P = ADDR_TOP(s);
        printf("[");
        while (P != NULL)
        {
            printf("%d", INFO(P));
            if (NEXT(P) != NULL)
            {
                printf(",");
            }
            P = NEXT(P);
        }
        printf("]");
    }
}

void push(Stack *s, ElType x)
{
    Address P = newNode(x);
    if (P != NULL)
    {
        NEXT(P) = ADDR_TOP(*s);
        ADDR_TOP(*s) = P;
    }
}

void pop(Stack *s, ElType *x)
{
    if (!isEmpty(*s))
    {
        Address P = ADDR_TOP(*s);
        *x = INFO(P);
        ADDR_TOP(*s) = NEXT(P);
        free(P);
    }
}