// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 1 Algoritma dan Struktur Data

/* 
TODO:
Buatlah implementasi dari header file berikut dengan memanfaatkan ADT Point. 
Anda cukup mengumpulkan file implementasi ADT Garis saja. 
*/


#include "garis.h"
#include "point.h"
#include <stdio.h>
#include <math.h>


void CreateGaris(GARIS *L, POINT P1, POINT P2) {
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}


void BacaGARIS(GARIS * L)
{
    BacaPOINT(&PAwal(*L));
    BacaPOINT(&PAkhir(*L));
    while(EQ(PAwal(*L),PAkhir(*L)))
    {
        printf("Garis tidak valid\n");
        BacaPOINT(&PAwal(*L));
        BacaPOINT(&PAkhir(*L));
    }
    CreateGaris(L,PAwal(*L),PAkhir(*L));
}

void TulisGARIS(GARIS L) {
    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
    printf(")");
}


float PanjangGARIS (GARIS L)
{
    float x1, y1, x2, y2;
    x1 = Absis(PAwal(L));
    y1 = Ordinat(PAwal(L));
    x2 = Absis(PAkhir(L));
    y2 = Ordinat(PAkhir(L));
    return(sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)));
}

float Gradien (GARIS L)
{   
    return ((Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L))));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY)
{
    Geser(&PAwal(*L), deltaX, deltaY);
    Geser(&PAkhir(*L), deltaX, deltaY);
}

boolean IsTegakLurus(GARIS L1, GARIS L2) {
    return (Gradien(L1) * Gradien (L2) == -1);
}

boolean IsSejajar(GARIS L1, GARIS L2) {
    return (Gradien(L1) == Gradien(L2));
}


float JarakGARIS(GARIS L, POINT P) {
    float a, b, c;
    a = Ordinat(PAwal(L)) - Ordinat(PAkhir(L));
    b = Absis(PAkhir(L)) - Absis(PAwal(L));
    c = Absis(PAwal(L)) * Ordinat(PAkhir(L)) - Absis(PAkhir(L)) * Ordinat(PAwal(L));
    return (a * Absis(P) + b * Ordinat(P) + c) / sqrt(a * a + b * b);
}

boolean IsPointMemenuhiGaris (GARIS L, POINT P) {
	float a = Gradien(L), b = -1, c = (Ordinat(PAwal(L)) - Gradien(L)*Absis(PAwal(L)));	
	if (a * Absis(P) + b * Ordinat(P) + c == 0) {
		return true;
	}
	else {
		return false;
	}
}