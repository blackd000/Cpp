#include "DoublyLinkedList.h"

DLLNode *createNode(int data, DLLNode *predecessor, DLLNode *successor) {
	DLLNode *tempNode = (DLLNode *) malloc(sizeof(DLLNode));

	tempNode->data = data;
	tempNode->next = successor;
	tempNode->prev = predecessor;

	return tempNode;
}

void DLLInsert(DLLNode **head, int data, int position) {
	if (!*head) {
		*head = createNode(data, NULL, NULL);
		return;
	}

	DLLNode *newNode;

	if (position == 0) { // insert node in DoublyLinkedList at the beginning
		newNode = createNode(data, NULL, *head);
		(*head)->prev = newNode;
		*head = newNode;
	} else { // insert node in DoublyLinkedList at somewhere
		int index = 0;
		DLLNode *traver = *head;
		while (traver->next && index < position - 1) {
			index++;
			traver = traver->next;
		}

		if (index != position - 1) {
			printf("\nVi tri may muon them node: %d khong ton tai\n", position);
			return;
		}

		newNode = createNode(data, traver, traver->next);

		// for insert intermediate node (because at the end traver->next is NULL)
		if (traver->next) {
			traver->next->prev = newNode;
		}
		traver->next = newNode;
	}
}

void DLLDelete(DLLNode **head, int position) {
	if (!*head) {
		printf("\nDoubly Linked List is empty\n");
		return;
	}

	DLLNode *tempNode = *head;

	if (position == 0) { // delete node at the beginning
		*head = (*head)->next;
		(*head)->prev = NULL;
	} else { // delete node in DoublyLinkedList at somewhere
		int index = 0;
		while (tempNode && index < position) {
			index++;
			tempNode = tempNode->next;
		}

		if (!tempNode) {
			printf("\nVi tri may dinh xoa: %d khong ton tai\n", position);
			return;
		}

		DLLNode *tempNode2 = tempNode->prev;
		tempNode2->next = tempNode->next;

		// for delete intermediate node (because at the end tempNode->next is NULL)
		if (tempNode->next) {
			tempNode->next->prev = tempNode2;
		}
	}

	free(tempNode);
}

void printDLL(DLLNode **head) {
	for (DLLNode *traver = *head; traver; traver = traver->next) {
		printf("%d ", traver->data);
	}
}
