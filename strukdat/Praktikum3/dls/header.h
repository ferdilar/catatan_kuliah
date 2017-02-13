#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[50];
	char nilai[2];
}nilai;

typedef struct{
	nilai kontainer;
	int prev;
	int next;
}elemen;

typedef struct{
	elemen memori[10];
	int first;
	int tail;
}list;

int byk;
