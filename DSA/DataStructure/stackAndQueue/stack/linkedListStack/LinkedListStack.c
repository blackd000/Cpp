#include "LinkedListStack.h"

void push(Stack **top, int data) {
	if (isEmptyStack(*top)) {
		*top = createNode(data);
		return;
	}

	Stack *tempNode = createNode(data);

	tempNode->next = *top;
	*top = tempNode;
}

int pop(Stack **top) {
	if (isEmptyStack(*top)) {
		printf("\nStack is empty\n");
		return INT_MIN;
	}

	int data = (*top)->data;

	Stack *tempNode = *top;
	*top = (*top)->next;

	free(tempNode);

	return data;
}

int top(Stack *head) {
	if (isEmptyStack(head)) {
		return INT_MIN;
	}

	return head->data;
}

int isEmptyStack(Stack *top) {
	return (top == NULL);
}

void deleteStack(Stack **top) {
	Stack *tempNode, *traverNode = *top;

	while (traverNode) {
		tempNode = traverNode;
		traverNode = traverNode->next;
		free(tempNode);
	}

	*top = NULL;
}

void printStack(Stack **top) {
	printSinglyLinkedList(top);
}
