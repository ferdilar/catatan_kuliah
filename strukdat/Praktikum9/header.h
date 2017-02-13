#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp *alamat;
typedef struct smp{
	char kontainer;
	alamat sibling;
	alamat child;
}simpul;

typedef struct{
	simpul *root;
}tree;

