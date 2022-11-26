#include <iostream>
#include "../binaryTrees/BinaryTree.cpp"

using std::cout;
using std::endl;
using std::max;
using std::min;

// - Naive Approach:
// 	+) The idea is to for each node, check if max value in left subtree 
// 	is smaller than the node and min value in right subtree is greater than the node.
//
// - Algorithm:
// 	1) If the current node is null then return true
// 	2) If the max value of the left child of the node is greater than or equal 
// 	to the current node then return false
// 	3) If the min value of the right child of the node is less than or equal to 
// 	the current node then return false
// 	4) If the left subtree or the right subtree is not a BST then return false
// 	5) Else return true
//
// - Pseudocode:
// 	FUNCTION int maxValue(BinaryTreeNode *root)
// 		IF root is NULL // this is BASE CASE
// 			RETURN INT16_MIN
// 		END IF
// 		INITIALIZE currentValue as root->data
// 		INITIALIZE leftMax as the recursive call on root->left
// 		INITIALIZE rightMax as the recursive call on root->right
// 		RETURN max value of the three of them
// 	END FUNCTION
//
// 	FUNCTION int minValue(BinaryTreeNode *root)
// 		IF root is NULL // this is BASE CASE after check all the way down to the leaf node
// 			RETURN INT16_MAX
// 		END IF
// 		INITIALIZE currentValue as root->data
// 		INITIALIZE leftMin as the recursive call on root->left
// 		INITIALIZE rightMin as the recursive call on root->right
// 		RETURN min value of the three of them
// 	END FUNCTION
//
// 	FUNCTION bool isBST(BinaryTreeNode *root)
// 		IF root is NULL // this is BASE CASE after check all the way down to the leaf node
// 			RETURN true
// 		END IF
// 		IF root->left is not NULL and root->left's max value is greater than or equal to root's data
// 			RETURN false
// 		END IF
// 		IF root->right is not NULL and root-right's min data is less than or euqal to root's data
// 			RETURN false
// 		END IF
// 		// RECURSIVELY check left and right subtree
// 		IF left subtree is not BST or right subtree is not BST
// 			RETURN false
// 		END IF
// 		RETURN true
// 	END FUNCTION

bool isBST(BinaryTreeNode *root);
int maxValue(BinaryTreeNode *root);
int minValue(BinaryTreeNode *root);

int main() {
	BinaryTreeNode *root = new BinaryTreeNode(9);

	// the result should be true
	insertElement(root, 6);
	insertElement(root, 15);
	insertElement(root, 4);
	insertElement(root, 8);
	insertElement(root, 13);

	/* // the result should be false */
	/* insertElement(root, 6); */
	/* insertElement(root, 15); */
	/* insertElement(root, 4); */
	/* insertElement(root, 11); */
	/* insertElement(root, 13); */

	levelOrder(root);

	cout << "\nIs this complete binary tree a BST?: " << (isBST(root) ? "yes" : "no") << endl;

	return 0;
}


bool isBST(BinaryTreeNode *root) {
	if (root == NULL) {
		return true;
	}

	if (root->left != NULL && maxValue(root->left) >= root->data) {
		return false;
	}
	if (root->right != NULL && minValue(root->right) <= root->data) {
		return false;
	}

	if (!isBST(root->left) || !isBST(root->right)) {
		return false;
	}

	return true;
}

int maxValue(BinaryTreeNode *root) {
	if (root == NULL) {
		return INT16_MIN;
	}

	int currentValue = root->data;
	int leftMax = maxValue(root->left);
	int rightMax = maxValue(root->right);

	return max(currentValue, max(leftMax, rightMax));
}

int minValue(BinaryTreeNode *root) {
	if (root == NULL) {
		return INT16_MAX;
	}

	int currentValue = root->data;
	int leftMin = minValue(root->left);
	int rightMin = minValue(root->right);

	return min(currentValue, min(leftMin, rightMin));
}
