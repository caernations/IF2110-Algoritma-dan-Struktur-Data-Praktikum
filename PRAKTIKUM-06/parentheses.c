// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 6 Algoritma dan Struktur Data

#include <stdio.h>
#include "boolean.h"
#include "stack.h"
#include "wordmachine.h"
#include "charmachine.h"


void readWord(Word *input) {
    int i;
    START();
    IgnoreBlanks();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV();
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}

int main() {
    Stack S;
    CreateEmpty(&S);

    Word inputWord;
    readWord(&inputWord);

    int depth = 0;
    int maxDepth = 0;

    for (int i = 0; i < inputWord.Length; i++) {
        char currentChar = inputWord.TabWord[i];
        if (currentChar == '(') {
            Push(&S, currentChar);
            depth++;
            if (depth > maxDepth) {
                maxDepth = depth;
            }
        } else if (currentChar == ')') {
            char poppedChar;
            if (!IsEmpty(S) && InfoTop(S) == '(') {
                Pop(&S, &poppedChar);
                depth--;
            } else {
                printf("-1\n");
                return 0;
            }
        }
    }

    if (IsEmpty(S)) {
        printf("%d\n", maxDepth);
    } else {
        printf("-1\n");
    }

    return 0;
}