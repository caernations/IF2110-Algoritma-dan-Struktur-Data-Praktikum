// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 0 Algoritma dan Struktur Data

/* 
TODO:
Tuan Mike memberikan sebuah tantangan. 
Diberikan dua buah bilangan a dan b, 
carilah bilangan antara a dan b inklusif yang merupakan bilangan kembar. 
Bilangan kembar didefinisikan sebagai bilangan yang memiliki digit-digit yang sama untuk setiap digitnya. 
Contoh 111, 22, 9999.

CONTOH:
// masukan:
20
40
// keluaran:
2
// penjelasan:
22 dan 33 merupakan bilangan kembar
*/


#include <stdio.h>

#define boolean unsigned char
#define true 1
#define false 0


int isTwin(int num) 
{
    int lastDigit = num % 10;
    while (num > 0) 
    {
        if (num % 10 != lastDigit) 
        {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    int a, b, i;
    int count = 0;
    scanf("%d", &a);
    scanf(" %d", &b);

    for (i = a + 1; i < b; i++) 
    {
        if (isTwin(i) == true) 
        {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
