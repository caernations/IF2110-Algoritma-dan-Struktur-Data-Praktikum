#include <stdio.h>
#include <stdlib.h>

#include "queuelinked.h"

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

boolean isEmpty(Queue q)
{
    return (ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}

int length(Queue q)
{
    Address P = ADDR_HEAD(q);
    int count = 0;
    while (P != NULL)
    {
        count++;
        P = NEXT(P);
    }
    return count;
}

void CreateQueue(Queue *q)
{
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayQueue(Queue q)
{
    if (isEmpty(q))
    {
        printf("[]");
    }
    else
    {
        Address P = ADDR_HEAD(q);
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

void enqueue(Queue *q, ElType x)
{
    Address P = newNode(x);
    if (P != NULL)
    {
        if (isEmpty(*q))
        {
            ADDR_HEAD(*q) = P;
        }
        else
        {
            NEXT(ADDR_TAIL(*q)) = P;
        }
        ADDR_TAIL(*q) = P;
    }
}

void dequeue(Queue *q, ElType *x)
{
    Address P = ADDR_HEAD(*q);
    if (length(*q) == 1)
    {
        ADDR_TAIL(*q) = NULL;
    }
    *x = INFO(P);
    ADDR_HEAD(*q) = NEXT(P);
    NEXT(P) = NULL;
    free(P);
}