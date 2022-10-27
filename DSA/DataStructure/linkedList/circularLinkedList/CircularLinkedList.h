#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct cllNode {
	int data;
	struct cllNode *next;
};
typedef struct cllNode CLLNode;

// - Time Complexity: O(1)
CLLNode *createNode(int data);

// - Time Complexity: O(n), for scanning the complete list of size n.
// - Space Complexity: O(1), for temporary variable.
void insertAtEndInCLL(CLLNode **head, int data);

// - Time Complexity: O(n), for scanning the complete list of size n.
// - Space Complexity: O(1), for temporary variable.
void insertAtBeginInCLL(CLLNode **head, int data);

// - Time Complexity: O(n), for scanning the complete list of size n. 
// - Space Complexity: O(1), for a temporary variable.
void deleteLastNodeInCLL(CLLNode **head);

// - Time Complexity: O(n), for scanning the complete list of size n. 
// - Space Complexity: O(1), for a temporary variable
void deleteFrontNodeInCLL(CLLNode **head);

// - Time Complexity: O(n), for scanning the complete list of size n.
// - Space Complexity: O(1), for temporary variable.
void printCLL(CLLNode **head);

#endif
