#include <stdio.h>
#include <string.h>

typedef struct{
	int no;
	char nama[50];
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
