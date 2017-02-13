#include <stdio.h>
#include <string.h>

typedef struct{
	char abjad;
}huruf;

typedef struct elmt *alamat;
typedef struct elmt{
	huruf kontainer;
	alamat next;
}elemen;

typedef struct{
	elemen *top;
}stack;

