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
int queueSize(ArrayQueue *);
void enQueue(ArrayQueue *, int);
int deQueue(ArrayQueue *);
void deleteQueue(ArrayQueue *);
void printQueue(ArrayQueue *);

#endif
