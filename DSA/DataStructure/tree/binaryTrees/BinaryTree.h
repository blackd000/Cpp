#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <stack>
#include <queue>

using std::cout;
using std::endl;
using std::stack;
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

// ================ Pre Order Traversal ================ //
// - Time Complexity: O(n). 
// - Space Complexity: O(n).
void preOrderDLR(BinaryTreeNode *root, const char *position);
// - Algorithm:
// 	FUNCTION void preOrderDLR(BinaryTreeNode *root)
// 		CREATE an empty stack S.
// 		INITIALIZE current node as root
// 		WHILE true (infinite loops) do the following
// 			WHILE the current node is not NULL
// 				OUTPUT the current node 
// 				PUSH the current node into stack
// 				SET current = current->left
// 			END WHILE
// 			IF stack is empty
// 				BREAK out the infinite while loop
// 			END IF
// 			POP the top item from stack and SET the current node as the pop item
// 			SET current = current->right
// 		END WHILE
void preOrderDLRStack(BinaryTreeNode *root);

// ================ In Order Traversal ================ //
// - Time Complexity: O(n). 
// - Space Complexity: O(n).
void inOrderLDR(BinaryTreeNode *root, const char *position);
// - Algorithm:
// 	FUNCTION void inOrderDLR(BinaryTreeNode *root)
// 		CREATE an empty stack S.
// 		INITIALIZE current node as root
// 		WHILE true (infinite loops) do the following
// 			WHILE current node is not NULL
// 				PUSH the current node to stack
// 				SET current = current->left
// 			END WHILE
// 			IF stack is empty 
// 				BREAK out the infinite loop
// 			END IF
// 			POP the top item from stack and SET current node as the pop item
// 			OUTPUT the popped item
// 			SET current = popped_item->right 
// 		END WHILE
void inOrderLDRStack(BinaryTreeNode *root);

// ================ Post Order Traversal ================ //
// - Time Complexity: O(n). 
// - Space Complexity: O(n).
void postOrderLRD(BinaryTreeNode *root, const char *position);

// ================ Level Order Traversal ================ //
// - Time Complexity: O(n). 
// - Space Complexity: O(n). Since, in the worst case, all the nodes 
// on the entire last level could be in the queue simultaneously
void levelOrder(BinaryTreeNode *root);

/*
 * - Delete binary tree with *postorder* because it does the work without storing anything
 * - Time Complexity: O(n). 
 * - Space Complexity: O(n).
 * */
void deleteBinaryTree(BinaryTreeNode *root);

#endif
