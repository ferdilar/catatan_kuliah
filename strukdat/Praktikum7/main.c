#include "header.h"

int main(){
	queue Q;
	int i;
	createEmpty(&Q);
	int n;
	
	scanf("%d", &n);
	char nama;
	for(i=0;i<n;i++){
		scanf(" %c", &nama);
		add(nama,&Q);
	}
	
	
	// printQueue(Q);
	// add(nama[0],&Q);
	// addPrioritas(nama[3],&Q,3);
	// del(&Q);
	
return 0;
}

