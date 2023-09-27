// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Pra-Praktikum 5 Algoritma dan Struktur Data

/* File: wordmachine.c */
/* Implementasi Mesin Kata */

#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;


void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}


void STARTWORD()
{
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        currentWord.Length = 0;
        ADVWORD();
    }
}


void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}


void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        {
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
        }
        ADV();
    }
    currentWord.TabWord[currentWord.Length] = '\0';
}