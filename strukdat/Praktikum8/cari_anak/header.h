#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp*alamat;
typedef struct smp{
	char kontainer;
	alamat left;
	alamat right;
}simpul;

typedef struct{
	simpul *root;
}tree;

int status;

