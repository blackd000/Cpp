#include <stdio.h>
#include "BinaryTree.c"

int main() {
	BinaryTreeNode *testTree = createTreeNode(1);

	insertElement(testTree, 2);
	insertElement(testTree, 3);
	insertElement(testTree, 4);
	insertElement(testTree, 5);
	insertElement(testTree, 6);
	insertElement(testTree, 7);

	preOrder(testTree, "root"); // 1 2 4 5 3 6 7

	return 0;
}
