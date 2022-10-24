#include <stdio.h>
#include "ArrayQueue.h"

int main() {
	ArrayQueue* queue = createQueue(10);

	// enQueue
	enQueue(queue, 8);
	enQueue(queue, 9);
	enQueue(queue, 19);
	enQueue(queue, 30);

	printQueue(queue);
	printf("\n");

	// deQueue
	deQueue(queue);
	deQueue(queue);

	printQueue(queue);
	printf("\n");

	return 0;
}
