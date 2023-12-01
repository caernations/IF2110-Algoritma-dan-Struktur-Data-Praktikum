#include <stdio.h>

long long int fibonacci(int n) {
    printf("fibonacci(%d)\n", n);

    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);

    int result = fibonacci(n);
    printf("%d\n", result);

    return 0;
}