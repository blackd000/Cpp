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

	if (root == NULL) {
		root = newNode;
		return;
	}

	queue<BinaryTreeNode *> Q;

	Q.push(root);

	while(!Q.empty()) {
		BinaryTreeNode *tempTree = Q.front();
		Q.pop();

		if (tempTree->left != NULL) {
			/* enQueue(Q, tempTree->left); */
			Q.push(tempTree->left);
		} else {
			tempTree->left = newNode;
			return;
		}

		if (tempTree->right != NULL) {
			/* enQueue(Q, tempTree->right); */
			Q.push(tempTree->right);
		} else {
			tempTree->right = newNode;
			return;
		}
	}
}

// preOrder Traversal using recursion and using stack
void preOrderDLR(BinaryTreeNode *root, const char *position) {
	if (root) {
		cout << position << " -> " << root->data << endl;
		preOrderDLR(root->left, "left");
		preOrderDLR(root->right, "right");
	}
}

void preOrderDLRStack(BinaryTreeNode *root) {
	if (root == NULL) {
		cout << "Cay rong\n";
		return;
	}

	stack<BinaryTreeNode *> S;

	BinaryTreeNode *currentNode = root;

	while (true) {
		while (currentNode != NULL) {
			cout << currentNode->data << " ";

			S.push(currentNode);

			currentNode = currentNode->left;
		}

		if (S.empty()) {
			break;
		}

		currentNode = S.top();
		S.pop();

		currentNode = currentNode->right;
	}
}

// inOrder Traversal using recursion and using stack
void inOrderLDR(BinaryTreeNode *root, const char *position) {
	if (root) {
		inOrderLDR(root->left, "left");
		cout << position << " -> " << root->data << endl;
		inOrderLDR(root->right, "right");
	}
}

void inOrderLDRStack(BinaryTreeNode *root) {
	if (root == NULL) {
		cout << "Cay rong\n";
		return;
	}

	stack<BinaryTreeNode *> S;

	BinaryTreeNode *currentNode = root;

	while (true) {
		while (currentNode != NULL) {
			S.push(currentNode);

			currentNode = currentNode->left;
		}

		if (S.empty()) {
			break;
		}

		currentNode = S.top();
		S.pop();

		cout << currentNode->data << " ";

		currentNode = currentNode->right;
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
