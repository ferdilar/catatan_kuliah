#include "header.h"

int main(){
	list L;
	
	createList(&L);
	
	//udh coba pake array tp ga bs
	char nim1[10];
	char nama1[50];
	char nilai1[5];
	
	char nim2[10];
	char nama2[50];
	char nilai2[5];
	
	char nim3[10];
	char nama3[50];
	char nilai3[5];
	
	char nim4[10];
	char nama4[50];
	char nilai4[5];
	
	char nim5[10];
	char nama5[50];
	char nilai5[5];
	scanf(" %s %s %s", &nim1,&nama1,&nilai1);
	scanf(" %s %s %s", &nim2,&nama2,&nilai2);
	scanf(" %s %s %s", &nim3,&nama3,&nilai3);
	scanf(" %s %s %s", &nim4,&nama4,&nilai4);
	scanf(" %s %s %s", &nim5,&nama5,&nilai5);
	// printf("\n");
	addFirst(nim1,nama1,nilai1,&L);
	addLast(nim2,nama2,nilai2,&L);
	addFirst(nim3,nama3,nilai3,&L);
	addAfter(L.first->next->next,nim4,nama4,nilai4,&L);

	printElemen(L);
	delLast(&L);
	delFirst(&L);
	printElemen(L);
	
	
	addFirst(nim5,nama5,nilai5,&L); 
	delAfter(L.first, &L);
	printElemen(L);

	delAll(&L);
	printElemen(L);
	
	// printElemen(L);
	// printf("=========\n");
	// addFirst("Ferdila","1202315","8",&L);
	// addAfter(L.first,"Melani","120000","9",&L);
	// addLast("Putri","1200090","9",&L);
	// printElemen(L);
	// printf("===========\n");
	
	// delLast(&L);
	// delAfter(L.first, &L);
	// delFirst(&L);
	// printElemen(L);
	// printf("===========\n");
	

return 0;
}



