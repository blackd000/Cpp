#include <stdio.h>
#include "BinaryTree.c"

int main() {
	/*
	 * 								 (1)
	 *					(2)						(3)
	 *			(4)     (5)		(6)     (7)
	 *		(8) (9)	(10) 
	 * */
	BinaryTreeNode *testTree = createTreeNode(1);

	insertElement(testTree, 2);
	insertElement(testTree, 3);
	insertElement(testTree, 4);
	insertElement(testTree, 5);
	insertElement(testTree, 6);
	insertElement(testTree, 7);
	insertElement(testTree, 8);
	insertElement(testTree, 9);
	insertElement(testTree, 10);

	preOrderDLR(testTree, "root"); // 1 2 4 8 9 5 10 3 6 7

	return 0;
}
