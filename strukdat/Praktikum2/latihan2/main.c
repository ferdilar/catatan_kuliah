#include "header.h"

int main(){
	list L;
	
	createList(&L);
	
	  	
	
	
	// printf("\n");
	addFirst("L-FPMIPA","Lemari","120",&L);
	addLast("N-FIP","Kursi","500",&L);
	addFirst("D-FPBS","Komputer","100",&L);
	addAfter(L.first->next->next,"Li-FPMIPA","Meja","300",&L);
	addFirst("E-FPEB","Papan","80",&L); 
	char cari[100];
	scanf(" %s", &cari);
	
	printf("cari akan ditambahkan setelah apaa:\n");
	
	
	char kode[10];
	char nama[50];
	char jumlah[5];
	
	
	scanf(" %s %s %s", &kode,&nama,&jumlah);
	
	int ke;
	cariElemen(L,cari,kode,nama,jumlah);
	printElemen(L);
	
	  

 
	
	
	// printElemen(L);
	// printf("=========\n");
	// addFirst("Ferdila","1202315","8",&L);
	// addAfter(L.first,"Melani","120000","9",&L);
	// addLast("Putri","1200090","9",&L);
	// printElemen(L);
	// printf("===========\n");
	
	// delLast(&L);
	// delAfter(L.first, &L);
	// delFirst(&L);
	// printElemen(L);
	// printf("===========\n");
	

return 0;
}



