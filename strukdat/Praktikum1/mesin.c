#include "header.h"

void createList(list * L){
	(*L).first=-1;
	int i;
	for(i=0;i<bykElemen;i++){
		(*L).memori[i].next=-2;
	}
}

int countElemen(list L){
	int hasil=0;
	if(L.first!=-1){
		int elemen;
		elemen=L.first;
			while(elemen!=-1){
				hasil++;
				elemen=L.memori[elemen].next;
			}
		}
		// printf("hasiiiiiiiiiiil=%d\n", hasil);
	return hasil;
}

int emptyElemen(list L){
	int hasil=0;
	if(countElemen(L)<bykElemen){
		int ketemu=0;
		int i=0;
		while(ketemu==0 && i<bykElemen){
			if(L.memori[i].next==-2){
				hasil = i;
				ketemu=1;
			}else{
				i++;
			}
		}
	}
	return hasil;
}

void addFirst(char nama[], char nim[], char jk[], list *L){
	if(countElemen(*L)<bykElemen){
		int baru = emptyElemen(*L);
		strcpy((*L).memori[baru].kontainer.nim,nim);
		strcpy((*L).memori[baru].kontainer.nama,nama);
		strcpy((*L).memori[baru].kontainer.jk,jk);
		if((*L).first==-1){
			(*L).first=baru;
			(*L).memori[baru].next=-1;	
		}else{
			(*L).memori[baru].next=(*L).first;
			(*L).first=baru;
		}
	}
}

void addLast(char nama[], char nim[], char jk[], list * L){
	if(countElemen(*L)<bykElemen){
		int baru = emptyElemen(*L);
		strcpy((*L).memori[baru].kontainer.nim,nim);
		strcpy((*L).memori[baru].kontainer.nama,nama);
		strcpy((*L).memori[baru].kontainer.jk,jk);
		if((*L).first==-1){
			addFirst(nama,nim,jk,L);
		}else{
			int akhir=(*L).first;
			while((*L).memori[akhir].next!=-1){
				akhir=(*L).memori[akhir].next;
			}
			(*L).memori[akhir].next=baru;
			(*L).memori[baru].next=-1;
		}
	}
}

void addAfter(int sebelum, char nama[], char nim[], char jk[], list * L){
	if(countElemen(*L)<bykElemen){
		int baru = emptyElemen(*L);
		strcpy((*L).memori[baru].kontainer.nim,nim);
		strcpy((*L).memori[baru].kontainer.nama,nama);
		strcpy((*L).memori[baru].kontainer.jk,jk);
		
		if((*L).memori[sebelum].next==-1){
			(*L).memori[baru].next=-1;
			(*L).memori[sebelum].next=baru;
		}else{
			(*L).memori[baru].next=(*L).memori[sebelum].next;
			(*L).memori[sebelum].next=baru;
		}
	}
}

void delFirst(list * L){
	if((*L).first!=-1){
		int hapus=(*L).first;
		if(countElemen(*L)==1){
			(*L).first=-1;
			(*L).memori[hapus].next=-2;
		}else{
			(*L).first=(*L).memori[hapus].next;
			(*L).memori[hapus].next=-2;
		}	
	}
}

void delAfter(int sebelum, list * L){
	if(sebelum!=1){
		if((*L).memori[sebelum].next!=-1){
			int hapus = (*L).memori[sebelum].next;
			if((*L).memori[hapus].next==-1){
				(*L).memori[sebelum].next=-1;
				(*L).memori[hapus].next=-2;
			}else{
				(*L).memori[sebelum].next=(*L).memori[hapus].next;
				(*L).memori[hapus].next=-2;
			}
		}
	}
}

void delLast(list * L){
	if(countElemen(*L)==1){
		delFirst(L);
	}else{
		int hapus=(*L).first;
		int sebelum =-1;
		while((*L).memori[hapus].next!=-1){
			sebelum=hapus;
			hapus = (*L).memori[hapus].next;
		}
		(*L).memori[sebelum].next=-1;
		(*L).memori[hapus].next=-2;
	}
}

delAll(list * L){
	int i;
	for(i=0;i<bykElemen;i++){
		delLast(L);
	}
}

void printElemen(list L){

	int i=0;
	// printf("%d\n", countElemen(L));
	

	if(countElemen(L)>0){
		int elemen;
		elemen=L.first;
			while(elemen!=-1){
				printf("%s ", (L).memori[elemen].kontainer.nama);
				printf("%s ", (L).memori[elemen].kontainer.nim);
				printf("%s\n", (L).memori[elemen].kontainer.jk);
				i++;
				elemen=L.memori[elemen].next;
			}
	
	
		// while(i=0;i<countElemen(L);i++){
			// printf("%d\n",i);
			// printf("%s ", (L).memori[i].kontainer.nama);
			// printf("%s ", (L).memori[i].kontainer.nim);
			// printf("%s\n", (L).memori[i].kontainer.jk);
	
		printf("-----\n");
	}else{
		printf("List Kosong\n");
		printf("-----\n");
	}
	// printf("%d", countElemen(L));
// }
}


