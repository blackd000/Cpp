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

DLLNode *createNode(int, DLLNode *, DLLNode *);

// - Time Complexity: O(n). In the worst case, we may need to 
// insert the node at the end of the list. 
// - Space Complexity: O(1), for creating one temporary variable.
DLLNode *DLLInsert(DLLNode *, int, int);

// - Time Complexity: O(n), for scanning the complete list of size n.
// - Space Complexity: O(1), for creating one temporary variable
DLLNode *DLLDelete(DLLNode *, int);

// - Time Complexity: O(n)
void printDLL(DLLNode *);

#endif
