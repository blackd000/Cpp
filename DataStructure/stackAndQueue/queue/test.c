#include <stdio.h>
#include "ArrayQueue.h"

int main() {
	ArrayQueue* test = createQueue(10);

	enQueue(test, 8);
	enQueue(test, 9);

	printQueue(test);

	return 0;
}
