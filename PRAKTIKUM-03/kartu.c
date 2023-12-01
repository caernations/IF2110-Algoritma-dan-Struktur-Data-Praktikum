// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 3 Algoritma dan Struktur Data

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "boolean.h"


int main() {
    int N, M;
    scanf("%d", &N);
    int stack1[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &stack1[i]);
    }
    
    scanf("%d", &M);
    int stack2[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &stack2[i]); 
    }
    
    int stackAkhir[N + M]; 
    
    int i = 0, j = 0, k = 0;
    while (i < N && j < M) {
        if (stack1[i] >= stack2[j]) {
            stackAkhir[k++] = stack1[i++];
        } else {
            stackAkhir[k++] = stack2[j++];
        }
    }
    
    while (i < N) {
        stackAkhir[k++] = stack1[i++];
    }
    
    while (j < M) {
        stackAkhir[k++] = stack2[j++];
    }
    
    printf("[");
    for (int l = 0; l < k; l++) {
        printf("%d", stackAkhir[l]);
        if (l < k - 1) {
            printf(",");
        }
    }
    printf("]\n");
    
    return 0;
}