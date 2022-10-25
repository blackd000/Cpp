#include <stdio.h>
#include "DoublyLinkedList.h"

int main() {
	DLLNode **head = (DLLNode **) malloc(sizeof(DLLNode *));

	DLLInsert(head, 13, 0);
	DLLInsert(head, 17, 1);
	DLLInsert(head, 333, 1);
	DLLInsert(head, 178, 2);

	printDLL(head);
	printf("\n");

	DLLDelete(head, 1);

	printDLL(head);
	printf("\n");

	printf("\n");
	return 0;
}
