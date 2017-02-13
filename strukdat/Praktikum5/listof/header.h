#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char grup;
}kelompok;

typedef struct{
	char nama[30];
}anggota;

typedef struct elmtK * alamatK;
typedef struct elmtK{
	anggota kontainerK;
	alamatK nextK;
}elemenK;

typedef struct elmtB * alamatB;
typedef struct elmtB{
	kelompok kontainerB;
	elemenK * firstK;
	alamatB nextB;
}elemenB;

typedef struct{
	elemenB * firstB;
}list;

