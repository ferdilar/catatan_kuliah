#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[50];
	char nilai[5];
}nilai;

typedef struct elmt*alamatelmt;

typedef struct elmt{
	nilai kontainer;
	alamatelmt next;
}elemen;

typedef struct{
	elemen * first;
}list;

