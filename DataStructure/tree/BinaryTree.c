#include <stdio.h>
#include <stdlib.h>
#include "LinkedListQueue.c"

/* struct binaryTreeNode { */
/* 	int data; */
/* 	struct binaryTreeNode *left; */
/* 	struct binaryTreeNode *right; */
/* }; */
/* typedef struct binaryTreeNode BinaryTreeNode; */

BinaryTreeNode *createTreeNode(int data) {
	BinaryTreeNode *treeNode = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));

	treeNode->data = data;
	treeNode->left = NULL;
	treeNode->right = NULL;

	return treeNode;
}

void insertElement(BinaryTreeNode *root, int data) {
	BinaryTreeNode *newNode = createTreeNode(data);

	if (!root) {
		root = newNode;
		return;
	}
	Queue *Q = createQueue();
	BinaryTreeNode *tempTree = NULL;

	enQueue(Q, root);

	while(!isEmptyQueue(Q)) {
		tempTree = deQueue(Q);

		if (tempTree->left) {
			enQueue(Q, tempTree->left);
		} else {
			tempTree->left = newNode;
			deleteQueue(Q);
			return;
		}

		if (tempTree->right) {
			enQueue(Q, tempTree->right);
		} else {
			tempTree->right = newNode;
			deleteQueue(Q);
			return;
		}
	}

	deleteQueue(Q);
}

void preOrder(BinaryTreeNode *root, const char *position) {
	if (root) {
		printf("%s -> %d\n", position, root->data);
		preOrder(root->left, "left");
		preOrder(root->right, "right");
	}
}
