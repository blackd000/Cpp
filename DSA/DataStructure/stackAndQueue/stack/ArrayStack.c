#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

struct nodeStack {
	char top;
	int size;
	char* array;	
};
typedef struct nodeStack ArrayStack;

ArrayStack* createStack() {
	ArrayStack* arrayStack = (ArrayStack*) (malloc(sizeof(ArrayStack)));
	
	arrayStack->size = MAX_LENGTH;
	arrayStack->top = -1;
	arrayStack->array = (char*) (malloc(arrayStack->size * sizeof(char)));

	return arrayStack;
}

int getSize(ArrayStack* arrayStack) {
	return (arrayStack->top + 1);
}

int isEmptyStack(ArrayStack* arrayStack) {
	return (arrayStack->top == -1);
}

int isFullStack(ArrayStack* arrayStack) {
	return (arrayStack->top == arrayStack->size - 1);
}

void push(ArrayStack* arrayStack, char data) {
	if (isFullStack(arrayStack)) {
		printf("Stack overflow");
	} else {
		arrayStack->array[++arrayStack->top] = data;
	}
}

char pop(ArrayStack* arrayStack) {
	if (isEmptyStack(arrayStack)) {
		printf("Stack is underflow");
		return -1;
	} else {
		return (arrayStack->array[arrayStack->top--]);
	}
}

void deleteStack(ArrayStack* arrayStack) {
	free(arrayStack->array);
	free(arrayStack);
}

void printStack(ArrayStack* arrayStack) {
	for (int i = 0; i < arrayStack->top + 1; i++) {
		printf("%c", arrayStack->array[i]);
	}
}

/* int main() { */
/* 	ArrayStack* testStack = createStack(); */

/* 	printf("%d\n", getSize(testStack)); */
/* 	printf("%d\n", isEmptyStack(testStack)); */
/* 	printf("%d\n", isFullStack(testStack)); */

/* 	// pushing data to stack */
/* 	push(testStack, 'd'); */
/* 	push(testStack, 'o'); */
/* 	push(testStack, 'n'); */
/* 	push(testStack, 'g'); */

/* 	// popping data to stack */
/* 	printf("Tao vua moi xoa: %c\n", pop(testStack)); */

/* 	// print Stack */
/* 	/1* printf("%s", testStack->array); *1/ */
/* 	printStack(testStack); */
	
/* 	return 0; */
/* } */
