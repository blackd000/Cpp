#include <stdio.h>
#include "Heap.c"

int main() {
	Heap *h = createHeap(10, 1);

	insert(h, 3);
	insert(h, 100);
	insert(h, 24);
	insert(h, 12);
	insert(h, 39);

	printHeap(h);

	printf("\n\nParent of index 3 is: %d", h->array[parent(h, 3)]);

	printf("\n\nLeft child and right child of location 1 is:\n");
	printf("Left: %d, Right: %d\n\n", h->array[leftChild(h, 1)], h->array[rightChild(h, 1)]);

	/* percolateDown(h, 0); */

	// delete max value of the heap
	printHeap(h);
	printf("\nI just removed %d\n", deleteMax(h));
	printHeap(h);

	return 0;
}
