// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Pra-Praktikum 1 Algoritma dan Struktur Data

/* 
TODO:
Buatlah implementasi dari header point.h. Kumpulkan dengan nama point.c
*/


#include <stdio.h>
#include <math.h>
#include "point.h"

#ifndef PI
#define PI   3.141592
#endif

void CreatePoint (POINT * P, float X, float Y) 
{
	POINT s;
	Absis(s) = X;
	Ordinat(s) = Y;
	*P = s;
}

void BacaPOINT (POINT * P) 
{
	float x, y;
	scanf("%f %f", &x, &y);
	CreatePoint(P, x, y);
} 

void TulisPOINT (POINT P) 
{
	printf("(%.2f, %.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2) 
{
	if ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2))) {
		return true;
	}
	else {
		return false;
	}
}

boolean NEQ (POINT P1, POINT P2) 
{
	if ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2))) {
		return false;
	}
	else {
		return true;
	}
}

boolean IsOrigin (POINT P) 
{
	if ((Absis(P) == 0) && (Ordinat(P) == 0)) {
		return true;
	}
	else {
		return false;
	}
}

boolean IsOnSbX (POINT P) 
{
	if (Ordinat(P) == 0) {
		return true;
	}
	else {
		return false;
	}
}

boolean IsOnSbY (POINT P) 
{
	if (Absis(P) == 0) {
		return true;
	}
	else {
		return false;
	}
}

int Kuadran (POINT P) 
{
	if ((Absis(P) > 0) && (Ordinat(P) > 0)) {
		return 1;
	}
	else if ((Absis(P) < 0) && (Ordinat(P) > 0)) {
		return 2;
	}
	else if ((Absis(P) < 0) && (Ordinat(P) < 0)) {
		return 3;
	}
	else if ((Absis(P) > 0) && (Ordinat(P) < 0)) {
		return 4;
	}
}

POINT NextX (POINT P) 
{
	Absis(P)++;
	return P;
}

POINT NextY (POINT P) 
{
	Ordinat(P)++;
	return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) 
{
	Absis(P) += deltaX;
	Ordinat(P) += deltaY;
	return P;
}

POINT MirrorOf (POINT P, boolean SbX) 
{
	POINT P1;
	if (SbX == true) {
		Ordinat(P) *= -1;
	}
	else if (SbX == false) {
		Absis(P) *= -1;
	}
	return P;
}

float Jarak0 (POINT P) 
{
	return sqrt(Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P));
}

float Panjang (POINT P1, POINT P2) 
{
	return sqrt((Absis(P1) - Absis(P2)) * (Absis(P1) - Absis(P2)) + (Ordinat(P1) - Ordinat(P2)) * (Ordinat(P1) - Ordinat(P2)));
}

void Geser (POINT *P, float deltaX, float deltaY) 
{
	POINT s = *P;
	Absis(s) += deltaX;
	Ordinat(s) += deltaY;
	*P = s;
}

void GeserKeSbX (POINT *P) 
{
	POINT s = *P;
	Ordinat(s) = 0;
	*P = s;
}

void GeserKeSbY (POINT *P) 
{
	POINT s = *P;
	Absis(s) = 0;
	*P = s;
}

void Mirror (POINT *P, boolean SbX) 
{
	POINT s = *P;
	if (SbX == true) {
		Ordinat(s) *= -1;
	}
	else if (SbX == false) {
		Absis(s) *= -1;
	}
	*P = s;
}	

void Putar (POINT *P, float Sudut) 
{
    float X, Y;
    X = Absis(*P);
    Y = Ordinat(*P);
    Sudut = Sudut * PI / 180;
    Absis(*P) = X * cos(Sudut) + Y * sin(Sudut);
    Ordinat(*P) = -1 * X * sin(Sudut) + Y * cos(Sudut);
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2) 
{
	int m = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
	int b = Ordinat(P1) - m * Absis(P1);
	printf("(%d,%d)", m, b);
}