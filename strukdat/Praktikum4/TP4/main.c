#include "header.h"

int main(){
	list L;
	list B;
	createList(&L);
	createList(&B);
	
	int i;
	
	char nama[50];
	int lvl;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf(" %s %d ", &nama, &lvl);
		addLast(nama,lvl,&L);
	}
	scanf("%d", &m);
	pindah data[m];
	for(i=0;i<m;i++){
		scanf("%d %d", &data[i].dari, &data[i].ke);
	}
	// printf("\n");
	// for(i=0;i<m;i++){
		// printf("%d %d\n", data[i].dari, data[i].ke);
	// }
	int k;
	for(i=0;i<m+1;i++){
		if(i==0){
		kombinasi(&L,&B);
		printf("\n");
		printElemen(L);
		}else{
			elemen *elmt = (L).first;
			elemen *dulu;
			elemen *skrg;
			k=0;
			char temp[50];
			int no_temp;
			
			while(elmt!=NULL){
				k++;
				if(k==data[i-1].dari){
					dulu = elmt;
				}
				if(k==data[i-1].ke){
					skrg = elmt;
				}
				elmt=elmt->next;
			}
					strcpy(temp,dulu->kontainer.warna);
					no_temp = dulu->kontainer.no;
					if(dulu == L.first){
						delFirst(&L);
					}else{
						delAfter(dulu->prev,&L);
					}
					if(skrg == L.first){
						addFirst(temp,no_temp,&L);
					}else{
						addAfter(skrg->prev,temp,no_temp,&L);
					}
			kombinasi(&L,&B);		
			printf("\n");
			printElemen(L);
		}
		
	}
	
  // printf("selesai");
// addLast(asdos[0].no, asdos[0].nama,&L);
// addFirst(asdos[1].no, asdos[1].nama,&L);
// addAfter(L.first,asdos[2].no, asdos[2].nama,&L);
// printElemen(L);
// delAfter(L.first, &L);
// delLast(&L);
// delFirst(&L);
// printf("\n");
// printElemen(L);
// addFirst(asdos[3].no, asdos[3].nama,&L);
// addLast(asdos[4].no, asdos[4].nama,&L);
// addFirst(asdos[5].no, asdos[5].nama,&L);
// addAfter(L.first -> next -> next -> prev,asdos[6].no, asdos[6].nama,&L);
// printelementohead(L);
return 0;
}

