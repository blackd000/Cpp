#include <stdio.h>
#include "SinglyLinkedList.h"

int main() {
	Node *head = createNode(8);

	head = insertInLinkedList(head, 9, 0);
	head = insertInLinkedList(head, 18, 1);
	head = insertInLinkedList(head, 28, 2);
	head = insertInLinkedList(head, 38, 2);

	// delete nodes from SinglyLinkedList
	printSinglyLinkedList(head);
	printf("\n");

	head = deleteInLinkedList(head, 3);

	printSinglyLinkedList(head);
	printf("\n");

	// delete SinglyLinkedList
	deleteLinkedList(head);

	return 0;
}
