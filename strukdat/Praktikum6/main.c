#include "header.h"

int main(){
	stack S1, S2;
	createStack(&S1);
	createStack(&S2);
	
	int huruf[4];
	scanf(" %c", &huruf[0]);
	scanf(" %c", &huruf[1]);
	scanf(" %c", &huruf[2]);
	scanf(" %c", &huruf[3]);

	push(huruf[0],&S1);
	push(huruf[1],&S1);
	push(huruf[2],&S1);
	push(huruf[3],&S1);
	
	// popCari(B);
	
	// popIsi(&S1, &S2);
	// pop(&S1);
	// popIsi(&S2, &S1);
	printStack(S1);
	printStack(S2);
	
return 0;
}

