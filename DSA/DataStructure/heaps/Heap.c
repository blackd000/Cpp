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

// all the i for index
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
	int maxIndex = i;

	int left = leftChild(h, i);
	int right = rightChild(h, i);

	if (left != -1 && h->array[left] > h->array[maxIndex]) {
		maxIndex = left;
	} 

	if (right != -1 && h->array[right] > h->array[maxIndex]) {
		maxIndex = right;
	}

	if (maxIndex != i) {
		int temp = h->array[i];
		h->array[i] = h->array[maxIndex];
		h->array[maxIndex] = temp;

		percolateDown(h, maxIndex);
	}
}

int deleteMax(Heap *h) {
	if (h->count == 0) {
		return -1;
	}

	int data = h->array[0];

	h->array[0] = h->array[h->count - 1];
	h->count--;

	percolateDown(h, 0); // at 0 index

	return data;
}

void percolateUp(Heap *h, int i) {
	int parentIndex = parent(h, i);

	/* printf("\n%d\n", parentIndex); */

	if (parentIndex != -1 && h->array[i] > h->array[parentIndex]) {
		int temp = h->array[parentIndex];
		h->array[parentIndex] = h->array[i];
		h->array[i] = temp;

		percolateUp(h, parentIndex);
	}
}

void resizeHeap(Heap *h) {
	int *oldArray = h->array;

	h->array = (int *) malloc(sizeof(int) * h->capacity * 2);

	for (int i = 0; i < h->capacity; i++) {
		h->array[i] = oldArray[i];
	}
	h->capacity *= 2;

	free(oldArray);
}

void insert(Heap *h, int value) {
	if (h->count == h->capacity) {
		resizeHeap(h);
	}

	h->array[h->count++] = value;
	percolateUp(h, h->count - 1);
}

void destroyHeap(Heap *h) {
	if (!h) {
		return;
	}

	free(h->array);
	h->array = NULL;

	free(h);
	h = NULL;
}

void buildHeap(Heap *h, int array[], int n) {
	if (!h) {
		printf("Empty stack\n");
		return;
	}
	while (n > h->capacity) {
		resizeHeap(h);
	}

	for (int i = 0; i < n; i++) {
		h->array[i] = array[i];
	}
	h->count = n;

	for (int i = (n - 1) / 2; i >= 0; i--) {
		percolateDown(h, i);
	}
}

void heapSort(int array[], int n) {
	Heap *h = createHeap(n, 0);

	buildHeap(h, array, n);

	int oldCount = h->count;

	//  Continue this process until the number of remaining elements is one
	for (int i = n - 1; i > 0; i--) {
		int temp = h->array[0];
		h->array[0] = h->array[i];
		h->array[i] = temp;

		h->count--;
	}

	h->count = oldCount;
}
