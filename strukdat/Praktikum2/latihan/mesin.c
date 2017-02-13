#include "header.h"

void createList(list * L){
	(*L).first= NULL;
}

int countElemen(list L){
	int hasil=0;
	if(L.first!= NULL){
		elemen *elmt = L.first;
		while(elmt != NULL){
			hasil++;
			elmt=elmt->next;
		}
	}return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list * L){
	elemen * baru = (elemen *) malloc(sizeof(elemen));
	strcpy(baru->kontainer.nim,nim);
	strcpy(baru->kontainer.nama,nama);
	strcpy(baru->kontainer.nilai,nilai);
	baru->next = NULL;
	if((*L).first == NULL){
		(*L).first=baru;
	}else{
		baru->next = (*L).first;
		(*L).first=baru;
	}
}

void addAfter(elemen * sebelum, char nim[], char nama[], char nilai[]){
	elemen * baru=(elemen *) malloc(sizeof(elemen));
	strcpy(baru->kontainer.nim,nim);
	strcpy(baru->kontainer.nama,nama);
	strcpy(baru->kontainer.nilai,nilai);
	baru->next = NULL;
	if(sebelum->next == NULL){
		sebelum->next = baru;
	}else{
		baru->next = sebelum->next;
		sebelum->next = baru;
	}

}

void addLast(char nim[], char nama[], char nilai[], list * L){
	elemen * baru = (elemen *) malloc(sizeof(elemen));
	strcpy(baru->kontainer.nim,nim);
	strcpy(baru->kontainer.nama,nama);
	strcpy(baru->kontainer.nilai,nilai);
	baru->next == NULL;
	if((*L).first==NULL){
		addFirst(nim,nama,nilai,L);
	}else{
		elemen * akhir = (*L).first;
		while(akhir->next != NULL){
			akhir=akhir->next;
		}
		akhir->next = baru;
	}
}

void delFirst(list *L){
	if((*L).first != NULL){
		elemen * hapus = (*L).first;
		if(countElemen(*L)==1){
			(*L).first=NULL;
			free(hapus);
		}else{
			(*L).first = hapus->next;
			hapus->next = NULL;
			free(hapus);
		}
	}
}

void delAfter(elemen * sebelum){
	if(sebelum != NULL){
		if(sebelum->next != NULL){
			elemen * hapus = sebelum->next;
			if(hapus->next ==NULL){
				free(hapus);
			}else{
				sebelum->next = hapus->next;
				hapus->next = NULL;
				free(hapus);
			}
		}
	}
}

void delLast(list * L){
	if((*L).first != NULL){
		if(countElemen(*L) == 1){
			delFirst(L);
		}
	else{
		elemen *akhir = (*L).first;
		elemen *sebelum;
		while(akhir->next != NULL){
			sebelum=akhir;
			akhir=akhir->next;
		}
			sebelum->next = NULL;
			free(akhir);
		}
	}
}


void cariElemen(list L, char cari[]){
int status=0;
	if(L.first != NULL){
		elemen *elmt = L.first;
		int i = 1;
		while(elmt != NULL){
			// printf("elemen ke: %d\n", i);
			if(strcmp(elmt->kontainer.nim,cari)==0){
			status=1;
			elmt = elmt->next;
			printf("%s %s %s\n", elmt->kontainer.nim, elmt->kontainer.nama, elmt->kontainer.nilai);
			}
			elmt = elmt->next;
			i++;
		}
		// printf("=====\n");
	}
	if(status==0){
		printf("tidak ditemukan\n");
	
	}
}
	
void delAll(list *L){
	if(countElemen(*L) != 0){
		int i;
		for(i= countElemen(*L);i>=0;i--){
			delLast(L);
		}
	}
}

