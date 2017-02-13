#include "header.h"

int main(){
	list L;
	
	int i,n,sebelum;
	scanf("%d", &n);
	byk=n;
	
	createList(&L);
	
	char dawala[n][50];
	int mid;
	for(i=0;i<n;i++){
		scanf("%s", &dawala[i]);
		if(strcmp(dawala[i],"dawala")==0){
			sebelum = middle(L);
			addAfter(sebelum,dawala[i],&L);
		}else{
			addLast(dawala[i], &L);
		}
	}
	
	printElemen(L);
return 0;
}

