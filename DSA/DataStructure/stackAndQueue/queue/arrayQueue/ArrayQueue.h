#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct arrayQueue {
	int front, rear;
	int capacity;
	int* array;
};
typedef struct arrayQueue ArrayQueue;

ArrayQueue *createQueue(int);
int isEmptyQueue(ArrayQueue *);
int isFullQueue(ArrayQueue *);

// Time Complexity: O(1)
int queueSize(ArrayQueue *);

// Time Complexity: O(1)
void enQueue(ArrayQueue *, int);

// Time Complexity: O(1)
int deQueue(ArrayQueue *);

// Time Complexity: O(1)
void deleteQueue(ArrayQueue *);

// Time Complexity: O(n)
void printQueue(ArrayQueue *);

#endif
