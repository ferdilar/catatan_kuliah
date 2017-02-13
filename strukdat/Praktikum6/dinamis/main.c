#include "header.h"

int main(){
	stack S1, S2;
	createStack(&S1);
	createStack(&S2);
	
	int angka[4];
	scanf("%d", &angka[0]);
	scanf("%d", &angka[1]);
	scanf("%d", &angka[2]);
	scanf("%d", &angka[3]);

	push(angka[0],&S1);
	push(angka[1],&S2);
	popIsi(&S1, &S2);
	printf("s1 - ");
	printStack(S1);
	printf("s2 - ");
	printStack(S2);
	push(angka[2],&S2);
	push(angka[3],&S2);
	pop(&S2);
	popIsi(&S2, &S1);
	printf("s1 - ");
	printStack(S1);
	printf("s2 - ");
	printStack(S2);
	
return 0;
}

