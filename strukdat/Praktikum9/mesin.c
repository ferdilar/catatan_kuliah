#include "header.h"

void makeTree(char c, tree *T){
// printf("%c", c);
	// if((*T).root==NULL){
		simpul* baru=(simpul*)malloc(sizeof(simpul));
		baru->kontainer=c;
		// printf("~%c", c);
		baru->sibling=NULL;
		baru->child=NULL;
		(*T).root=baru;
	// }
}

void addChild(char c, simpul* bapak){
	if(bapak!=NULL){
		simpul*baru=(simpul*)malloc(sizeof(simpul));
		baru->kontainer=c;
		baru->sibling=NULL;
		baru->child=NULL;
		if(bapak->child==NULL){
			bapak->child=baru;
		}else if(bapak->child->sibling==NULL){
			bapak->child->sibling=baru;
			baru->sibling=bapak->child;
		}else{
			simpul*bungsu=bapak->child;
			while(bungsu->sibling!=bapak->child){
				bungsu=bungsu->sibling;
			}
			bungsu->sibling=baru;
			baru->sibling=bapak->child;
		}
	}
}

void delChild(char c, simpul *bapak){
	if(bapak!=NULL){
		if(bapak->child!=NULL){
			if(bapak->child->sibling==NULL){
				if(bapak->child->kontainer==c){
					if(bapak->child->child==NULL){
						simpul*hapus=bapak->child;
						bapak->child=NULL;
						free(hapus);
					}
				}
			}else if(bapak->child->sibling->sibling==bapak->child){
				if(bapak->child->kontainer==c){//anak ke-1
					if(bapak->child->child==NULL){
						simpul*hapus=bapak->child;
						bapak->child=bapak->child->sibling;
						bapak->child->sibling=NULL;
						free(hapus);
					}
				}else if(bapak->child->sibling->kontainer==c){
					if(bapak->child->sibling->child==NULL){
						simpul *hapus=bapak->child->sibling;
						bapak->child->sibling=NULL;
						hapus->sibling=NULL;
						free(hapus);
					}
				}
			}else{
				simpul*kakak=NULL;
				simpul*cari=bapak->child;
				int status=0;
				while((status==0)&&(cari->sibling!=bapak->child)){
					if(cari->kontainer==c){
						status=1;
					}else{
						kakak=cari;
						cari=cari->sibling;
					}
				}
				if((cari->kontainer==c)&&(status==0)){
					status=1;
				}
				if((cari->child==NULL)&&(status==1)){
					if(cari==bapak->child){	
						simpul*bungsu=bapak->child;
						while(bungsu->sibling!=bapak->child){
							bungsu=bungsu->sibling;
						}
						bapak->child=cari->sibling;
						bungsu->sibling=bapak->child;
						cari->sibling=NULL;
						free(cari);
					}else{
						kakak->sibling=cari->sibling;
						cari->sibling=NULL;
						free(cari);
					}
				}
			}
		}
	}
}

void printTreePreOrder(simpul*bapak){
	if(bapak!=NULL){
		printf("%c ", bapak->kontainer);
		if(bapak->child!=NULL){
			if(bapak->child->sibling==NULL){
				printTreePreOrder(bapak->child);
			}else{
				simpul*anak=bapak->child;
				while(anak->sibling!=bapak->child){
					printTreePreOrder(anak);
					anak=anak->sibling;
				}
				printTreePreOrder(anak);
			}
		}
	}
}

void findSimpul(char c, simpul *bapak){
int status=0;
	if(bapak!=NULL){
		if(bapak->kontainer==c){
			printf("ditemukan %c\n", c);
			status=1;
		}
		if(bapak->child!=NULL){
			if(bapak->child->sibling==NULL && status==0){
				findSimpul(c,bapak->child);
			}else if(status==0){
				simpul*anak=bapak->child;
				while(anak->sibling!=bapak->child && status==0){
					findSimpul(c,anak);
					anak=anak->sibling;
				}
				findSimpul(c,anak);
			}else{
				printf("tidak ditemukan\n");
			}
		}
	}
}


