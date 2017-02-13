#include "header.h"

typedef struct{
  int no;
  char nam[30];
}data;

int main(){
	list L;
	byk=10;
	createList(&L);
	
	int i;
	
	data asdos[7];

	for(i=0;i<7;i++){
		scanf("%d %s", &asdos[i].no, &asdos[i].nam);
	}
  
	addLast(asdos[0].no, asdos[0].nam,&L);
	addFirst(asdos[1].no, asdos[1].nam,&L);
	addAfter(L.first,asdos[2].no, asdos[2].nam,&L);
	// printf("\n");
	printElemen(L);
	delAfter(L.first, &L);
	delLast(&L);
	delFirst(&L);
	printelementohead(L);
	addFirst(asdos[3].no, asdos[3].nam,&L);
	addLast(asdos[4].no, asdos[4].nam,&L);
	addFirst(asdos[5].no, asdos[5].nam,&L);
	addAfter(L.first,asdos[6].no, asdos[6].nam,&L);
	printElemen(L);
return 0;
}

