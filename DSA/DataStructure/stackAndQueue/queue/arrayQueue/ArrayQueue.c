#include "ArrayQueue.h"

ArrayQueue *createQueue(int size) {
	ArrayQueue *Q = (ArrayQueue *) (malloc(sizeof(ArrayQueue)));

	Q->front = Q->rear = -1;
	Q->capacity = size;
	Q->array = (int*) (malloc(Q->capacity * sizeof(int)));

	return Q;
}

int isEmptyQueue(ArrayQueue *Q) {
	return (Q->front == -1);
}

int isFullQueue(ArrayQueue *Q) {
	return ((Q->rear + 1) % Q->capacity == Q->front);
}

int queueSize(ArrayQueue *Q) {
	return ((Q->capacity - Q->front + Q->rear + 1) % Q->capacity);
}

void enQueue(ArrayQueue *Q, int data) {
	if (isFullQueue(Q)) {
		printf("Exception: Queue Overflow\n");
	} else {
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = data;

		if (Q->front == -1) {
			Q->front = Q->rear;
		}
	}
}

int deQueue(ArrayQueue *Q) {
	int data = 0;
	if (isEmptyQueue(Q)) {
		printf("Exception: Queue is empty");
	} else {
		data = Q->array[Q->front];
		if (Q->front == Q->rear) {
			Q->front = Q->rear = -1;
		} else {
			Q->front = (Q->front + 1) % Q->capacity;
		}
	}

	return data;
}

void deleteQueue(ArrayQueue *Q) {
	free(Q->array);
	free(Q);
}

void printQueue(ArrayQueue *Q) {
	if (isEmptyQueue(Q)) {
		printf("Exception: Queue is empty!!");
		return;
	}

	do {
		printf("%d ", Q->array[Q->front]);

		Q->front = (Q->front + 1) % Q->capacity;
	} while (Q->front != (Q->rear + 1) % Q->capacity);
}
