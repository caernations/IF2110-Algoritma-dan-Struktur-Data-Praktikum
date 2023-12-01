// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 0 Algoritma dan Struktur Data

/* 
TODO:
Tuan Man sedang menghitung domba kesayangannya. 
Ia memulai hitungannya dari angka 1. 
Ia akan berteriak "happy" ketika ia sedang menghitung domba yang urutannya dapat dibagi oleh angka kesayangannya. 
Selain itu, ia akan berteriak sesuai urutan domba tersebut.
Tuan Man ingin membuat program komputer yang mencetak apa saja yang ia katakan. 
Program akan menerima 2 masukan, M dan N. 
M menyatakan banyak domba yang dimiliki dan N menyatakan angka kesayangannya. 

CONTOH:
// masukan:
5
2
// keluaran:
1
happy
3
happy
5
*/


#include <stdio.h>

int main()
{
    int m, n, i;

    scanf("%d\n", &m);
    scanf(" %d", &n);

    for (i = 0 ; i < m ; i++)
    {
        if (((i + 1) % n) == 0)
        {
            printf("%s\n", "happy");
        } else
        {
            printf("%d\n", (i + 1));
        }
    }

    return 0;
}