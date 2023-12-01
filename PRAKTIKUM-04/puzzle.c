// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 4 Algoritma dan Struktur Data


#include <stdio.h>
#include "boolean.h" 
#include "matrix.h" 

int main() 
{

    int N, M;
    scanf("%d %d", &N, &M);

    Matrix puzzle;
    readMatrix(&puzzle, N, M);

    int K;
    scanf("%d", &K);

    int A, B;
    Matrix potonganPuzzle;

    boolean canBeSolved = true; 
    for (int k = 0; k < K; k++) 
    {
        scanf("%d %d", &A, &B);

        readMatrix(&potonganPuzzle, A, B);

        boolean found = false;
        for (int i = 0; i <= N - A; i++) 
        {
            for (int j = 0; j <= M - B; j++) 
            {
                Matrix subMatrix;
                createMatrix(A, B, &subMatrix);
                for (int x = 0; x < A; x++) 
                {
                    for (int y = 0; y < B; y++) 
                    {
                        ELMT(subMatrix, x, y) = ELMT(puzzle, i + x, j + y);
                    }
                }

                if (isMatrixEqual(subMatrix, potonganPuzzle)) 
                {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) 
        {
            canBeSolved = false;
            break;
        }
    }

    if (canBeSolved) 
    {
        printf("Puzzle dapat diselesaikan.\n");
    } 
    else 
    {
        printf("Puzzle tidak dapat diselesaikan.\n");
    }

    return 0;
}