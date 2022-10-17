#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

void preOrderDLR(BinaryTreeNode *root, const char *position) {
	if (root) {
		printf("%s -> %d\n", position, root->data);
		preOrderDLR(root->left, "left");
		preOrderDLR(root->right, "right");
	}
}

void inOrderLDR(BinaryTreeNode *root, const char *position) {
	if (root) {
		inOrderLDR(root->left, "left");
		printf("%s -> %d\n", position, root->data);
		inOrderLDR(root->right, "right");
	}
}

void postOrderLRD(BinaryTreeNode *root, const char *position) {
	if (root) {
		postOrderLRD(root->left, "left");
		postOrderLRD(root->right, "right");
		printf("%s -> %d\n", position, root->data);
	}
}

void levelOrder(BinaryTreeNode *root) {
	Queue *queue = createQueue();
	BinaryTreeNode *tempNode = NULL;
	int level = 0;

	if (!root) {
		printf("Empty Binary Tree!\n");
		deleteQueue(queue);
		return;
	}

	enQueue(queue, root);

	while(!isEmptyQueue(queue)) {
		tempNode = deQueue(queue);
		printf("%d ", tempNode->data);

		if (tempNode->left) {
			enQueue(queue, tempNode->left);
		}

		if (tempNode->right) {
			enQueue(queue, tempNode->right);
		}
	}

	deleteQueue(queue);
}

// Find maximum value Time Complexity: O(n). Space Complexity: O(n)
int findMax(BinaryTreeNode *root) {
	int left, right, max = INT_MIN;
	
	if (root) {
		int currentValue = root->data;

		int leftValue = findMax(root->left);
		int rightValue = findMax(root->right);

		if (leftValue > rightValue) {
			max = leftValue;
		} else {
			max = rightValue;
		}

		if (currentValue > max) {
			max = currentValue;
		}
	}

	return max;
}

// search for a value Time Complexity: O(n). Space Complexity: O(n)
int searchValue(BinaryTreeNode *root, int data) {
	if (!root) {
		return 0;
	} else {
		if (data == root->data) {
			return 1;
		} else {
			if (searchValue(root->left, data) == 1) {
				return 1;
			} else {
				return (searchValue(root->right, data));
			}
		}
	}
}

/*
 * delete binary tree with *postorder* because
 * it does the work without storing anything
 * Time Complexity: O(n). Space Complexity: O(n).
 * */
void deleteBinaryTree(BinaryTreeNode *root) {
	if (!root) {
		return;
	}

	deleteBinaryTree(root->left);
	deleteBinaryTree(root->right);

	free(root);
}

int heightOfBinaryTree(BinaryTreeNode *root) {
	int leftHeight, rightHeight;

	if (!root) {
		return 0;
	}

	leftHeight = heightOfBinaryTree(root->left);
	rightHeight = heightOfBinaryTree(root->right);

	if (leftHeight > rightHeight) {
		return (leftHeight + 1);
	} else {
		return (rightHeight + 1);
	}
}
