#include "header.h"

void createEmpty(queue *Q){
	(*Q).first=NULL;
	(*Q).last=NULL;
}
int isEmpty(queue Q){
	int hasil=0;
	if(Q.first == NULL){
		hasil=1;
	}
return hasil;
}

int countElemen(queue Q){
	int hasil=0;
	if(Q.first!= NULL){
		elemen *elmt = Q.first;
		while(elmt != NULL){
			hasil++;
			elmt=elmt->next;
		}
	}return hasil;
}

void add(char nama, queue *Q){
	if(isEmpty(*Q)==1){
		elemen *baru=(elemen*)malloc(sizeof(elemen));
		baru->kontainer.nama=nama;
		baru->next=NULL;
		(*Q).first=baru;
		(*Q).last=baru;
		baru=NULL;
	}else{
		elemen *baru=(elemen*)malloc(sizeof(elemen));
		baru->kontainer.nama=nama;
		baru->next=NULL;
		(*Q).last->next=baru;
		(*Q).last=baru;
	}
}

void del(queue *Q){
	if(isEmpty(*Q)!=1){
		elemen *hapus=(*Q).first;
		if(countElemen(*Q)==1){
			(*Q).first=NULL;
			(*Q).last=NULL;
			free(hapus);
		}else{
			(*Q).first=hapus->next;
			hapus->next=NULL;
			free(hapus);
		}
	}
}

void printQueue(queue Q){
	if(Q.first!=NULL){
		elemen *elmt = Q.first;
		printf("-----------------\n");
		while(elmt!=NULL){
			printf("%c",elmt->kontainer.nama);
			if(elmt->next!=NULL){
				printf(" ");
			}
			elmt=elmt->next;
		}
		printf("\n-----------------\n");
	}else{
		printf("QUEUE kosong\n");
	}
}

void addPrioritas(char nama, queue *Q, int urutan){
	if((isEmpty(*Q)==1)||(urutan>countElemen(*Q))){
		add(nama,Q);
	}else if(urutan==1){
		elemen *baru = (elemen *)malloc(sizeof(elemen));
		baru->kontainer.nama=nama;
		baru->next=NULL;
		baru->next=(*Q).first;
		(*Q).first=baru;
	}else if(urutan<=countElemen(*Q)){
		elemen *tunjuk = (*Q).first;
		int i;
		for(i=2;i<urutan;i++){
			tunjuk=tunjuk->next;
		}
		elemen *baru=(elemen*)malloc(sizeof(elemen));
		baru->kontainer.nama=nama;
		baru->next=NULL;
		baru->next=tunjuk->next;
		tunjuk->next=baru;
	}
}

