#include "deque.h"
#include "stdio.h"

Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
   atau NIL jika alokasi gagal */
{
    Address P = (Address)malloc(sizeof(Node));
    if (P != NULL)
    {
        INFO(P) = x;
        NEXT(P) = NIL;
    }
    return P;
}

boolean isEmpty(Deque q)
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */
{
    return ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL;
}

int length(Deque q)
/* Mengirimkan banyaknya elemen Deque. Mengirimkan 0 jika q kosong */
{
    int count = 0;
    Address P = ADDR_HEAD(q);
    while (P != NIL)
    {
        count++;
        P = NEXT(P);
    }
    return count;
}

void CreateDeque(Deque *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
{
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

void DisplayDeque(Deque q)
/* Proses : Menuliskan isi Deque, ditulis di antara kurung siku; antara dua elemen
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah,
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Deque kosong : menulis [] */
{
    printf("[");
    Address P = ADDR_HEAD(q);
    while (P != NIL)
    {
        printf("%d", INFO(P));
        P = NEXT(P);
        if (P != NIL)
        {
            printf(",");
        }
    }
    printf("]");
}

void EnqueueHead(Deque *q, ElType x)
/* Proses: Mengalokasi x dan menambahkan x pada bagian HEAD dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertFirst */
/* I.S. q mungkin kosong */
/* F.S. x menjadi HEAD, HEAD "maju" */
{
    Address P = newNode(x);
    if (P != NULL)
    {
        NEXT(P) = ADDR_HEAD(*q);
        ADDR_HEAD(*q) = P;
        if (ADDR_TAIL(*q) == NIL)
        {
            ADDR_TAIL(*q) = P;
        }
    }
}

void DequeueHead(Deque *q, ElType *x)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    Address P = ADDR_HEAD(*q);
    *x = INFO(P);
    ADDR_HEAD(*q) = NEXT(P);
    free(P);
    if (ADDR_HEAD(*q) == NIL)
    {
        ADDR_TAIL(*q) = NIL;
    }
}

void EnqueueTail(Deque *q, ElType x)
/* Proses: Mengalokasi x dan menambahkan x pada bagian TAIL dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi TAIL, TAIL "mundur" */
{
    Address P = newNode(x);
    if (P != NULL)
    {
        if (ADDR_TAIL(*q) != NIL)
        {
            NEXT(ADDR_TAIL(*q)) = P;
            ADDR_TAIL(*q) = P;
        }
        else
        {
            ADDR_HEAD(*q) = ADDR_TAIL(*q) = P;
        }
    }
}

void DequeueTail(Deque *q, ElType *x)
/* Proses: Menghapus x pada bagian TAIL dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteLast */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen TAIL pd I.S., TAIL "maju" */
{
    Address P = ADDR_HEAD(*q);
    Address prev = NIL;
    while (NEXT(P) != NIL)
    {
        prev = P;
        P = NEXT(P);
    }
    *x = INFO(P);
    if (prev != NIL)
    {
        NEXT(prev) = NIL;
        ADDR_TAIL(*q) = prev;
    }
    else
    {
        ADDR_HEAD(*q) = ADDR_TAIL(*q) = NIL;
    }
    free(P);
}
