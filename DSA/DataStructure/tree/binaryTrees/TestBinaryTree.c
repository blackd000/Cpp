#include <stdio.h>
#include "BinaryTree.c"

int main() {
	/*
	 * 								 (1)
	 *					(2)						(3)
	 *			(4)     (5)		(6)     (7)
	 *		(18) (9)	(10) 
	 * */
	BinaryTreeNode *testTree = createTreeNode(1);

	insertElement(testTree, 2);
	insertElement(testTree, 3);
	insertElement(testTree, 4);
	insertElement(testTree, 5);
	insertElement(testTree, 6);
	insertElement(testTree, 7);
	insertElement(testTree, 18);
	insertElement(testTree, 9);
	insertElement(testTree, 10);

	printf("Pre Order DLR\n");
	preOrderDLR(testTree, "root"); // 1 2 4 8 9 5 10 3 6 7
	printf("\nIn Order DLR\n");
	inOrderLDR(testTree, "root");
	printf("\nPost Order LRD\n");
	postOrderLRD(testTree, "root");
	printf("\nLevel Order\n");
	levelOrder(testTree);

	printf("\n\nmax value: %d", findMax(testTree));

	printf("\n\nfind value %d", searchValue(testTree, 18));

	printf("\n\nthe height of the tree: %d\n", heightOfBinaryTree(testTree));

	deleteBinaryTree(testTree);

	return 0;
}
