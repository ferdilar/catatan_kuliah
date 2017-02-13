#include "header.h"

void createEmpty(queue *Q){
	(*Q).first=-1;
	(*Q).last=-1;
}

int isEmpty(queue Q){
	int hasil=0;
	if(Q.first == -1){
		hasil=1;
	}
return hasil;
}

int isFull(queue Q){
	int hasil=0;
	if(Q.last == (byk-1)){
		hasil=1;
	}
return hasil;
}

void add(char nama, queue *Q){
	if(isFull(*Q)!=1){
		if(isEmpty(*Q)==1){
			(*Q).first++;
			(*Q).last++;
			(*Q).data[(*Q).last].nama=nama;
		}else{
			(*Q).last++;
			(*Q).data[(*Q).last].nama=nama;
		}
	}else{
		printf("antrian penuh!\n");
	}
}

void del(queue *Q){//delFirst
	if(isEmpty(*Q)!=1){
		if((*Q).first==(*Q).last){
			(*Q).first--;
			(*Q).last--;
		}else{
			int i;
			for(i=1;i<=(*Q).last;i++){
				(*Q).data[i-1].nama=(*Q).data[i].nama;
			}
			(*Q).last--;
		}
	}
}

void printQueue(queue Q){
	if(Q.first!=-1){
		int i;
		printf("-----------------\n");
		for(i=0;i<=(Q).last;i++){
			printf("%c",(Q).data[i].nama);
			if(i!=(Q).last){
				printf(" ");
			}
		}
		
		printf("\n-----------------\n");		
	}else{
		printf("Queue kosong\n");
	}
}

void addBerprioritas(char nama, queue *Q, int urutan){
	if(isFull(*Q)!=1){
		if((isEmpty(*Q)==1)||((urutan-1)>(*Q).last)){
			add(nama,Q);
		}else{
			if(urutan==1){
				int i;
				for(i=(*Q).last;i>0;i--){
					(*Q).data[i+1].nama=(*Q).data[i].nama;
				}
			(*Q).last++;
			(*Q).data[0].nama,nama;
			}else if((urutan-1)<=(*Q).last){
				int i;
				for(i=(*Q).last;i>=(urutan-1);i--){
					(*Q).data[i+1].nama=(*Q).data[i].nama;
				}
				(*Q).data[urutan-1].nama=nama;
				(*Q).last++;
			}
		}
	}
}

