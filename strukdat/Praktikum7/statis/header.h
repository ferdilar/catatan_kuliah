#include <stdio.h>
#include <string.h>

typedef struct{	
	char nama;
}antri;

typedef struct{
	antri data[3];
	int first;
	int last;
}queue;

int byk;
