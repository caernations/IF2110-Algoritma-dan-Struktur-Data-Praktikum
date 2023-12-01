#include <stdio.h>
#include "stacklinked.h"

int main()
{
    Stack t1;
    Stack t2;
    Stack t3;

    CreateStack(&t1);
    CreateStack(&t2);
    CreateStack(&t3);
    int i;

    for (i = 5; i > 0; i--)
    {
        push(&t1, i);
    }
    int N;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        int awal, selanjutnya;
        scanf("%d %d", &awal, &selanjutnya);
        if (awal == 1 && selanjutnya == 2)
        {
            if (isEmpty(t1))
            {
                printf("Menara kosong\n");
            }
            else
            {
                int val;
                pop(&t1, &val);
                if (!isEmpty(t2) && val > TOP(t2))
                {
                    push(&t1, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else
                {
                    push(&t2, val);
                }
            }
        }
        else if (awal == 1 && selanjutnya == 3)
        {
            if (isEmpty(t1))
            {
                printf("Menara kosong\n");
            }
            else
            {
                int val;
                pop(&t1, &val);
                if (!isEmpty(t3) && val > TOP(t3))
                {
                    push(&t1, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else
                {
                    push(&t3, val);
                }
            }
        }
        else if (awal == 2 && selanjutnya == 1)
        {
            if (isEmpty(t2))
            {
                printf("Menara kosong\n");
            }
            else
            {
                int val;
                pop(&t2, &val);
                if (!isEmpty(t1) && val > TOP(t1))
                {
                    push(&t2, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else
                {
                    push(&t1, val);
                }
            }
        }
        else if (awal == 2 && selanjutnya == 3)
        {
            if (isEmpty(t2))
            {
                printf("Menara kosong\n");
            }
            else
            {
                int val;
                pop(&t2, &val);
                if (!isEmpty(t3) && val > TOP(t3))
                {
                    push(&t2, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else
                {
                    push(&t3, val);
                }
            }
        }
        else if (awal == 3 && selanjutnya == 1)
        {
            if (isEmpty(t3))
            {
                printf("Menara kosong\n");
            }
            else
            {
                int val;
                pop(&t3, &val);
                if (!isEmpty(t1) && val > TOP(t1))
                {
                    push(&t3, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else
                {
                    push(&t1, val);
                }
            }
        }
        else if (awal == 3 && selanjutnya == 2)
        {
            if (isEmpty(t3))
            {
                printf("Menara kosong\n");
            }
            else
            {
                int val;
                pop(&t3, &val);
                if (!isEmpty(t2) && val > TOP(t2))
                {
                    push(&t3, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else
                {
                    push(&t2, val);
                }
            }
        }
    }
    printf("Menara 1: ");
    DisplayStack(t1);
    printf("\n");
    printf("Menara 2: ");
    DisplayStack(t2);
    printf("\n");
    printf("Menara 3: ");
    DisplayStack(t3);
    printf("\n");
}
