#include "header.h"

int main(){
	queue Q;
	int i;
	createEmpty(&Q);
	
	char nama[7];
	for(i=0;i<7;i++){
		scanf(" %c", &nama[i]);
	}
	
	printQueue(Q);
	add(nama[0],&Q);
	add(nama[1],&Q);
	add(nama[2],&Q);
	addPrioritas(nama[3],&Q,3);
	add(nama[4],&Q);
	printQueue(Q);
	del(&Q);
	del(&Q);
	del(&Q);
	printQueue(Q);
	addPrioritas(nama[5],&Q,2);
	add(nama[6],&Q);
	printQueue(Q);
	
return 0;
}

