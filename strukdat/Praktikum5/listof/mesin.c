#include "header.h"

void createList(list *L){
	(*L).firstB=NULL;
}

int countElemenB(list L){
	int hasil=0;
	if(L.firstB!= NULL){
		elemenB *elmtB = L.firstB;
		while(elmtB != NULL){
			hasil++;
			elmtB=elmtB->nextB;
		}
	}
return hasil;
}

int countElemenK(elemenB *tunjuk){
	int hasil=0;
	if(tunjuk != NULL){
		if(tunjuk->firstK != NULL){
			elemenK *maju = tunjuk->firstK;
			while(maju != NULL){
				hasil++;
				maju=maju->nextK;
			}
		}
	}
return hasil;
}

void addFirstB(char grup, list * L){
	elemenB * baru = (elemenB *) malloc(sizeof(elemenB));
	baru->kontainerB.grup=grup;
	baru->nextB = NULL;
	baru->firstK = NULL;
	if((*L).firstB == NULL){
		(*L).firstB=baru;
	}else{
		baru->nextB = (*L).firstB;
		(*L).firstB=baru;
	}
}

void addFirstK(char nama[], elemenB * tunjuk){
	if(tunjuk != NULL){
		elemenK *baru = (elemenK *)malloc(sizeof(elemenK));
		 strcpy(baru->kontainerK.nama,nama);
		baru->nextK = NULL;
		if(tunjuk->firstK == NULL){
			tunjuk->firstK=baru;
		}else{
			baru->nextK = tunjuk->firstK;
			tunjuk->firstK = baru;
		}
	}
}

void addAfterB(elemenB * sebelum, char grup){
	elemenB * baru=(elemenB *) malloc(sizeof(elemenB));
	baru->kontainerB.grup=grup;
	baru->nextB = NULL;
	baru->firstK = NULL;//pentinggg
	if(sebelum->nextB == NULL){
		sebelum->nextB = baru;
	}else{
		baru->nextB = sebelum->nextB;
		sebelum->nextB = baru;
	}

}

void addAfterK(char nama[], elemenK *sebelum){
	if(sebelum != NULL){
		elemenK *baru = (elemenK *)malloc(sizeof(elemenK));
		strcpy(baru->kontainerK.nama,nama);
		baru->nextK = NULL;
		if(sebelum->nextK == NULL){
			sebelum->nextK = baru;
		}else{
			baru->nextK=sebelum->nextK;
			sebelum->nextK=baru;
		}
	}
}

void addLastB(char grup, list * L){
	if((*L).firstB==NULL){
		addFirstB(grup,L);
	}else{
		elemenB * baru = (elemenB *) malloc(sizeof(elemenB));
		baru->kontainerB.grup=grup;
		baru->nextB = NULL;
		baru->firstK = NULL;
		elemenB * akhir = (*L).firstB;
		while(akhir->nextB != NULL){
			akhir=akhir->nextB;
		}
		akhir->nextB = baru;
	}
}

void addLastK(char nama[], elemenB *tunjuk){
	if(tunjuk->firstK == NULL){
		addFirstK(nama,tunjuk);
	}else{
		elemenK *baru = (elemenK *)malloc(sizeof(elemenK));
		strcpy(baru->kontainerK.nama,nama);
		baru->nextK = NULL;
		elemenK *akhir = tunjuk -> firstK;
		while(akhir->nextK != NULL){
			akhir = akhir->nextK;
		}
		akhir->nextK = baru;
	}
}


void delFirstK(elemenB *tunjuk){
	if(tunjuk->firstK != NULL){
		elemenK *hapus = tunjuk->firstK;
		if(countElemenK(tunjuk)==1){
			tunjuk->firstK=NULL;
			free(hapus);
		}else{
			tunjuk->firstK = hapus->nextK;
			hapus->nextK = NULL;
			free(hapus);
		}
	}
}

void delLastK(elemenB *tunjuk){
	if(tunjuk->firstK != NULL){
		if(countElemenK(tunjuk) == 1){
			delFirstK(tunjuk);
		}else{
			elemenK *akhir = tunjuk->firstK;
			elemenK *sebelum;
			while(akhir->nextK != NULL){
				sebelum=akhir;
				akhir=akhir->nextK;
			}
		sebelum->nextK = NULL;
		free(akhir);
		}
	}
}

void delFirstB(list *L){
	if((*L).firstB != NULL){
		elemenB *hapus = (*L).firstB;
		int i,j=countElemenK(hapus);
		for(i=0;i<j;i++){
			delLastK(hapus);
		}
		if(countElemenB(*L) == 1){
			(*L).firstB == NULL;
			free(hapus);
		}else{
			(*L).firstB = hapus->nextB;
			hapus->nextB = NULL;
			free(hapus);
		}
	}
}

void delLastB(list *L){
	if((*L).firstB != NULL){
		if(countElemenB(*L) == 1){
			delFirstB(L);
		}else{
			elemenB *akhir = (*L).firstB;
			elemenB *sebelum;
			int i,j=countElemenK(akhir);
			for(i=0;i<j;i++){
				delLastK(akhir);
			}
			while(akhir->nextB != NULL){
				sebelum=akhir;
				akhir=akhir->nextB;
			}
			sebelum->nextB = NULL;
			free(akhir);
		}
	}
}


	
void delAfterB(elemenB *sebelum, list *L){
	if(sebelum != NULL){
		if(sebelum -> nextB != NULL){
			elemenB *hapus = sebelum->nextB;
			int i,j=countElemenK(hapus);
			for(i=0;i<j;i++){
				delLastK(hapus);
			}
			if(countElemenB(*L) == 1){
				(*L).firstB == NULL;
				free(hapus);
			}else{
				sebelum->nextB = hapus->nextB;//
				hapus->nextB = NULL;
				free(hapus);
			}
		}
	}
}
	
void delAfterK(elemenK *sebelum){
	if(sebelum != NULL){
		if(sebelum->nextK != NULL){
			elemenK *hapus = sebelum->nextK;
			if(hapus->nextK == NULL){
				free(hapus);
			}else{
				sebelum->nextK = hapus->nextK;
				hapus->nextK = NULL;
				free(hapus);
			}
		}
	}
}

void delAllK(elemenB *L){
	if(countElemenK(L) != 0){
		int i,j=countElemenK(L);
		for(i=countElemenK(L);i>=1;i--){
			delLastK(L);  
		}
	}
}

void delAllB(list *L){
	if(countElemenB(*L) != 0){
		int i,j=countElemenB(*L);
		for(i=j;i>=1;i--){
			delLastB(L); 
		}
	}
}

void printElemen(list L){
	if(L.firstB != NULL){
		elemenB *elmtB = L.firstB;
		while(elmtB != NULL){
			//printf
			printf("%c\n", elmtB->kontainerB.grup);
			elemenK *elmtK = elmtB -> firstK;
			while(elmtK != NULL){
				//printf
				printf("%s\n", elmtK->kontainerK.nama);
				elmtK = elmtK->nextK;
			}
			// printf("---------------\n");
			elmtB = elmtB->nextB;
		}
	}else{
		printf("List Kosong\n");
	}
}

