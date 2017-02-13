#include "header.h"

int main(){
	list L;
	createList(&L);
	
	int i;
	
	nilai asdos[7];

	for(i=0;i<7;i++){
		scanf("%d %s", &asdos[i].no, &asdos[i].nama);
	}
  
addLast(asdos[0].no, asdos[0].nama,&L);
addFirst(asdos[1].no, asdos[1].nama,&L);
addAfter(L.first,asdos[2].no, asdos[2].nama,&L);
printElemen(L);
delAfter(L.first, &L);
delLast(&L);
delFirst(&L);
printElemen(L);
addFirst(asdos[3].no, asdos[3].nama,&L);
addLast(asdos[4].no, asdos[4].nama,&L);
addFirst(asdos[5].no, asdos[5].nama,&L);
addAfter(L.first -> next -> next -> prev,asdos[6].no, asdos[6].nama,&L);
printelementohead(L);
return 0;
}

