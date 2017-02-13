#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[10];
	char nim[20];
	char jk[2];
}nilai;

typedef struct{
	nilai kontainer;
	int next;
}elemen;

typedef struct{
	int first;
	elemen memori[10];
}list;

int bykElemen;
