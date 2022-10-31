#include "ReverseQueue.h"

void reverseQueueFirstKElement(int k, Queue *queue) {
	if (!queue || k > getSize(queue)) {
		printf("Error\n");
		return;
	}

	Stack **stack = (Stack **) malloc(sizeof(Stack *));

	for (int i = 0; i < k; i++) {
		push(stack, deQueue(queue));
	}

	// pop all of the stack and enQueue
	for (int i = 0; i < k; i++) {
		enQueue(queue, pop(stack));
	}

	for (int i = 0; i < getSize(queue) - k; i++) {
		enQueue(queue, deQueue(queue));
	}
}
