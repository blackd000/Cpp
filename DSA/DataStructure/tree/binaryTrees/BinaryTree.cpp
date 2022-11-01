#include "BinaryTree.h"

/* BinaryTreeNode *createTreeNode(int data) { */
/* 	BinaryTreeNode *treeNode = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode)); */

/* 	treeNode->data = data; */
/* 	treeNode->left = NULL; */
/* 	treeNode->right = NULL; */

/* 	return treeNode; */
/* } */

void insertElement(BinaryTreeNode *root, int data) {
	BinaryTreeNode *newNode = new BinaryTreeNode(data);

	if (!root) {
		root = newNode;
		return;
	}
	queue<BinaryTreeNode *> Q;
	BinaryTreeNode *tempTree = NULL;

	Q.push(root);

	while(!Q.empty()) {
		tempTree = Q.front();
		Q.pop();

		if (tempTree->left) {
			/* enQueue(Q, tempTree->left); */
			Q.push(tempTree->left);
		} else {
			tempTree->left = newNode;
			return;
		}

		if (tempTree->right) {
			/* enQueue(Q, tempTree->right); */
			Q.push(tempTree->right);
		} else {
			tempTree->right = newNode;
			return;
		}
	}
}

void preOrderDLR(BinaryTreeNode *root, const char *position) {
	if (root) {
		cout << position << " -> " << root->data << endl;
		preOrderDLR(root->left, "left");
		preOrderDLR(root->right, "right");
	}
}

void inOrderLDR(BinaryTreeNode *root, const char *position) {
	if (root) {
		inOrderLDR(root->left, "left");
		cout << position << " -> " << root->data << endl;
		inOrderLDR(root->right, "right");
	}
}

void postOrderLRD(BinaryTreeNode *root, const char *position) {
	if (root) {
		postOrderLRD(root->left, "left");
		postOrderLRD(root->right, "right");
		cout << position << " -> " << root->data << endl;
	}
}

void levelOrder(BinaryTreeNode *root) {
	/* Queue *queue = createQueue(); */
	queue<BinaryTreeNode *> Q;
	BinaryTreeNode *tempNode = NULL;
	int level = 0;

	if (!root) {
		cout << "Empty Binary Tree!\n";
		return;
	}

	/* enQueue(queue, root); */
	Q.push(root);

	while(!Q.empty()) {
		tempNode = Q.front();
		Q.pop();
		cout << tempNode->data << " ";

		if (tempNode->left) {
			/* enQueue(queue, tempNode->left); */
			Q.push(tempNode->left);
		}

		if (tempNode->right) {
			/* enQueue(queue, tempNode->right); */
			Q.push(tempNode->right);
		}
	}
}

void deleteBinaryTree(BinaryTreeNode *root) {
	if (!root) {
		return;
	}

	deleteBinaryTree(root->left);
	deleteBinaryTree(root->right);

	delete(root);
}
