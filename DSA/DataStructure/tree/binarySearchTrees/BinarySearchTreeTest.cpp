#include <iostream>
#include "BinarySearchTree.h"

int main() {
	BinarySearchTreeNode *root = new BinarySearchTreeNode(4);

	insert(root, 2);
	insert(root, 8);
	insert(root, 5);
	insert(root, 6);
	insert(root, 7);
	insert(root, 12);

	cout << "Before:\n";
	inorder(root);

	/* if (findRecursive(root, 12)) { */
	/* 	printf("\nYES YES YES\n"); */
	/* } else { */
	/* 	printf("\nNO NO NO\n"); */
	/* } */

	/* if (find(root, 7) != NULL) { */
	/* 	cout << "\nYES YES YES\n"; */
	/* } else { */
	/* 	cout << "\nNO NO NO\n"; */
	/* } */

	/* cout << "\nMin is: " << findMin(root)->data << endl; */
	/* cout << "\nMin is: " << findMax(root)->data << endl; */

	deleteBST(root, 6);

	cout << "\nAfter:\n";
	inorder(root);

	cout << endl;
	return 0;
}
