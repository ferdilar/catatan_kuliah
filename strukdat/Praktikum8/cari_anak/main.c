#include "header.h"

int main(){
	tree T;
	char cari;
	makeTree('A', &T);
	addLeft('B',T.root);
	addRight('C',T.root);
	addLeft('D',T.root->left);
	addRight('E',T.root->left);
	addRight('F',T.root->right);
	addLeft('G',T.root->left->left);
	addRight('H',T.root->left->left);
	addRight('I',T.root->left->right);
	addLeft('J',T.root->right->right);
	addRight('K',T.root->right->right);
	addLeft('L',T.root->left->left->right);
	addRight('M',T.root->left->left->right);
	addLeft('N',T.root->right->right->left);
	// printf("Pre\n");
	// printTreePreOrder(T.root);
	// delLeft(T.root->left->left->right);//L Hilang
	// printf("\nIn\n");
	// printTreeInOrder(T.root);
	// delRight(T.root->left->right);//I Terhapus
	// printf("\nPost\n");
	// printTreePostOrder(T.root);
	status=0;
	scanf("%c", &cari);
	search(cari,T.root);
	
return 0;
}

