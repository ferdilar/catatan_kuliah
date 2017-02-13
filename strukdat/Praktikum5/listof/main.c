#include "header.h"

int main(){
	list L;
	int n;
	scanf("%d", &n);
	createList(&L);
	int i;
	char huruf;
	char kata[10];
	elemenB * hujan;
	for(i=0;i<n;i++){
	
		scanf(" %c", &huruf);
			addLastB(huruf,&L);
		if(i==0){
			hujan=L.firstB;
		}else{
			hujan= hujan->nextB;
		}
		scanf("%s", &kata);
			addLastK(kata,hujan);
		scanf("%s", &kata);
			addAfterK(kata,hujan->firstK);
			// printf("000");
		scanf("%s", &kata);
			addLastK(kata,hujan);
		scanf("%s", &kata);
			addFirstK(kata,hujan);
			
	}
	printElemen(L);
	
return 0;
}

