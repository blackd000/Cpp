#include <stdio.h>
#include "Heap.c"

int main() {
	int array[] = { 1, 5, 14, 2, 10, 21, 18, 3, 11, 8, 7, 12 }; // n = 12
	int n = 12;

	Heap *heap = createHeap(n, 8);

	/* buildHeap(heap, array, n); */

	heapSort(array, n);

	printHeap(heap);

	return 0;
}
