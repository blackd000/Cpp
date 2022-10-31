#include <stdio.h>
#include "LinkedListStack.h"

int main() {
	Stack **stack = (Stack **) malloc(sizeof(Stack *));

	// push data into stack
	push(stack, 8);
	push(stack, 18);
	push(stack, 13);
	push(stack, 69);

	printStack(*stack);
	printf("\n");

	// pop data
	printf("Tao vua moi xoa: %d\n", pop(stack));
	printf("Tao vua moi xoa: %d\n", pop(stack));

	printStack(*stack);
	printf("\n");

	deleteStack(stack);

	printf("\n");
	return 0;
}
