#include <stdio.h>
#include "ArrayStack.h"

int main() {
	ArrayStack* testStack = createStack();

	printf("size of the array stack (not capacity): %d\n", getSize(testStack));
	printf("is empty stack: %d\n", isEmptyStack(testStack));
	printf("is full stack: %d\n", isFullStack(testStack));

	// pushing data to stack
	push(testStack, 'd');
	push(testStack, 'o');
	push(testStack, 'n');
	push(testStack, 'g');

	printStack(testStack);
	printf("\n");

	// popping data to stack
	printf("Tao vua moi xoa: %c\n", pop(testStack));

	// print Stack
	/* printf("%s", testStack->array); */
	printStack(testStack);
	printf("\n");
	
	return 0;
}
