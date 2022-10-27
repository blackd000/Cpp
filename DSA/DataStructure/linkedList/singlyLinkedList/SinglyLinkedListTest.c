#include <stdio.h>
#include "SinglyLinkedList.h"

int main() {
	Node **head = (Node **) malloc(sizeof(Node *));

	insertInLinkedList(head, 9, 0);
	insertInLinkedList(head, 18, 1);
	insertInLinkedList(head, 28, 2);
	insertInLinkedList(head, 38, 2);

	// delete nodes from SinglyLinkedList
	printSinglyLinkedList(head);
	printf("\n");

	deleteInLinkedList(head, 3);

	printSinglyLinkedList(head);
	printf("\n");

	// delete SinglyLinkedList
	deleteLinkedList(head);

	printf("\n");
	return 0;
}
