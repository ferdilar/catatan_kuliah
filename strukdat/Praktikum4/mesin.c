#include "header.h"

void createList(list *L){
	(*L).first=NULL;
	(*L).tail=NULL;
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

void addFirst(int no, char nama[], list *L){
	elemen *baru=(elemen*)malloc(sizeof(elemen));
	baru->kontainer.no=no;
	strcpy(baru->kontainer.nama,nama);
	baru->prev=NULL;
	baru->next=NULL;
	if((*L).first==NULL){
		(*L).first=baru;
		(*L).tail=baru;
	}else{
		baru->next=(*L).first;
		(*L).first->prev=baru;
		(*L).first=baru;
	}
}
void addAfter(elemen *sebelum, int no, char nama[], list *L){
	if(sebelum!=NULL){
		elemen *baru=(elemen*)malloc(sizeof(elemen));
		baru->kontainer.no=no;
		strcpy(baru->kontainer.nama,nama);
		baru->prev=NULL;
		baru->next=NULL;
		if(sebelum->next==NULL){
			sebelum->next=baru;
			baru->prev=sebelum;
			(*L).tail=baru;
		}else{
			baru->prev=sebelum;
			baru->next=sebelum->next;
			sebelum->next=baru;
			baru->next->prev=baru;
		}
	}
}

void addLast(int no, char nama[], list *L){
	if((*L).first==NULL){
		addFirst(no,nama,L);
	}else{
		elemen *baru = (elemen*)malloc(sizeof(elemen));
		baru->kontainer.no=no;
		strcpy(baru->kontainer.nama,nama);
		baru->prev=NULL;
		baru->next=NULL;
		baru->prev=(*L).tail;
		(*L).tail->next=baru;
		(*L).tail=baru;
	}
}

void delFirst(list *L){
	if((*L).first!=NULL){
		if(countElemen(*L)==1){
			elemen *hapus=(*L).first;
			(*L).first=NULL;
			(*L).tail=NULL;
			free(hapus);
		}else{
			elemen *hapus=(*L).first;
			(*L).first=hapus->next;
			hapus->next->prev=NULL;
			hapus->next=NULL;
			free(hapus);
		}
	}
}

void delAfter(elemen *sebelum, list *L){
	if(sebelum!=NULL){
		if(sebelum->next!=NULL){
			elemen *hapus=sebelum->next;
			if(hapus->next==NULL){
				sebelum->next=NULL;
				hapus->prev=NULL;
				(*L).tail=sebelum;
				free(hapus);
			}else{
				sebelum->next=hapus->next;
				hapus->next->prev=sebelum;
				hapus->next=NULL;
				hapus->prev=NULL;
				free(hapus);
			}
		}
	}
}

void delLast(list *L){
	if((*L).first!=NULL){
		if(countElemen(*L)==1){
			delFirst(L);
		}else{
			elemen *hapus=(*L).tail;
			(*L).tail=hapus->prev;
			(*L).tail->next=NULL;
			hapus->prev=NULL;
			hapus->next=NULL;
			free(hapus);
		}
	}
}

void printElemen(list L){
	if(L.first != NULL){
		elemen *elmt = L.first;
		// int i = 1;
		while(elmt != NULL){
			// printf("elemen ke: %d\n", i);
			printf("%d %s\n", elmt->kontainer.no, elmt->kontainer.nama);
			elmt = elmt->next;
			// i++;
		}
		// printf("=====\n");
	}else{
		printf("list kosong\n");
		// printf("=====\n");
	}
}

void printelementohead(list L){
	// int i=0;
	// printf("%d\n", countElemen(L));
	if(L.tail!=NULL){
		elemen *elmt = L.tail;
			while(elmt!=NULL){
			printf("%d %s\n", elmt->kontainer.no, elmt->kontainer.nama);
			elmt = elmt->prev;
			}
	}else{
		printf("list kosong\n");
		// printf("-----\n");
	}
	// printf("%d", countElemen(L));
// }
}
	
void delAll(list *L){
	if(countElemen(*L) != 0){
		int i,j=countElemen(*L);
		for(i=j;i>=0;i--){
			delLast(L);
		}
	}
}

