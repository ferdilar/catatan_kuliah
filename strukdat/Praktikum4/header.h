#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	int no;
	char nama[50];
}nilai;
typedef struct elmt*alamat;typedef struct elmt{
	nilai kontainer;
	alamat prev;
	alamat next;
}elemen;
typedef struct{
	elemen* first;
	elemen* tail;
}list;

