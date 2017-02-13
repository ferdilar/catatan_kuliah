#include <stdio.h>
#include <string.h>

typedef struct{
	int angka;
}nomer;

typedef struct elmt *alamat;
typedef struct elmt{
	nomer kontainer;
	alamat next;
}elemen;

typedef struct{
	elemen *top;
}stack;

