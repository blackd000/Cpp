#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct dllNode {
	int data;
	struct dllNode *next;
	struct dllNode *prev;
};
typedef struct dllNode DLLNode;

DLLNode *createNode(int data, DLLNode *predecessor, DLLNode *successor);

// - Time Complexity: O(n). In the worst case, we may need to 
// insert the node at the end of the list. 
// - Space Complexity: O(1), for creating one temporary variable.
void DLLInsert(DLLNode **head, int data, int position);

// - Time Complexity: O(n), for scanning the complete list of size n.
// - Space Complexity: O(1), for creating one temporary variable
void DLLDelete(DLLNode **head, int position);

// - Time Complexity: O(n)
void printDLL(DLLNode **head);

#endif
