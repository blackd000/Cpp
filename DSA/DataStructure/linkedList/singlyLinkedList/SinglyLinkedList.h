#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node Node;

Node *createNode(int data);

// - Time Complexity: O(n), since, in the worst case, we may need to insert 
// the node at the end of the list. 
// - Space Complexity: O(1), for creating one temporary variable.
void insertInLinkedList(Node **head, int data, int position);

// - Time Complexity: O(n). In the worst case, we may need to delete the 
// node at the end of the list. 
// - Space Complexity: O(1), for one temporary variable
void deleteInLinkedList(Node **head, int position);

// - Time Complexity: O(n), for scanning the complete list of size n.
// - Space Complexity: O(1), for creating one temporary variable.
void deleteLinkedList(Node **head);

// - Time Complexity: O(n)
void printSinglyLinkedList(Node *head);

#endif
