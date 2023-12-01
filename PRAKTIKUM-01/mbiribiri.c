// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Praktikum 1 Algoritma dan Struktur Data


#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "garis.h"
#include "point.h"


float distance (GARIS L, POINT P) 
{
	float a = Gradien(L);
    float b = -1;
    float c = (Ordinat(PAwal(L)) - Gradien(L) * Absis(PAwal(L)));
	float atas = a * Absis(P) + b * Ordinat(P) + c;

	if (atas < 0) 
    {
		atas *= -1;
	}

	float bawah = sqrt(pow(a, 2) + pow(b, 2));
	return (atas / (float) bawah);
}


int main () 
{
	float b;
	int i, jumlahSheep, count = 0;
	GARIS wolf;
	POINT sheep;

	scanf("%f", &b);
	scanf(" %f %f", &Absis(PAwal(wolf)), &Ordinat(PAwal(wolf)));
	scanf(" %f %f", &Absis(PAkhir(wolf)), &Ordinat(PAkhir(wolf)));	
	scanf(" %d", &jumlahSheep);

	for (i = 0; i < jumlahSheep; i++) 
    {
		scanf(" %f %f", &Absis(sheep), &Ordinat(sheep));
		if (distance(wolf, sheep) <= b) 
        {
			count++;
		}
	}
	printf("%d\n", count);
}
