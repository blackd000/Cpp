#include "ArrayQueue.c"

ArrayQueue* createQueue(int);
int isEmptyQueue(ArrayQueue*);
int isFullQueue(ArrayQueue*);
int queueSize(ArrayQueue*);
void enQueue(ArrayQueue*, int);
int deQueue(ArrayQueue*);
void deleteQueue(ArrayQueue*);
void printQueue(ArrayQueue*);
