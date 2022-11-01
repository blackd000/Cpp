#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

using std::cout;
using std::endl;

/* struct binarySearchTreeNode { */
/* 	int data; */
/* 	struct binarySearchTreeNode *left; */
/* 	struct binarySearchTreeNode *right; */
/* }; */
/* typedef struct binarySearchTreeNode BinarySearchTreeNode; */

class BinarySearchTreeNode {
public:
	int data;
	BinarySearchTreeNode *left;
	BinarySearchTreeNode *right;

	BinarySearchTreeNode(int data) {
		this->data = data;
		left = right = NULL;
	}
};

// - Time Complexity:O(n). Space Complexity:O(n), for 
// - recursive stack. For iterative version, space complexity is O(1).
BinarySearchTreeNode *insert(BinarySearchTreeNode *root, int data);

void inorder(BinarySearchTreeNode *root);

// - Time Complexity: O(n), in worst case (when BST is a skew tree). 
// - Space Complexity: O(n), for recursive stack.
BinarySearchTreeNode *find(BinarySearchTreeNode *root, int data);

// - Time Complexity: O(n). 
// - Space Complexity: O(1)
BinarySearchTreeNode *findNonRecursive(BinarySearchTreeNode *root, int data);

// - Time Complexity: O(n), in worst case (when BST is a left skew tree). 
// - Space Complexity: O(n), for recursive stack
BinarySearchTreeNode *findMin(BinarySearchTreeNode *root);

// - Time Complexity: O(n). 
// - Space Complexity: O(1)
BinarySearchTreeNode *findMinNonRecursive(BinarySearchTreeNode *root);

// - Time Complexity: O(n), in worst case (when BST is a left skew tree). 
// - Space Complexity: O(n), for recursive stack
BinarySearchTreeNode *findMax(BinarySearchTreeNode *root);

// - Time Complexity: O(n). 
// - Space Complexity: O(1)
BinarySearchTreeNode *findMaxNonRecursive(BinarySearchTreeNode *root);

// - Time Complexity: O(n). 
// - Space Complexity: O(n) for recursive stack. For iterative version, 
// space complexity is O(1).
BinarySearchTreeNode *deleteBST(BinarySearchTreeNode *root, int data);

#endif
