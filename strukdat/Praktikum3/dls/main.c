#include "header.h"

int main(){
	list L;
	byk=10;
	createList(&L);
	
	int n,i;
	scanf("%d", &n);
	
	nilai mhs[n];

	for(i=0;i<n;i++){
		scanf("%s %s %s", &mhs[i].nim, &mhs[i].nama, &mhs[i].nilai);
	}
  
	for(i=0;i<n;i++){
		addLast(mhs[i].nim, mhs[i].nama, mhs[i].nilai, &L);
	}
	
	// char nim1[10];
	// char nama1[50];
	// char jk1[5];
	
	// char nim2[10];
	// char nama2[50];
	// char jk2[5];
	
	// char nim3[10];
	// char nama3[50];
	// char jk3[5];
	
	// char nim4[10];
	// char nama4[50];
	// char jk4[5];
	
	// scanf("%s %s %s", &nama1,&nim1,&jk1);
	// scanf(" %s %s %s", &nama2,&nim2,&jk2);
	// scanf(" %s %s %s", &nama3,&nim3,&jk3);
	// scanf(" %s %s %s", &nama4,&nim4,&jk4);
	
	printf("\n");
	// addLast(nama1,nim1,jk1,&L);
	// addFirst(nama2,nim2,jk2,&L);
	// addAfter(L.first,nama3,nim3,jk3,&L);
	// printElemen(L);
	// delLast(&L);
	// printElemen(L);
	// addLast(nama4,nim4,jk4,&L);
	// printElemen(L);
	// delAfter(L.memori[L.first].next, &L);
	// delLast(&L);
	// printElemen(L);
	// delFirst(&L);
	printElemen(L);
	
return 0;
}

