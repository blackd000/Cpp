#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

struct nodeStack {
	char top;
	int size;
	char* array;	
};
typedef struct nodeStack ArrayStack;

ArrayStack *createStack();
int getSize(ArrayStack *arrayStack);
int isEmptyStack(ArrayStack *arrayStack);
int isFullStack(ArrayStack *arrayStack);
void push(ArrayStack *arrayStack, char data);
char pop(ArrayStack *arrayStack);
void deleteStack(ArrayStack *arrayStack);
void printStack(ArrayStack *arrayStack);

#endif
