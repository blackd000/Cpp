#include <stdio.h>
#include <stdlib.h>

struct binarySearchTreeNode {
	int data;
	struct binarySearchTreeNode *left;
	struct binarySearchTreeNode *right;
};
typedef struct binarySearchTreeNode BinarySearchTreeNode;

BinarySearchTreeNode *createNode(int data) {
	BinarySearchTreeNode *tempNode = (BinarySearchTreeNode *) malloc(sizeof(BinarySearchTreeNode));

	tempNode->data = data;
	tempNode->left = tempNode->right = NULL;

	return tempNode;
}

// Time Complexity:O(n). Space Complexity:O(n), for 
// recursive stack. For iterative version, space complexity is O(1).
BinarySearchTreeNode *insert(BinarySearchTreeNode *root, int data) {
	if (!root) {
		root = createNode(data);
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
		printf("%d ", root->data);
		inorder(root->right);
	}
}

// Time Complexity: O(n), in worst case (when BST is 
// a skew tree). Space Complexity: O(n), for recursive stack.
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

// Time Complexity: O(n). Space Complexity: O(1)
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

// Time Complexity: O(n), in worst case (when BST is 
// a left skew tree). Space Complexity: O(n), for recursive stack
BinarySearchTreeNode *findMin(BinarySearchTreeNode *root) {
	if (!root) {
		return NULL;
	} else if (!root->left) {
		return root;
	} else {
		return findMin(root->left);
	}
}

// Time Complexity: O(n). Space Complexity: O(1)
BinarySearchTreeNode *findMinNonRecursive(BinarySearchTreeNode *root) {
	if (!root) {
		return NULL;
	}

	while (root->left) {
		root = root->left;
	}

	return root;
}

// Time Complexity: O(n), in worst case (when BST is a 
// left skew tree). Space Complexity: O(n), for recursive stack
BinarySearchTreeNode *findMax(BinarySearchTreeNode *root) {
	if (!root) {
		return NULL;
	} else if (!root->right) {
		return root;
	} else {
		return findMax(root->right);
	}
}

// Time Complexity: O(n). Space Complexity: O(1)
BinarySearchTreeNode *findMaxNonRecursive(BinarySearchTreeNode *root) {
	if (!root) {
		return NULL;
	}

	while (root->right) {
		root = root->right;
	}

	return root;
}

// Time Complexity: O(n). Space Complexity: O(n) for recursive 
// stack. For iterative version, space complexity is O(1).
BinarySearchTreeNode *delete(BinarySearchTreeNode *root, int data) {
	BinarySearchTreeNode *temp = NULL;

	if (!root) { // not found
		printf("Element not found!!!\n");
	} else if (data < root->data) {
		root->left = delete(root->left, data);
	} else if (data > root->data) {
		root->right = delete(root->right, data);
	} else { // Found an element
		if (root->left && root->right) { // replace with the largest in left subtree
			temp = findMax(root->left);
			root->data = temp->data;
			root->left = delete(root->left, root->data);
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

			free(temp);
		}
	}

	return root;
}
