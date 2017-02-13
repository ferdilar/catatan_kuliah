#include <stdio.h>
#include <malloc.h>

typedef struct smp* alamatsimpul;
typedef struct jlr* alamatjalur;

typedef struct smp{
	char kota;
	alamatsimpul next;//menghubungkan setiap simpul pada graph walaupun pada gambar graph nya tidak behubungan
	alamatjalur arc;//yang dihub-kan dengan jalur tujuan
}simpul;

typedef struct jlr{//menggunakan prinsip list of list dinamis
	int bobot;
	alamatjalur next;//menghubungkan nya dg jalur selanjutnya pada simpul tersebut
	simpul* tujuan;//mangalamatkan pada simpul lain
}jalur;

typedef struct{
	simpul* first;
}graph;

simpul *findSimpul(char, graph);

