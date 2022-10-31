#include <stdio.h>
#include "LinkedListQueue.h"

int main() {
	Queue *queue = createQueue();

	// enQueue data
	enQueue(queue, 8);
	enQueue(queue, 9);
	enQueue(queue, 12);
	enQueue(queue, 3);

	printQueue(queue);
	printf("\n");

	// deQueue data
	deQueue(queue);
	deQueue(queue);

	printQueue(queue);
	printf("\n");

	deleteQueue(queue);

	printf("\n");
	return 0;
}
