#include <iostream>
#include "BinaryTree.h"

int main() {
	/*
	 * 								 (1)
	 *					 (2)						(3)
	 *			 (4)     (5)		(6)     (7)
	 *		(18) (9) (10) 
	 * */
	BinaryTreeNode *testTree = new BinaryTreeNode(1);

	insertElement(testTree, 2);
	insertElement(testTree, 3);
	insertElement(testTree, 4);
	insertElement(testTree, 5);
	insertElement(testTree, 6);
	insertElement(testTree, 7);
	insertElement(testTree, 18);
	insertElement(testTree, 9);
	insertElement(testTree, 10);

	cout << "\nPre Order DLR\n";
	preOrderDLR(testTree, "root"); // 1 2 4 18 9 5 10 3 6 7
	cout << "\nPre Order DLR using stack\n";
	preOrderDLRStack(testTree);

	/* cout << "\nIn Order LDR\n"; */
	/* inOrderLDR(testTree, "root"); */
	/* cout << "\nIn Order LDR using stack\n"; */
	/* inOrderLDRStack(testTree); */

	/* cout << "\nPost Order LRD\n"; */
	/* postOrderLRD(testTree, "root"); */

	/* cout << "\nLevel Order DLR\n"; */
	/* levelOrder(testTree); */

	deleteBinaryTree(testTree);

	cout << endl;
	return 0;
}
