#include <stdio.h>
#include "BinarySearchTree.c"

int main() {
	BinarySearchTreeNode *root = NULL;

	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 8);
	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 12);

	inorder(root);

	/* if (findRecursive(root, 12)) { */
	/* 	printf("\nYES YES YES\n"); */
	/* } else { */
	/* 	printf("\nNO NO NO\n"); */
	/* } */

	if (find(root, 19)) {
		printf("\nYES YES YES\n");
	} else {
		printf("\nNO NO NO\n");
	}

	printf("\nMin is: %d\n", findMin(root)->data);
	printf("Max is: %d\n", findMax(root)->data);

	delete(root, 5);

	inorder(root);

	return 0;
}
