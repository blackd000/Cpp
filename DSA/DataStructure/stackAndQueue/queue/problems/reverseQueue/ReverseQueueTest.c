#include <stdio.h>
#include "ReverseQueue.h"

int main() {
	Queue *queue = createQueue();

	enQueue(queue, 10);
	enQueue(queue, 20);
	enQueue(queue, 30);
	enQueue(queue, 40);
	enQueue(queue, 50);
	enQueue(queue, 60);
	enQueue(queue, 70);
	enQueue(queue, 80);
	enQueue(queue, 90);

	printQueue(queue);
	printf("\n");

	reverseQueueFirstKElement(4, queue);

	printQueue(queue);
	printf("\n");

	printf("\n");
	return 0;
}
