#include "header.h"

void createList(list *L){
	(*L).first=-1;
	(*L).tail=-1;
	int i;
	for(i=0;i<byk;i++){
		(*L).memori[i].prev=-2;
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
	if(countElemen(L)<byk){
		int ketemu=0;
		int i=0;
		while(ketemu==0 && i<byk){
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

void addFirst(char nama[], list *L){
	if(countElemen(*L)<byk){
		int baru=emptyElemen(*L);//pointer
		strcpy((*L).memori[baru].kontainer.kata,nama);
		(*L).memori[baru].next=-1;
		(*L).memori[baru].prev=-1;
		
		if((*L).first==-1){
			(*L).first=baru;
			(*L).tail=baru;
		}else{
			(*L).memori[baru].next=(*L).first;
			(*L).memori[(*L).first].prev=baru;
			(*L).first=baru;
		}
	}
}

void addAfter(int sebelum, char nama[], list *L){
	if(sebelum!=-1){
		if(countElemen(*L)<byk){
			int baru=emptyElemen(*L);
		strcpy((*L).memori[baru].kontainer.kata,nama);
			(*L).memori[baru].next=-1;
			(*L).memori[baru].prev=-1;
			if((*L).memori[sebelum].next==-1){
				(*L).memori[sebelum].next=baru;
				(*L).memori[baru].prev=sebelum;
				(*L).tail=baru;
			}else{
				(*L).memori[baru].next=(*L).memori[sebelum].next;
				(*L).memori[baru].prev=sebelum;
				(*L).memori[sebelum].next=baru;
				(*L).memori[(*L).memori[baru].next].prev=baru;
			}
		}
	}
}


void addLast(char nama[], list *L){
	if((*L).first==-1){
		addFirst(nama,L);
	}else{
		if(countElemen(*L)<byk){
			int baru=emptyElemen(*L);
		strcpy((*L).memori[baru].kontainer.kata,nama);
			(*L).memori[baru].next=-1;
			(*L).memori[baru].prev=-1;
			(*L).memori[baru].prev=(*L).tail;
			(*L).memori[(*L).tail].next=baru;
			(*L).tail=baru;
		}
	}
}


void delFirst(list *L){
	if((*L).first!=-1){
		if(countElemen(*L)==1){
			int hapus=(*L).first;
			(*L).first=-1;
			(*L).tail=-1;
			(*L).memori[hapus].prev=-2;
			(*L).memori[hapus].next=-2;
		}else{
			int hapus=(*L).first;
			(*L).first=(*L).memori[hapus].next;
			(*L).memori[(*L).first].prev=-1;
			(*L).memori[hapus].prev=-2;
			(*L).memori[hapus].next=-2;
		}
	}
}

void delAfter(int sebelum, list *L){
	if(sebelum!=-1){
		if((*L).memori[sebelum].next!=-1){
			int hapus=(*L).memori[sebelum].next;
			if((*L).memori[hapus].next==-1){
				(*L).memori[sebelum].next=-1;
				(*L).memori[hapus].prev=-2;
				(*L).memori[hapus].next=-2;
				(*L).tail=sebelum;
			}else{
				(*L).memori[sebelum].next=(*L).memori[hapus].next;
				(*L).memori[(*L).memori[hapus].next].prev=sebelum;
				(*L).memori[hapus].prev=-2;
				(*L).memori[hapus].next=-2;
			}
		}
	}
}

void delLast(list *L){
	if(countElemen(*L)==1){
		delFirst(L);
	}else{
		int hapus=(*L).tail;
		(*L).tail=(*L).memori[hapus].prev;
		(*L).memori[(*L).tail].next=-1;
		(*L).memori[hapus].prev=-2;
		(*L).memori[hapus].next=-2;
	}
}


void printElemen(list L){
	int i=0;
	// printf("%d\n", countElemen(L));
	if(L.first!=-1){
		int elemen,elemen2;
		int panjang=0;
		int i;
		elemen=L.first;
		elemen2=L.tail;
			while(elemen!=-1){
				for(i=0;i<panjang;i++){
					printf(" ");
				}
				printf("%s\n", (L).memori[elemen].kontainer.kata);
				elemen=L.memori[elemen].next;
				panjang=L.memori[elemen2].prev;
				elemen2=L.memori[elemen2].prev;
			}
	}else{
		printf("list kosong\n");
		
	}
}

int middle(list L){
	int middle = countElemen(L)/2;
	int i;
	int elemen;
	elemen=L.first;
	while(i<middle-1){
		elemen=L.memori[elemen].next;
		i++;
	}
return elemen;
}

