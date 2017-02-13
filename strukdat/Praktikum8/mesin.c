#include "header.h"

void makeTree(char c, tree *T){
 // (*T).root=NULL;
	// if((*T).root==NULL){
		simpul *baru=(simpul*)malloc(sizeof(simpul));
		baru->kontainer=c;
		// printf("%c", baru->kontainer);
		baru->left=NULL;
		baru->right=NULL;
		(*T).root=baru;
		// printf("masuk");
	// }
}

//add right
void addRight(char c, simpul *bapak){
	if(bapak!=NULL){
		if(bapak->right==NULL){
			simpul *baru = (simpul*)malloc(sizeof(simpul));
			baru->kontainer=c;
			baru->left=NULL;
			baru->right=NULL;
			bapak->right=baru;
		}
	}
}
void countSimpul(){
	

}


void addLeft(char c, simpul *bapak){
	if(bapak!=NULL){
		if(bapak->left==NULL){
			simpul *baru = (simpul*)malloc(sizeof(simpul));
			baru->kontainer=c;
			baru->left=NULL;
			baru->right=NULL;
			bapak->left=baru;
		}
	}
}

//del right
void delRight(simpul *bapak){
	if(bapak!=NULL){
		if(bapak->right!=NULL){
			if((bapak->right->left==NULL)&&(bapak->right->right==NULL)){
				simpul *hapus= bapak->right;
				bapak->right=NULL;
				free(hapus);
			}
		}
	}
}

void delLeft(simpul *bapak){
	if(bapak!=NULL){
		if(bapak->left!=NULL){
			if((bapak->left->left==NULL)&&(bapak->left->right==NULL)){
				simpul *hapus= bapak->left;
				bapak->left=NULL;
				free(hapus);
			}
		}
	}
}

void printTreePreOrder(simpul *bapak){
	if(bapak!=NULL){
		printf("%c-", bapak->kontainer);
		printTreePreOrder(bapak->left);
		printTreePreOrder(bapak->right);
	}
	// printf("\n");
}


void printTreeInOrder(simpul *bapak){
	if(bapak!=NULL){
		printTreeInOrder(bapak->left);
		printf("%c-", bapak->kontainer);
		printTreeInOrder(bapak->right);
	}
}


void printTreePostOrder(simpul *bapak){
	if(bapak!=NULL){
		printTreePostOrder(bapak->left);
		printTreePostOrder(bapak->right);
		printf("%c-", bapak->kontainer);
		// n++;
	}
	// else{
		// printf("\n%d\n",n);
	// }
}

void copyTree(simpul *bapak1, simpul *bapak2){
	if(bapak1!=NULL){
		bapak2=(simpul*)malloc(sizeof(simpul));
		bapak2->kontainer=bapak1->kontainer;
		if(bapak1->left!=NULL){
			copyTree(bapak1->left,bapak2->left);
		}
		if(bapak1->right!=NULL){
			copyTree(bapak1->right,bapak2->right);
		}
	}
}

int isEqual(simpul *bapak1,simpul *bapak2){
	int hasil;
	if((bapak1 != NULL) && (bapak2 != NULL)){
		if(bapak1 ->kontainer!= bapak2 ->kontainer){
			hasil=1;
		}else{
			isEqual(bapak1->left,bapak2->left);
			isEqual(bapak1->right,bapak2->left);
		}
	}else{
		hasil=0;
	}
return hasil;
}

