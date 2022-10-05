#include <stdio.h>
#include "Heap.c"

int main() {
	Heap *h = createHeap(10, 1);

	insertHeap(h, 99);
	insertHeap(h, 100);
	insertHeap(h, 92);
	insertHeap(h, 999);
	insertHeap(h, 39);

	printHeap(h);

	printf("\n\nParent of index 3 is: %d", h->array[parent(h, 3)]);

	printf("\n\nLeft child and right child of location 1 is:\n");
	printf("Left: %d, Right: %d\n\n", h->array[leftChild(h, 1)], h->array[rightChild(h, 1)]);

	percolateDown(h, 0);

	printHeap(h);

	return 0;
}
