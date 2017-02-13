#include "header.h"

int main(){
	tree T;
	makeTree('A', &T);
	// printf("%c\n", T.root->kontainer);
	// printTreePreOrder(T.root);
	
   addChild('B',T.root);
   delChild('B',T.root);
   addChild('C',T.root);
   addChild('D',T.root);
   addChild('E',T.root->child);
   addChild('F',T.root->child->child);
   addChild('G',T.root->child);
   addChild('H',T.root);
   printTreePreOrder(T.root);
   printf("\n");
   delChild('H',T.root);
   printTreePreOrder(T.root);
   printf("\n");
   addChild('I',T.root->child);
   addChild('J',T.root->child->child);
   printTreePreOrder(T.root);
   printf("\n");

   // printf("../n");
   findSimpul('C',T.root);
   findSimpul('C',T.root->child->child);
   // printf("\nselesai");

return 0;
}

