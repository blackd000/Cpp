#include <stdio.h>
#include "CircularLinkedList.h"

int main() {
	/* CLLNode *head = createNode(19); */
	CLLNode **head = (CLLNode **) malloc(sizeof(CLLNode *));

	// insert at the end of a CircularLinkedList
	insertAtEndInCLL(head, 8);
	insertAtEndInCLL(head, 18);
	insertAtEndInCLL(head, 23);
	insertAtEndInCLL(head, 39);

	// insert at the front of a CircularLinkedList
	insertAtBeginInCLL(head, 11);
	insertAtBeginInCLL(head, 14);

	printCLL(head);
	printf("\n");

	// delete the last node in a CircularLinkedList
	deleteLastNodeInCLL(head);
	deleteLastNodeInCLL(head);

	printCLL(head);
	printf("\n");

	// delete the first node in a CircularLinkedList
	deleteFrontNodeInCLL(head);
	
	printCLL(head);
	printf("\n");

	printf("\n");
	return 0;
}
