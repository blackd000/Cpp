#include <stdio.h>
#include "CircularLinkedList.h"

int main() {
	/* CLLNode *head = createNode(19); */
	CLLNode *head = NULL;

	head = insertAtEndInCLL(head, 8);
	head = insertAtEndInCLL(head, 18);
	head = insertAtEndInCLL(head, 23);
	head = insertAtEndInCLL(head, 39);

	printCLL(head);
	printf("\n");

	printf("\n");
	return 0;
}
