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

int main() {
    int num, originalNum, remainder, sum = 0;

    scanf("%d", &num);

    originalNum = num;

    while (num > 0) {
        remainder = num % 10;
        sum += remainder;
        num /= 10;
    }

    printf("%d\n", sum);

    return 0;
}