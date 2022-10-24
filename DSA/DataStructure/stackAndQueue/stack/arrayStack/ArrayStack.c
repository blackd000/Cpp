#include "ArrayStack.h"

ArrayStack *createStack() {
	ArrayStack *arrayStack = (ArrayStack *) (malloc(sizeof(ArrayStack)));
	
	arrayStack->size = MAX_LENGTH;
	arrayStack->top = -1;
	arrayStack->array = (char *) (malloc(arrayStack->size * sizeof(char)));

	return arrayStack;
}

int getSize(ArrayStack *arrayStack) {
	return (arrayStack->top + 1);
}

int isEmptyStack(ArrayStack *arrayStack) {
	return (arrayStack->top == -1);
}

int isFullStack(ArrayStack *arrayStack) {
	return (arrayStack->top == arrayStack->size - 1);
}

void push(ArrayStack *arrayStack, char data) {
	if (isFullStack(arrayStack)) {
		printf("Stack overflow");
	} else {
		arrayStack->array[++arrayStack->top] = data;
	}
}

char pop(ArrayStack *arrayStack) {
	if (isEmptyStack(arrayStack)) {
		printf("Stack is underflow");
		return -1;
	} else {
		return (arrayStack->array[arrayStack->top--]);
	}
}

void deleteStack(ArrayStack *arrayStack) {
	free(arrayStack->array);
	free(arrayStack);
}

void printStack(ArrayStack *arrayStack) {
	for (int i = 0; i < arrayStack->top + 1; i++) {
		printf("%c", arrayStack->array[i]);
	}
}
