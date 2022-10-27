#include "CircularLinkedList.h"

CLLNode *createNode(int data) {
	CLLNode *tempNode = (CLLNode *) malloc(sizeof(CLLNode));

	tempNode->data = data;
	tempNode->next = tempNode;

	return tempNode;
}

void insertAtEndInCLL(CLLNode **head, int data) {
	if (!*head) {
		*head = createNode(data);
		return;
	}

	CLLNode *newNode = createNode(data);

	newNode->next = *head;

	CLLNode *current = *head;
	while (current->next != *head) {
		current = current->next;
	}

	current->next = newNode;
}

void insertAtBeginInCLL(CLLNode **head, int data) {
	if (!*head) {
		*head = createNode(data);
		return;
	}

	CLLNode *newNode = createNode(data);

	newNode->next = *head;

	CLLNode *current = *head;
	while (current->next != *head) {
		current = current->next;
	}

	current->next = newNode;

	*head = newNode;
}

void deleteLastNodeInCLL(CLLNode **head) {
	if (!*head) {
		printf("The CircularLinkedList is empty");
		return;
	}

	CLLNode *current = *head, *prevNode;

	while (current->next != *head) {
		prevNode = current;
		current = current->next;
	}

	prevNode->next = *head;
	free(current);
}

void deleteFrontNodeInCLL(CLLNode **head) {
	if (!*head) {
		printf("The CircularLinkedList is empty");
		return;
	}

	CLLNode *current = *head;

	while (current->next != *head) {
		current = current->next;
	}

	CLLNode *tempNode = *head;

	current->next = (*head)->next;
	*head = (*head)->next;

	free(tempNode);
}

void printCLL(CLLNode **head) {
	CLLNode *current = *head;
	do {
		printf("%d ", current->data);
		current = current->next;
	} while (current != *head);
}
