#include "stack.h"
#include <stdio.h>

#define MAX_CALLS 100 // Maksimum jumlah pemanggilan fungsi yang direkam

int nonRecursiveFibonacci(int N, int callOrder[MAX_CALLS], int *callCount) {
    Stack s;
    int temp;
    int fibValues[N+1];
    boolean calculated[N+1];
    *callCount = 0; // inisialisasi jumlah pemanggilan

    CreateEmpty(&s);
    for (int i = 0; i <= N; i++) {
        fibValues[i] = -1;
        calculated[i] = false;
    }

    Push(&s, N);

    while (!IsEmpty(s)) {
        Pop(&s, &temp);
        int n = temp;

        // Rekam urutan pemanggilan
        if (*callCount < MAX_CALLS) {
            callOrder[*callCount] = n;
            (*callCount)++;
        }

        if (calculated[n]) {
            continue;
        }

        if (n == 0 || n == 1) {
            fibValues[n] = n;
            calculated[n] = true;
        } else {
            if (calculated[n-1] && calculated[n-2]) {
                fibValues[n] = fibValues[n-1] + fibValues[n-2];
                calculated[n] = true;
            } else {
                Push(&s, n);

                if (!calculated[n-1]) {
                    Push(&s, n-1);
                }
                
                if (!calculated[n-2]) {
                    Push(&s, n-2);
                }
            }
        }
    }

    return fibValues[N];
}

int main() {
    int N;
    scanf("%d", &N);

    int callOrder[MAX_CALLS];
    int callCount;

    int result = nonRecursiveFibonacci(N, callOrder, &callCount);

    // Cetak urutan pemanggilan
    for (int i = 0; i < callCount; i++) {
        printf("fibonacci(%d)\n", callOrder[i]);
    }

    // Cetak hasil akhir
    printf("%d\n", result);

    return 0;
}
