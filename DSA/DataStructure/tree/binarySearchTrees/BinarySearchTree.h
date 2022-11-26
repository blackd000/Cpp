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

// - Algorithm:
// 	1) We start searching for a key from the root until we hit a leaf 
// 	node (A new key is always inserted at the leaf).
// 	2) Once a leaf node is found, the new node is added as a child of the leaf node.
// 	3) During this process if data has been found in BST then do nothing
//
// - Pseudocode:
// 	FUNCTION BinarySearchTreeNode *insert(BinarySearchTreeNode *root, int data)
// 		// reach the end means data is not in BST (BASE CASE)
// 		IF root is NULL
// 			RETURN the new create node for the data
// 		END IF
// 		IF data is less than root->data
// 			SET root->left as the recursive call on the left subtree
// 		ELSE IF data is greater than root->data
// 			SET root->right as the recursive call on the right subtree
// 		END IF
// 		// return 'root' after insert an element or if found the element then simply return root (do nothing)
// 		RETURN root
// 	END FUNCTION
//
// - Time Complexity: O(n). 
// - Space Complexity: O(n), for recursive stack. For iterative version, space complexity is O(1).
BinarySearchTreeNode *insert(BinarySearchTreeNode *root, int data);

// - Algorithm:
// 1) Start with the root and keep moving left or right using the BST property. 
// 2) If the data we are searching is same as nodes data then we return current node.
// 3) If the data we are searching is less than nodes data then search left subtree of current node;
// otherwise search right subtree of current node. 
// 4) If the data is not present, we end up in a NULL link (BASE CASE)
void inorder(BinarySearchTreeNode *root);

// - Algorithm:
// 1) Start with the root and keep moving left or right using the BST property. 
// 2) If the data we are searching is same as nodes data then we return current node.
// 3) If the data we are searching is less than nodes data then search left subtree of current node;
// otherwise search right subtree of current node. 
// 4) If the data is not present, we end up in a NULL link (BASE CASE)
// 
// - Pseudocode:
// 	FUNCTION BinarySearchTreeNode *find(BinarySearchTreeNode *root, int data)
// 		// the value is not found also BASE CASE
// 		IF root is NULL
// 			RETURN NULL
// 		END IF
// 		IF data is less than root->data // search left
// 			RETURN the recursive call on the left subtree
// 		ELSE IF data is greater than root->data // search right
// 			RETURN the recursive call on the right subtree
// 		END IF
// 		// we found it
// 		RETURN root // the current node
// 	END FUNCTION
//
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

// - Algorithm:
// 	1) Find the location of the element which we want to delete.
// 	2) If node to be deleted is the leaf: Simply remove from the tree which 
// 	is return NULL to its parent.
// 	3) If node to be deleted has only one child: Copy the child to the temp node 
// 	and delete the node that need to be deleted and return the temp node.
// 	4) If node to be deleted has two children: Find inorder successor (smallest 
// 	element in the left subtree) of the node. Copy contents of the inorder successor 
// 	to the node and delete the inorder successor. Note that inorder predecessor can 
// 	also be used.
//
// - Time Complexity: O(n). 
// - Space Complexity: O(n) for recursive stack. For iterative version, 
// space complexity is O(1).
BinarySearchTreeNode *deleteBST(BinarySearchTreeNode *root, int data);

#endif
