#include "header.h"


int main(){
	banyak=3;
	stack S, S2;
	createStack(&S);
	createStack(&S2);
	
	char huruf[5];
	scanf(" %c", &huruf[0]);
	scanf(" %c", &huruf[1]);
	scanf(" %c", &huruf[2]);
	scanf(" %c", &huruf[3]);
	scanf(" %c", &huruf[4]);
	
	push(huruf[0],&S);
	push(huruf[1],&S);
	printStack(S);
	push(huruf[2],&S);
	push(huruf[3],&S);
	printStack(S);
	pop(&S);
	pop(&S);
	push(huruf[4],&S);
	printStack(S);
	
	// popIsi(&S, &S2);
	
	
	
	printStack(S2);
return 0;
}

