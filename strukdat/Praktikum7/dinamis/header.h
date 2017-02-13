#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{	
	char nama;
}antri;
typedef struct elmt*alamat;
typedef struct elmt{
	antri kontainer;
	alamat next;
}elemen;

typedef struct{
	elemen *first;
	elemen *last;
}queue;

