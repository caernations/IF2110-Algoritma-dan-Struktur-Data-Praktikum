// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 0 Algoritma dan Struktur Data

/* 
TODO:
Tuan Mike ingin mengetahui jumlah digit dari suatu integer. 
Diberikan sebuah masukan integer, 
keluarkan jumlah digit dari integer tersebut. 

CONTOH:
// masukan:
1234
// keluaran:
10
// penjelasan:
1 + 2 + 3 + 4 = 10
*/


#include <stdio.h>

int main() 
{
    int num, number, remainder, jumlahDigit = 0;

    scanf("%d", &num);

    number = num;

    while (num > 0) 
    {
        remainder = num % 10;
        jumlahDigit += remainder;
        num /= 10;
    }

    printf("%d\n", jumlahDigit);

    return 0;
}