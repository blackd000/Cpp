#include "CircularLinkedList.h"

CLLNode *createNode(int data) {
	CLLNode *tempNode = (CLLNode *) malloc(sizeof(CLLNode));

	tempNode->data = data;
	tempNode->next = tempNode;

	return tempNode;
}

CLLNode *insertAtEndInCLL(CLLNode *head, int data) {
	if (!head) {
		head = createNode(data);
		return head;
	}

	CLLNode *newNode = createNode(data);

	newNode->next = head;

	CLLNode *current = head;
	while (current->next != head) {
		current = current->next;
	}

	current->next = newNode;

	return head;
}

void printCLL(CLLNode *head) {
	CLLNode *current = head;
	do {
		printf("%d ", current->data);
		current = current->next;
	} while (current != head);
}
