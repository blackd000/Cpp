#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

/* struct binaryTreeNode { */
/* 	int data; */
/* 	struct binaryTreeNode *left; */
/* 	struct binaryTreeNode *right; */
/* }; */
/* typedef struct binaryTreeNode BinaryTreeNode; */

class BinaryTreeNode {
public:
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;

	BinaryTreeNode(int data) {
		this->data = data;
		left = right = NULL;
	}
};

/* BinaryTreeNode *createTreeNode(int data); */

// - Time Complexity: O(n). 
// - Space Complexity: O(n)
void insertElement(BinaryTreeNode *root, int data);

// - Time Complexity: O(n). 
// - Space Complexity: O(n).
void preOrderDLR(BinaryTreeNode *root, const char *position);

// - Time Complexity: O(n). 
// - Space Complexity: O(n).
void inOrderLDR(BinaryTreeNode *root, const char *position);

// - Time Complexity: O(n). 
// - Space Complexity: O(n).
void postOrderLRD(BinaryTreeNode *root, const char *position);

// - Time Complexity: O(n). 
// - Space Complexity: O(n). Since, in the worst case, all the nodes 
// on the entire last level could be in the queue simultaneously
void levelOrder(BinaryTreeNode *root);

/*
 * - Delete binary tree with *postorder* because
 * it does the work without storing anything
 * - Time Complexity: O(n). 
 * - Space Complexity: O(n).
 * */
void deleteBinaryTree(BinaryTreeNode *root);

#endif
