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

void addFirst(char warna[], int no, list *L){
	elemen *baru=(elemen*)malloc(sizeof(elemen));
	baru->kontainer.no=no;
	strcpy(baru->kontainer.warna,warna);
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
void addAfter(elemen *sebelum, char warna[], int no, list *L){
	if(sebelum!=NULL){
		elemen *baru=(elemen*)malloc(sizeof(elemen));
		baru->kontainer.no=no;
		strcpy(baru->kontainer.warna,warna);
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

void addLast(char warna[], int no, list *L){
	if((*L).first==NULL){
		addFirst(warna,no,L);
	}else{
		elemen *baru = (elemen*)malloc(sizeof(elemen));
		baru->kontainer.no=no;
		strcpy(baru->kontainer.warna,warna);
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
		while(elmt != NULL){
			printf("%s %d\n", elmt->kontainer.warna, elmt->kontainer.no);
			elmt = elmt->next;
		}
	}else{
		printf("list kosong\n");
	}
}

void printelementohead(list L){
	if(L.tail!=NULL){
		elemen *elmt = L.tail;
			while(elmt!=NULL){
			printf("%d %s\n", elmt->kontainer.no, elmt->kontainer.warna);
			elmt = elmt->prev;
			}
	}else{
		printf("list kosong\n");
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

void kombinasi(list *L,list *B){
	int i;
	// for(i=0;i<m+1;i++){
		int j=0,k=0;
		elemen *elmt = (*L).first;
		elemen *cekprev;
		int n=countElemen(*L);
		// printf("%d",n);
		while(j<n && elmt!=NULL){
			if(strcmp(elmt->kontainer.warna,"merah")==0 && elmt->next!=NULL){
				elmt=elmt->next;//elmt 2
				k++;
				cekprev=elmt->prev;//elmt1
				if(cekprev->kontainer.no==elmt->kontainer.no){
					if((strcmp(elmt->kontainer.warna,"merah")==0)&&(elmt->kontainer.no==elmt->next->kontainer.no)&&(strcmp(elmt->next->kontainer.warna,"merah")==0)){
							elmt=elmt->next;//elmt 3
							k++;
							if(elmt->kontainer.no+1<=3){
								addLast(elmt->kontainer.warna,elmt->kontainer.no+1,B);
								// printf("3- merah \n");
								// printElemen(*B);
							}else{
								addLast(elmt->kontainer.warna,elmt->kontainer.no,B);
								// printf("3 merah \n");
								// printElemen(*B);
							}
							elmt=elmt->next;//elmt 4
							k++;
					}else if(strcmp(elmt->kontainer.warna,"kuning")==0){
						addLast("orange",elmt->kontainer.no,B);
						// printf("merah-kuning \n");
						// printElemen(*B);
						elmt=elmt->next;//elmt3
					}else if(strcmp(elmt->kontainer.warna,"biru")==0){
						addLast("ungu",elmt->kontainer.no,B);
						// printf("merah-biru \n");
						// printElemen(*B);
						elmt=elmt->next;//elmt3
					}else{
						addLast(cekprev->kontainer.warna,cekprev->kontainer.no,B);//elmt1
						// printf("batal kombine merah \n");
						// printElemen(*B);
					}
				}else{
					addLast(cekprev->kontainer.warna,cekprev->kontainer.no,B);//elmt1
					// printf("batal merah beda level\n");
					// printElemen(*B);
				}
			}else if(strcmp(elmt->kontainer.warna,"kuning")==0 && elmt->next!=NULL){
				elmt=elmt->next;//elmt 2
				k++;
				cekprev=elmt->prev;//elmt1
				if(cekprev->kontainer.no==elmt->kontainer.no){
					if(elmt->next!=NULL && (strcmp(elmt->kontainer.warna,"kuning")==0)&&(elmt->kontainer.no==elmt->next->kontainer.no)&&(strcmp(elmt->next->kontainer.warna,"kuning")==0)){
							elmt=elmt->next;//elmt 3
							k++;
							if(elmt->kontainer.no+1<=3){
								addLast(elmt->kontainer.warna,elmt->kontainer.no+1,B);
								// printf("3- kuning \n");
								// printElemen(*B);
							}else{
								addLast(elmt->kontainer.warna,elmt->kontainer.no,B);
								// printf("3 kuning \n");
								// printElemen(*B);
							}
							elmt=elmt->next;//elmt 4
							k++;
					}else if(strcmp(elmt->kontainer.warna,"merah")==0){
						addLast("orange",elmt->kontainer.no,B);
						// printf("kuning-merah \n");
						// printElemen(*B);
						elmt=elmt->next;//elmt3
					}else if(strcmp(elmt->kontainer.warna,"biru")==0){
						addLast("hijau",elmt->kontainer.no,B);
						// printf("kuning-biru \n");
						// printElemen(*B);
						elmt=elmt->next;//elmt3
					}else{
						addLast(cekprev->kontainer.warna,cekprev->kontainer.no,B);//elmt1
						// printf("batal kombine kuning \n");
						// printElemen(*B);
					}
				}else{
					addLast(cekprev->kontainer.warna,cekprev->kontainer.no,B);//elmt1
					// printf("batal kuning beda level \n");
					// printElemen(*B);
				}
			}else if(strcmp(elmt->kontainer.warna,"biru")==0 && elmt->next!=NULL){
				elmt=elmt->next;//elmt 2
				k++;
				cekprev=elmt->prev;//elmt1
				if(cekprev->kontainer.no==elmt->kontainer.no){
					if((strcmp(elmt->kontainer.warna,"biru")==0)&&(elmt->kontainer.no==elmt->next->kontainer.no)&&(strcmp(elmt->next->kontainer.warna,"biru")==0)){
							elmt=elmt->next;//elmt 3
							k++;
							if(elmt->kontainer.no+1<=3){
								addLast(elmt->kontainer.warna,elmt->kontainer.no+1,B);
								// printf("3- biru \n");
								// printElemen(*B);
							}else{
								addLast(elmt->kontainer.warna,elmt->kontainer.no,B);
								// printf("3 biru\n");
								// printElemen(*B);
							}
							elmt=elmt->next;//elmt 4
							k++;
					}else if(strcmp(elmt->kontainer.warna,"merah")==0){
						addLast("ungu",elmt->kontainer.no,B);
						// printf("biru-merah\n");
						// printElemen(*B);
						elmt=elmt->next;//elmt3
					}else if(strcmp(elmt->kontainer.warna,"kuning")==0){
						addLast("hijau",elmt->kontainer.no,B);
						// printf("biru kuning\n");
						// printElemen(*B);
						elmt=elmt->next;//elmt3
					}else{
						addLast(cekprev->kontainer.warna,cekprev->kontainer.no,B);//elmt1
						// printf("batal kombine biru\n");
						// printElemen(*B);
					}
				}else{
					addLast(cekprev->kontainer.warna,cekprev->kontainer.no,B);//elmt1
					// printf("batal biru beda level \n");
					// printElemen(*B);
				}
			}else{
				addLast(elmt->kontainer.warna,elmt->kontainer.no,B);
				// printf("buka m-b-k\n");
				// printElemen(*B);
				elmt=elmt->next;//elmt 2
			}
			// printf("elemen B\n");
			// printElemen(*B);
			// printf("%d",j);
			j++;
		}
		// printf("elemen B\n");
		// printElemen(*B);
		
		delAll(L);
		createList(L);//elemen L diperbaharui dengann elemen B
		// printElemen(*L);
		elemen *elmtB=(*B).first;
		while(elmtB!=NULL){
			addLast(elmtB->kontainer.warna,elmtB->kontainer.no,L);
			elmtB=elmtB->next;
		}
		delAll(B);
		createList(B);//elemen B baru untuk dipakai selanjutnya
		// printf("\nelemen B\n");
		// printElemen(*L);
	// }
	
}

