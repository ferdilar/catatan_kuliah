#include "header.h"


void createStack(stack *S){
	(*S).top=-1;
}

int isEmpty(stack S){
	int hasil = 0;
	if(S.top == -1){
		hasil=1;
	}
	return hasil;
}

int isFull(stack S){
	int hasil = 0;
	if(S.top == (banyak-1)){
		hasil = 1;
	}
	return hasil;
}

void push(char abjad, stack *S){
	if(isFull(*S) != 1){
		(*S).top++;//top pointer
		(*S).data[(*S).top].abjad=abjad;
	}else{
		printf("Stack Overflow\n");
	}
}

// mahasiswa pop(stack *S){
	// mahasiswa temp;
	// strcpy((*S).data[(*S).top].nama,nama);
	// strcpy((*S).data[(*S).top].nim,nim);
	// strcpy((*S).data[(*S).top].nilai,nilai);
	// (*S).top--;
	// return temp;
// }

void pop(stack *S){
	if((*S).top == 0){
		(*S).top = -1;
	}else{
		if((*S).top != -1){
			(*S).top--;
		}
	}
}

void popIsi(stack *S, stack *S2){
	if(isEmpty(*S) == 0 && isFull(*S2) == 0){
		push((*S).data[(*S).top].abjad, S2);
		pop(&(*S));
	}
}
	

void printStack(stack S){
	if(S.top != -1){
		int i;
		for(i=S.top;i>=0;i--){
			printf("%c\n", S.data[i].abjad);
		}
	}
	// else{
		// printf("stack kosong\n");
	// }
}

