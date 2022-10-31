#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../../linkedList/singlyLinkedList/SinglyLinkedList.h"

struct queue {
	Node *front;
	Node *rear;
	int size;
};
typedef struct queue Queue;

Queue *createQueue();

// - Time Complexity: O(1)
int isEmptyQueue(Queue *queue);

// - Time Complexity: O(1)
int getSize(Queue *queue);

// - Time Complexity: O(1)
void enQueue(Queue *queue, int data);

// - Time Complexity: O(1)
int deQueue(Queue *queue);

// - Time Complexity: O(1)
void deleteQueue(Queue *queue);

// - Time Complexity: O(n)
void printQueue(Queue *queue);

#endif
