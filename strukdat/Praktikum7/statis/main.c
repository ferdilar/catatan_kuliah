#include "header.h"

int main(){
	queue Q;
	int i;
	byk=3;
	createEmpty(&Q);
	
	char nama[byk];
	for(i=0;i<8;i++){
		scanf(" %c", &nama[i]);
	}
	
	printQueue(Q);
	add(nama[0],&Q);
	add(nama[1],&Q);
	addBerprioritas(nama[2],&Q,3);
	printQueue(Q);
	add(nama[3],&Q);
	printQueue(Q);
	del(&Q);
	del(&Q);
	del(&Q);
	add(nama[4],&Q);
	add(nama[5],&Q);
	addBerprioritas(nama[6],&Q,2);
	printQueue(Q);
	del(&Q);
	add(nama[7],&Q);
	printQueue(Q);
	
return 0;
}

