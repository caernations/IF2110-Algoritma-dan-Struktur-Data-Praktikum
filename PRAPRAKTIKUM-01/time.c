// Nama : Yasmin Farisah Salma
// NIM  : 13522140
// Pra-Praktikum 1 Algoritma dan Struktur Data

/* 
TODO:
Buatlah implementasi dari header berikut. Kumpulkan dengan nama time.c
*/


#include <stdio.h>
#include "time.h"

boolean IsTIMEValid (int H, int M, int S) 
{
	if (H < 0 || H > 23 || M < 0 || M > 59 || S < 0 || S > 59) {
		return false;
	}
	else {
		return true;
	}
}

void CreateTime (TIME * T, int HH, int MM, int SS) 
{
	TIME s;
	Hour(s) = HH;
	Minute(s) = MM;
	Second(s) = SS;
	*T = s;
}

void BacaTIME (TIME * T) 
{
	TIME s;
	scanf("%d %d %d", &Hour(s), &Minute(s), &Second(s));
	while (!IsTIMEValid(Hour(s), Minute(s), Second(s))) {
		printf("Jam tidak valid\n");
		scanf(" %d %d %d", &Hour(s), &Minute(s), &Second(s));
	}
	*T = s;
}

void TulisTIME (TIME T) 
{
	printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik (TIME T) 
{
	long detik;
	detik = Hour(T) * 3600 + Minute(T) * 60 + Second(T);
	return detik;
}

TIME DetikToTIME (long N) 
{
	TIME t;
	if (N > 86400) {
		N %= 86400;
	}
	Hour(t) = N / 3600;
	N %= 3600;
	Minute(t) = N / 60;
	N %= 60;
	Second(t) = N;
	return t;
} 

boolean TEQ (TIME T1, TIME T2) 
{
	if (Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2)) {
		return true;		
	}
	else {
		return false;
	}
}

boolean TNEQ (TIME T1, TIME T2) 
{
	if (Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2)) {
		return false;		
	}
	else {
		return true;
	}
}

boolean TLT (TIME T1, TIME T2) 
{
	long d1 = TIMEToDetik(T1), d2 = TIMEToDetik(T2);
	if (d1 < d2) {
		return true;
	}
	else {
		return false;
	}
}

boolean TGT (TIME T1, TIME T2) 
{
	long d1 = TIMEToDetik(T1), d2 = TIMEToDetik(T2);
	if (d1 > d2) {
		return true;
	}
	else {
		return false;
	}
}

TIME NextDetik (TIME T) 
{
	long detik = TIMEToDetik(T);
	detik++;
	return DetikToTIME(detik);
}

TIME NextNDetik (TIME T, int N) 
{
	long detik = TIMEToDetik(T);
	detik += N;
	return DetikToTIME(detik);
}

TIME PrevDetik (TIME T) 
{
	long detik = TIMEToDetik(T);
	detik--;
	return DetikToTIME(detik);
}

TIME PrevNDetik (TIME T, int N) 
{
	long detik = TIMEToDetik(T);
	detik -= N;
	return DetikToTIME(detik);
}

long Durasi (TIME TAw, TIME TAkh) 
{
    int InitTime, FinalTime, Diff;
    InitTime = TIMEToDetik(TAw);
    FinalTime = TIMEToDetik(TAkh);
    Diff  = FinalTime - InitTime;
    if (InitTime > FinalTime) {
        return Diff + 86400;
    }
    else {
        return Diff;
    }
}