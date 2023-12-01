// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 4 Algoritma dan Struktur Data


#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

#define MOD 2003


Matrix pangkatMatrix(Matrix m, long long pangkat) 
{
    if (pangkat == 0) 
    {
        Matrix identitas;
        createMatrix(2, 2, &identitas);
        ELMT(identitas, 0, 0) = 1;
        ELMT(identitas, 0, 1) = 0;
        ELMT(identitas, 1, 0) = 0;
        ELMT(identitas, 1, 1) = 1;
        return identitas;
    } 
    else if (pangkat == 1) 
    {
        return m;
    } 
    else 
    {
        Matrix m2 = pangkatMatrix(m, pangkat / 2);
        Matrix resultMatrix = multiplyMatrixWithMod(m2, m2, MOD);
        if (pangkat % 2 == 1) 
        {
            resultMatrix = multiplyMatrixWithMod(resultMatrix, m, MOD);
        }
        return resultMatrix;
    }
}

int main() 
{
    long long K;
    scanf("%lld", &K);

    if (K == 1 || K == 2) 
    {
        printf("%d\n", 1);
    } else 
    {
        Matrix matrixFibonacci;
        createMatrix(2, 2, &matrixFibonacci);
        ELMT(matrixFibonacci, 0, 0) = 1;
        ELMT(matrixFibonacci, 0, 1) = 1;
        ELMT(matrixFibonacci, 1, 0) = 1;
        ELMT(matrixFibonacci, 1, 1) = 0;

        Matrix resultMatrix = pangkatMatrix(matrixFibonacci, K - 1); 
        int fibonacci = ELMT(resultMatrix, 0, 0);

        printf("%d\n", fibonacci % MOD);
    }

    return 0;
}