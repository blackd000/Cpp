#include <stdio.h>
#include "DoublyLinkedList.h"

int main() {
	DLLNode *head = createNode(19, NULL, NULL);

	head = DLLInsert(head, 13, 0);
	head = DLLInsert(head, 17, 1);
	head = DLLInsert(head, 333, 3);

	printDLL(head);
	printf("\n");

	head = DLLDelete(head, 1);

	printDLL(head);
	printf("\n");

	return 0;
}
