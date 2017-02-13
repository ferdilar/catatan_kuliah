#include "header.h"

int main(){
	tree T;
	char karakter[14];
	int i;
	for(i=0;i<14;i++){
		scanf("%c", &karakter[i]);
	}
	makeTree(karakter[0], &T);
	addLeft(karakter[1],T.root);
	addRight(karakter[2],T.root);
	addLeft(karakter[3],T.root->left);
	addRight(karakter[4],T.root->left);
	addRight(karakter[5],T.root->right);
	addLeft(karakter[6],T.root->left->left);
	addRight(karakter[7],T.root->left->left);
	addRight(karakter[8],T.root->left->right);
	addLeft(karakter[9],T.root->right->right);
	addRight(karakter[10],T.root->right->right);
	addLeft(karakter[11],T.root->left->left->right);
	addRight(karakter[12],T.root->left->left->right);
	addLeft(karakter[13],T.root->right->right->left);
	// n=0;
	printf("Pre\n");
	printTreePreOrder(T.root);
	// delLeft(T.root->left->left->right);//L Hilang
	// n=0;
	printf("\nIn\n");
	printTreeInOrder(T.root);
	// delRight(T.root->left->right);//I Terhapus
	n=0;
	printf("\nPost\n");
	printTreePostOrder(T.root);
	// printTreePreOrder(T.root);
	// printTreePostOrder(T.root);
	// printTreeInOrder(T.root);
	// printf("selesai");
return 0;
}

