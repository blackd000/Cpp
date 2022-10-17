#include <stdio.h>
#include "ArrayQueue.h"

int main() {
	ArrayQueue* test = createQueue(10);

	// enQueue
	enQueue(test, 8);
	enQueue(test, 9);
	enQueue(test, 19);
	enQueue(test, 30);

	// deQueue
	deQueue(test);
	deQueue(test);

	printQueue(test);

	return 0;
}
