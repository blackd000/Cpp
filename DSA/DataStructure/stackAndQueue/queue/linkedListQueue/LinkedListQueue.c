#include "LinkedListQueue.h"

Queue *createQueue() {
	Queue *tempQueue = (Queue *) malloc(sizeof(Queue));

	tempQueue->front = tempQueue->rear = NULL;
	tempQueue->size = 0;

	return tempQueue;
}

int isEmptyQueue(Queue *queue) {
	return (queue->front == NULL);
}

int getSize(Queue *queue) {
	return queue->size;
}

void enQueue(Queue *queue, int data) {
	if (!queue) {
		printf("Queue is NULL\n");
		return;
	}

	queue->size++;

	Node *newNode = createNode(data);

	if (queue->rear) {
		queue->rear->next = newNode;
	}

	queue->rear = newNode;

	if (!queue->front) {
		queue->front = queue->rear;
	}
}

int deQueue(Queue *queue) {
	if (!queue) {
		printf("Queue is NULL\n");
		return INT_MIN;
	}

	if (isEmptyQueue(queue)) {
		printf("Queue is empty\n");
		return INT_MIN;
	}

	queue->size--;

	Node *tempNode = queue->front;
	int data = tempNode->data;
	queue->front = tempNode->next;

	free(tempNode);

	return data;
}

void deleteQueue(Queue *queue) {
	Node *tempQueue;

	while (queue->front) {
		tempQueue = queue->front;
		queue->front = queue->front->next;
		free(tempQueue);
	}

	free(queue);
}

void printQueue(Queue *queue) {
	printSinglyLinkedList(queue->front);
}
