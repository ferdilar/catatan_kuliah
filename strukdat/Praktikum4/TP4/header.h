#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*Saya FerdilaRahmi tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan TP4, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

typedef struct{
	int no;
	char warna[50];
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

int n,m;
typedef struct{
	int dari;
	int ke;
}pindah;

