#include <stdio.h>
#include "stacklinked.h"

int main()
{
    int t;
    scanf("%d", &t);
    for (t; t > 0; t--)
    {
        Stack masuk, kecil, parkir;
        CreateStack(&masuk);
        CreateStack(&kecil);
        CreateStack(&parkir);

        int n;
        scanf("%d", &n);
        int i;
        int arr[n];

        for (i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            arr[n - i - 1] = temp;
        }

        for (i = 0; i < n; i++)
        {
            push(&masuk, arr[i]);
        }
        boolean bisa = true;
        int current = 1;
        int buang;
        while ((length(masuk) > 0 || length(kecil) > 0) && bisa)
        {
            if (!isEmpty(masuk))
            {
                if (TOP(masuk) == current)
                {
                    push(&parkir, TOP(masuk));
                    pop(&masuk, &buang);
                    current++;
                    continue;
                }
            }

            if (!isEmpty(kecil))
            {
                if (TOP(kecil) == current)
                {
                    push(&parkir, current);
                    pop(&kecil, &buang);
                    current++;
                    continue;
                }
            }

            if (!isEmpty(masuk))
            {
                pop(&masuk, &buang);
                push(&kecil, buang);
                continue;
            }
            bisa = false;
        }

        if (bisa)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
}