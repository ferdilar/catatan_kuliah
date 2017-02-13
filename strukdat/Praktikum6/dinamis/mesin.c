#include "header.h"

void createStack(stack *S){
	(*S).top = NULL;
}

int isEmpty(stack S){
	int hasil = 0;
	if(S.top == NULL){
		hasil = 1;
	}
	return hasil;
}

int countElemen(stack S){
	int hasil=0;
	if(S.top != NULL){
		elemen *elmt = S.top;
		while(elmt != NULL){
			hasil++;
			elmt=elmt->next;
		}
	}return hasil;
}
void push(int angka, stack *S){
	elemen *baru = (elemen*)malloc(sizeof(elemen));
	baru->kontainer.angka=angka;
	baru->next = NULL;
	if(isEmpty(*S) == 1){
		(*S).top = baru;
	}else{
		baru->next = (*S).top;
		(*S).top = baru;
	}
}

void pop(stack *S){
	if((*S).top != NULL){
		elemen *hapus = (*S).top;
		(*S).top = (*S).top->next;
		hapus->next = NULL;
		free(hapus);
	}
}

void printStack(stack S){
	if(S.top != NULL){
		elemen *elmt = S.top;
		int i = countElemen(S);
		
		while(elmt != NULL){
			printf("%d", elmt->kontainer.angka);
			if(elmt->next!=NULL){
				printf(" ");
			}
			elmt=elmt->next;
		}
		printf("\n");
	}else{
		printf("Stack Kosong\n");
	}
}

void popIsi(stack *S, stack *S2){
	if(isEmpty(*S) == 0){
		push((*S).top->kontainer.angka, S2);
		pop(&(*S));
	}
}



		


	
