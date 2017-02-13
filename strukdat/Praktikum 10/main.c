#include "header.h"

int main(){
	graph G;
	
	createEmpty(&G);
	addSimpul('A', &G);
	addSimpul('B', &G);
	addSimpul('C', &G);
	addSimpul('D', &G);
	addSimpul('E', &G);
	////////////////////////////
	//////////////////////////////////
	simpul *awal = findSimpul('A',G);
	simpul *akhir = findSimpul('D',G);
	
	if((awal!=NULL) && (akhir!=NULL)){
		addJalur(awal,akhir);
	}
	////////////////////////////////////////////////////
	
	//////////////////////////////////
	awal = findSimpul('A',G);
	akhir = findSimpul('E',G);
	
	if((awal!=NULL) && (akhir!=NULL)){
		addJalur(awal,akhir);
	}
	////////////////////////////////////////////////////
	
	//////////////////////////////////
	awal = findSimpul('B',G);
	akhir = findSimpul('A',G);
	
	if((awal!=NULL) && (akhir!=NULL)){
		addJalur(awal,akhir);
	}
	////////////////////////////////////////////////////
	
	
	//////////////////////////////////
	awal = findSimpul('B',G);
	akhir = findSimpul('C',G);
	
	if((awal!=NULL) && (akhir!=NULL)){
		addJalur(awal,akhir);
	}
	////////////////////////////////////////////////////
	
	//////////////////////////////////
	awal = findSimpul('E',G);
	akhir = findSimpul('B',G);
	
	if((awal!=NULL) && (akhir!=NULL)){
		addJalur(awal,akhir);
	}
	////////////////////////////////////////////////////
	
	printGraph(G);
	
	// delJalur(awal,akhir);
	// printf("hapus jalur\n");
	// printGraph(G);
	////////////////////////////
	delSimpul('B',&G);
	printGraph(G);
	// printf("sjhsjfs\n");
	return 0;
}

