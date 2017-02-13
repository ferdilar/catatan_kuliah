#include "header.h"

void createEmpty(graph* G){
	(*G).first=NULL;
}

void addSimpul(char c, graph* G){
	simpul* baru;
	baru=(simpul*)malloc(sizeof(simpul));
	baru->kota=c;
	baru->next=NULL;
	baru->arc=NULL;
	if((*G).first==NULL){
		(*G).first=baru;
	}else{
		simpul* akhir=(*G).first;
		while(akhir->next!=NULL){
			akhir=akhir->next;
		}
		akhir->next=baru;
	}
}

void addJalur(simpul* awal, simpul* tujuan){
	if((awal!=NULL)&&(tujuan!=NULL)){
		if(awal->arc==NULL){
			jalur *baru=(jalur*)malloc(sizeof(jalur));
			baru->tujuan=tujuan;
			baru->next=NULL;
			awal->arc=baru;
		}else{
			int status=0;
			jalur* cek=awal->arc;
			while((status==0)&&(cek!=NULL)){
				if(cek->tujuan==tujuan){
					status=1;
				}else{
					cek=cek->next;
				}
			}
			if(status==0){
				jalur* baru=(jalur*)malloc(sizeof(jalur));
				baru->next=NULL;
				baru->tujuan=tujuan;
				jalur* akhir=awal->arc;
				while(akhir->next!=NULL){
					akhir=akhir->next;
				}
				akhir->next=baru;
			}
		}
	}
}

simpul* findSimpul(char c, graph G){
	simpul *hasil=NULL;
	simpul *cari=G.first;
	
	int status=0;
	while((cari!=NULL)&&(status==0)){
		if(cari->kota==c){
			hasil=cari;
			status=1;
		}else{
			cari=cari->next;
		}
	}
	return hasil;
}

void delJalur(simpul* awal, simpul* tujuan){
	if((awal!=NULL)&&(tujuan!=NULL)){
		int status=0;
		jalur* cari=awal->arc;
		jalur* sebelum=NULL;
		while((cari!=NULL)&&(status==0)){
			if(cari->tujuan==tujuan){
				status=1;
			}else{
				sebelum=cari;
				cari=cari->next;
			}
		}
		if(status==1){
			if(awal->arc->next==NULL){
				cari->tujuan=NULL;
				awal->arc=NULL;
				free(cari);
			}else{
				if(awal->arc==cari){
					sebelum->next=cari->next;
					cari->tujuan=NULL;
					cari->next=NULL;
					free(cari);
				}else if(cari->next!=NULL){
					sebelum->next=cari->next;
					cari->tujuan=NULL;
					cari->next=NULL;
					free(cari);
				}else{
					sebelum->next=NULL;
					cari->tujuan=NULL;
					free(cari);
				}
			}
		}
	}
}

void delSimpul(char kota, graph* G){
	simpul* cari=(*G).first;
	simpul* sebelum=NULL;
	int status=0;
	while((cari!=NULL)&&(status==0)){
		if(cari->kota==kota){
			status=1;
		}else{
			sebelum=cari;
			cari=cari->next;
		}
	}
	if(status==1){
		simpul* jalan=(*G).first;
		while(jalan!=NULL){
			if(jalan!=cari){
				delJalur(jalan,cari);
			}
			jalan=jalan->next;
		}
		jalur* hapus=NULL;
		jalur* cek=cari->arc;
		while(cek!=NULL){
			hapus=cek;
			cek=cek->next;
			hapus->tujuan=NULL;
			hapus->next=NULL;
			cari->arc=cek;
			free(hapus);
		}
		if((*G).first->next==NULL){
			(*G).first=NULL;
			free(cari);
		}else{
			if((*G).first==cari){
				(*G).first=cari->next;
				cari->next=NULL;
				free(cari);
			}else if(cari->next!=NULL){
				sebelum->next=cari->next;
				cari->next=NULL;
				free(cari);
			}else{
				sebelum->next=NULL;
				free(cari);
			}
		}
	}
}

void printGraph(graph G){
	simpul *cari=G.first;
	if(cari!=NULL){
		while(cari!=NULL){
			printf("Node %c\n", cari->kota);
			jalur *arc = cari->arc;
			while(arc!=NULL){
				printf("Jalur %c ke %c\n", cari->kota, arc->tujuan->kota);
				arc=arc->next;
			}
			cari=cari->next;
		}
	}else{
		printf("graph kosong\n");
	}
}


		
