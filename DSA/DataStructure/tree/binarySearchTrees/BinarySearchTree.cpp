#include "BinarySearchTree.h"

/* BinarySearchTreeNode *createNode(int data) { */
/* 	BinarySearchTreeNode *tempNode = (BinarySearchTreeNode *) malloc(sizeof(BinarySearchTreeNode)); */

/* 	tempNode->data = data; */
/* 	tempNode->left = tempNode->right = NULL; */

/* 	return tempNode; */
/* } */

BinarySearchTreeNode *insert(BinarySearchTreeNode *root, int data) {
	if (root == NULL) {
		return (new BinarySearchTreeNode(data));
	} 

	if (data < root->data) {
		root->left = insert(root->left, data);
	} else if (data > root->data) {
		root->right = insert(root->right, data);
	}

	// return 'root' node after insertion or if found element then simply return (do nothing)
	return root;
}

void inorder(BinarySearchTreeNode *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

BinarySearchTreeNode *find(BinarySearchTreeNode *root, int data) {
	// not found
	if (root == NULL) {
		return NULL;
	}

	if (data < root->data) {
		return find(root->left, data);
	} else if (data > root->data) {
		return find(root->right, data);
	}

	// finally found this value
	return root;
}

BinarySearchTreeNode *findNonRecursive(BinarySearchTreeNode *root, int data) {
	while (root != NULL) {
		if (data == root->data) {
			return root;
		} else if (data < root->data) {
			root = root->left;
		} else {
			root = root->right;
		}
	}

	return NULL;
}

BinarySearchTreeNode *findMin(BinarySearchTreeNode *root) {
	if (root == NULL) {
		return NULL;
	} 

	if (root->left == NULL) {
		return root;
	} else {
		return findMin(root->left);
	}
}

BinarySearchTreeNode *findMinNonRecursive(BinarySearchTreeNode *root) {
	if (root == NULL) {
		return NULL;
	}

	BinarySearchTreeNode *currentNode = root;

	while (currentNode->left != NULL) {
		currentNode = currentNode->left;
	}

	return currentNode;
}

BinarySearchTreeNode *findMax(BinarySearchTreeNode *root) {
	if (root == NULL) {
		return NULL;
	} 

	if (root->right == NULL) {
		return root;
	} else {
		return findMax(root->right);
	}
}

BinarySearchTreeNode *findMaxNonRecursive(BinarySearchTreeNode *root) {
	if (root == NULL) {
		return NULL;
	}

	BinarySearchTreeNode *currentNode = root;

	while (currentNode->right != NULL) {
		currentNode = currentNode->right;
	}

	return currentNode;
}

BinarySearchTreeNode *deleteBST(BinarySearchTreeNode *root, int data) {
	if (root == NULL) { // not found, its also a BASE CASE
		cout << "\nElement not found!!!\n";
		return root;
	}

	// find an element
	if (data < root->data) {
		root->left = deleteBST(root->left, data);
	} else if (data > root->data) {
		root->right = deleteBST(root->right, data);
	} else { // Found an element, lets remove it boi
		if (root->left == NULL && root->right == NULL) { // the removed node is the leaf node
			delete(root);
			return NULL;
		} else if (root->right == NULL) { // the removed node has left child
			BinarySearchTreeNode *tempNode = root->left;
			delete(root);
			return tempNode;
		} else if (root->left == NULL) { // the removed node has right child
			BinarySearchTreeNode *tempNode = root->right;
			delete(root);
			return tempNode;
		} else { // the removed node has both left child and right child
			// it's time to find the inorder successor 
			BinarySearchTreeNode *tempNode = findMinNonRecursive(root->right);

			root->data = tempNode->data;

			// delete the inorder successor
			root->right = deleteBST(root->right, tempNode->data);
		}
	}

	return root;
}
