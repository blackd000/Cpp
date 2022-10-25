#include <stdio.h>
#include "SinglyLinkedList.h"

Node *createNode(int data) {
	Node *tempNode = (Node *) malloc(sizeof(Node));

	tempNode->data = data;
	tempNode->next = NULL;

	return tempNode;
}

void insertInLinkedList(Node **head, int data, int position) {
	if (!*head) {
		*head = createNode(data);
		return;
	}

	Node *traverNode, *newNode;

	traverNode = *head;
	newNode = createNode(data);

	if (position == 0) { // inserting at the beginning
		newNode->next = *head;
		*head = newNode;
	} else { // traverse the list until reach the position
		int index = 0;
		/* Node *tempNode; */
		while (traverNode->next && index < position - 1) {
			index++;
			/* tempNode = traverNode; */
			traverNode = traverNode->next;
		}

		if (index != position - 1) {
			printf("\nVi tri may muon them: %d khong ton tai\n", position);
			return;
		}

		newNode->next = traverNode->next;
		traverNode->next = newNode;
	}
}

void deleteInLinkedList(Node **head, int position) {
	Node *traverNode = *head, *tempNode;

	if (position == 0) { // delete at the beginning
		*head = (*head)->next;
		free(traverNode);
	} else { // delete at the position we want
		int index = 0;
		while (traverNode && index < position) {
			index++;
			tempNode = traverNode;
			traverNode = traverNode->next;
		}

		if (!traverNode) {
			printf("\nVi tri may dinh xoa: %d khong ton tai\n", position);
		} else {
			tempNode->next = traverNode->next;
			free(traverNode);
		}
	}
}

void deleteLinkedList(Node **head) {
	Node *auxilaryNode, *traverNode = *head;
	
	while (traverNode) {
		auxilaryNode = traverNode;
		traverNode = traverNode->next;
		free(auxilaryNode);
	}

	*head = NULL; // to affect the real head back in the caller
}

void printSinglyLinkedList(Node **head) {
	for (Node *traver = *head; traver; traver = traver->next) {
		printf("%d ", traver->data);
	}
}
