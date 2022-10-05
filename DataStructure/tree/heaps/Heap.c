#include <stdio.h>
#include <stdlib.h>

struct heap {
	int *array;
	int count; // number of elements in Heap
	int capacity; // Size of Heap
	int heapType; // Min Heap or Max Heap
};
typedef struct heap Heap;

Heap *createHeap(int capacity, int heapType) {
	Heap *tempHeap = (Heap *) malloc(sizeof(Heap));

	tempHeap->capacity = capacity;
	tempHeap->heapType = heapType;
	tempHeap->count = 0;

	tempHeap->array = (int *) malloc(capacity * sizeof(int));

	return tempHeap;
}

void insertHeap(Heap *h, int value) {
	if (!h) {
		printf("Empty Head!!\n");
		return;
	}

	h->array[h->count++] = value;
}

void printHeap(Heap *h) {
	for (int i = 0; i < h->count; i++) {
		printf("%d ", h->array[i]);
	}
}

int parent(Heap *h, int i) {
	if (i <= 0 || i > h->count - 1) {
		/* printf("Parent is not exist!!\n"); */
		return -1;
	}

	return ((i - 1) / 2);
}

int leftChild(Heap *h, int i) {
	if (i * 2 + 1 > h->count - 1) {
		/* printf("Left child is not exist!!\n"); */
		return -1;
	}

	return (i * 2 + 1);
}

int rightChild(Heap *h, int i) {
	if (i * 2 + 2 > h->count - 1) {
		/* printf("Right child is not exist!!\n"); */
		return -1;
	}

	return (i * 2 + 2);
}

int getMaximum(Heap *h) {
	if (h->count == 0) {
		return -1;
	}

	return (h->array[0]);
}

void percolateDown(Heap *h, int i) {
	int max = i;

	int left = leftChild(h, i);
	int right = rightChild(h, i);

	if (left != -1 && h->array[left] > h->array[max]) {
		max = left;
	} 

	if (right != -1 && h->array[right] > h->array[max]) {
		max = right;
	}

	if (max != i) {
		int temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;

		percolateDown(h, max);
	}

}
