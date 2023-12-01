// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 0 Algoritma dan Struktur Data

/* 
TODO:
Tuan Mike memiliki n buah bilangan dan menerima n buah bilangan integer. 
Keluarkan bilangan terbesar kedua.

CONTOH:
// masukan:
5
3
4
2
8
7
// keluaran:
7
// penjelasan:
n adalah 5 dan program menerima 5 bilangan bertipe integer
// catatan: jika output salah saat dirun di vscode, 
coba run dengan online compiler.
https://www.programiz.com/c-programming/online-compiler/#google_vignette
*/


#include <stdio.h>

int main() 
{
    int max1, max2 = -9999999; 
    int num, i, n;

    scanf("%d", &n);
    
    for (i = 0 ; i < n ; i++)
    {

        scanf("%d", &num);
        
        if (num > max1) 
        {
            max2 = max1;
            max1 = num;
            
        } else if (num > max2 && num < max1) 
        {
            max2 = num;
        }
    }
    
    printf("%d\n", max2);
    return 0;
}
