#include <stdio.h>
#include "Heap.h"

void test1();
void test2();

int main() {
	test2();

	return 0;
}

void test1() {
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
}

void test2() {
	// test heap sort
	int array[] = { 1, 5, 14, 2, 10, 21, 18, 3, 11, 8, 7, 12 }; // n = 12
	int n = 12;

	/* Heap *heap = createHeap(n, 50); */
	/* buildHeap(heap, array, n); */
	/* printHeap(heap); */
	/* printf("\n"); */

	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	heapSort(array, n);

	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
