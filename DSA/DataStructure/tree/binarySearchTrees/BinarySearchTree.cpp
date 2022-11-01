#include "BinarySearchTree.h"

/* BinarySearchTreeNode *createNode(int data) { */
/* 	BinarySearchTreeNode *tempNode = (BinarySearchTreeNode *) malloc(sizeof(BinarySearchTreeNode)); */

/* 	tempNode->data = data; */
/* 	tempNode->left = tempNode->right = NULL; */

/* 	return tempNode; */
/* } */

BinarySearchTreeNode *insert(BinarySearchTreeNode *root, int data) {
	if (!root) {
		root = new BinarySearchTreeNode(data);
	} else {
		if (data < root->data) {
			root->left = insert(root->left, data);
		} else if (data > root->data) {
			root->right = insert(root->right, data);
		}
	}

	return root;
}

void inorder(BinarySearchTreeNode *root) {
	if (root) {
		inorder(root->left);
		cout << root->data << " ";

		inorder(root->right);
	}
}

BinarySearchTreeNode *find(BinarySearchTreeNode *root, int data) {
	if (!root) {
		return NULL;
	}

	if (data < root->data) {
		return find(root->left, data);
	} else if (data > root->data) {
		return find(root->right, data);
	}

	return root; // da tim thay
}

BinarySearchTreeNode *findNonRecursive(BinarySearchTreeNode *root, int data) {
	if (!root) {
		return NULL;
	}

	while (root) {
		if (data == root->data) {
			return root;
		} else if (data < root->data) {
			root = root->left;
		} else {
			root = root->right;
		}
		/* printf("\nHere: "); */
		/* inorder(root); */
		/* printf("\n"); */
	}

	return NULL;
}

BinarySearchTreeNode *findMin(BinarySearchTreeNode *root) {
	if (!root) {
		return NULL;
	} else if (!root->left) {
		return root;
	} else {
		return findMin(root->left);
	}
}

BinarySearchTreeNode *findMinNonRecursive(BinarySearchTreeNode *root) {
	if (!root) {
		return NULL;
	}

	while (root->left) {
		root = root->left;
	}

	return root;
}

BinarySearchTreeNode *findMax(BinarySearchTreeNode *root) {
	if (!root) {
		return NULL;
	} else if (!root->right) {
		return root;
	} else {
		return findMax(root->right);
	}
}

BinarySearchTreeNode *findMaxNonRecursive(BinarySearchTreeNode *root) {
	if (!root) {
		return NULL;
	}

	while (root->right) {
		root = root->right;
	}

	return root;
}

BinarySearchTreeNode *deleteBST(BinarySearchTreeNode *root, int data) {
	BinarySearchTreeNode *temp = NULL;

	if (!root) { // not found
		cout << "Element not found!!!\n";
	} else if (data < root->data) {
		root->left = deleteBST(root->left, data);
	} else if (data > root->data) {
		root->right = deleteBST(root->right, data);
	} else { // Found an element
		if (root->left && root->right) { // replace with the largest in left subtree
			temp = findMax(root->left);
			root->data = temp->data;
			root->left = deleteBST(root->left, root->data);
		} else {
			temp = root;

			// one child left or right
			if (root->left) {
				root = root->left;
			} else if (root->right) {
				root = root->right;
			} else { // or not at all
				root = NULL;
			}

			delete(temp);
		}
	}

	return root;
}
