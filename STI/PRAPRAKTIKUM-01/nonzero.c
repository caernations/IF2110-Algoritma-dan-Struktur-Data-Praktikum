#include <stdio.h>

int main() 
{
    int num;
    int originalNum;
    int remainder;
    int finalNumbers = 1;
    int countNonZero = 0;

    scanf("%d", &num);

    originalNum = num;

    while (num > 0) {
        remainder = num % 10;
        if (remainder != 0) {
            finalNumbers *= remainder;
        }
        num /= 10;
    }

    printf("%d ", finalNumbers);
    

    int tempFinalNumbers = finalNumbers;
    while (tempFinalNumbers > 0) 
    {
        remainder = tempFinalNumbers % 10;
        if (remainder != 0) {
            countNonZero++;
        }
        tempFinalNumbers /= 10;
    }

    printf("%d\n", countNonZero);

    return 0;
}