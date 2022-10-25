#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct cllNode {
	int data;
	struct cllNode *next;
};
typedef struct cllNode CLLNode;

CLLNode *createNode(int data);

// - Time Complexity: O(n), for scanning the complete list of size n.
// - Space Complexity: O(1), for temporary variable.
CLLNode *insertAtEndInCLL(CLLNode *head, int data);

void printCLL(CLLNode *head);

#endif
