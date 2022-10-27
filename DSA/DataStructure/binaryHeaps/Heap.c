#include "Heap.h"

// Time Complexity: O(1).
Heap *createHeap(int capacity, int heapType) {
	Heap *tempHeap = (Heap *) malloc(sizeof(Heap));

	tempHeap->capacity = capacity;
	tempHeap->heapType = heapType;
	tempHeap->count = 0;
	tempHeap->array = (int *) malloc(capacity * sizeof(int));

	return tempHeap;
}

void printHeap(Heap *h) {
	for (int i = 0; i < h->count; i++) {
		printf("%d ", h->array[i]);
	}
}

// all the i for index
// Time Complexity: O(1).
int parent(Heap *h, int i) {
	if (i <= 0 || i > h->count - 1) {
		/* printf("Parent is not exist!!\n"); */
		return -1;
	}

	return ((i - 1) / 2);
}

// Time Complexity: O(1).
int leftChild(Heap *h, int i) {
	if (i * 2 + 1 > h->count - 1) {
		/* printf("Left child is not exist!!\n"); */
		return -1;
	}

	return (i * 2 + 1);
}

// Time Complexity: O(1).
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

// percolate down (heapify) the element at location i
// Time Complexity: O(logn). Heap is a complete binary tree and in the worst case we 
// start at the root and  come down to the leaf. This is equal to the height of the 
// complete binary tree. Space Complexity: O(1)
void heapify(Heap *h, int i) {
	// get index of left child and right child
	int left = leftChild(h, i);
	int right = rightChild(h, i);

	// check max of left child and right child
	int max = i;
	if (left != -1 && h->array[left] > h->array[max]) {
		max = left;
	}
	if (right != -1 && h->array[right] > h->array[max]) {
		max = right;
	}

	// if found max (has left or right) then swap current node with its child
	if (max != i) {
		int temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;

		// after swap, continue to heapify (percolate down) until this element 
		// is satisfies the heap properties
		heapify(h, max);
	}
}

// Time complexity: O(logn)
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

// *** NOTE: Deleting an element uses heapify (PercolateDown)
// Time Complexity: same as Heapify function and it is O(logn).
int deleteMax(Heap *h) {
	if (h->count == 0) {
		printf("heap is NULL\n");
		return -1;
	}

	// swap the last element with the root and reduce the heap size
	int data = h->array[0];
	h->array[0] = h->array[h->count - 1];
	h->count--;

	// After replacing the last element, the tree may not satisfy the heap property. We heapify this element
	heapify(h, 0); // at 0 index

	return data;
}

void resizeHeap(Heap *h) {
	/* // old way doing stuff */
	/* int *oldArray = h->array; */

	/* h->array = (int *) malloc(h->capacity * 2 * sizeof(int)); */

	/* for (int i = 0; i < h->capacity; i++) { */
	/* 	h->array[i] = oldArray[i]; */
	/* } */
	/* h->capacity *= 2; */

	/* free(oldArray); */

	h->capacity *= 2;
	h->array = (int *) realloc(h->array, h->capacity * sizeof(int));

	printf("\nThe head has been resized!!\n");
}

// *** NOTE: Inserting an element uses percolateUp.
// Time Complexity: O(logn). The explanation is the same as that of the Heapify function. 
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
		heapify(h, i);
	}
}

void heapSort(int array[], int n) {
	Heap *h = createHeap(n, 0);

	buildHeap(h, array, n);

	int oldCount = h->count;

	//  Continue this process until the number of remaining elements is one
	for (int i = n - 1; i > 0; i--) {
		int temp = h->array[0];
		h->array[0] = h->array[h->count - 1];
		h->array[h->count - 1] = temp;

		h->count--;
		heapify(h, 0);
	}

	h->count = oldCount;

	for (int i = 0; i < n; i++) {
		array[i] = h->array[i];
	}
}
