#include "Heap.h"

/* Heap *createHeap(int capacity, int heapType) { */
/* 	Heap *tempHeap = (Heap *) malloc(sizeof(Heap)); */

/* 	tempHeap->capacity = capacity; */
/* 	tempHeap->heapType = heapType; */
/* 	tempHeap->count = 0; */
/* 	tempHeap->array = (int *) malloc(capacity * sizeof(int)); */

/* 	return tempHeap; */
/* } */

// - All i stands for for index
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

	// if found max (has left or right) then swap the current node with its child
	if (max != i) {
		int temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;

		// after swap, continue to heapify (percolate down) until this element 
		// is satisfies the heap properties
		heapify(h, max);
	}
}

void percolateUp(Heap *h, int i) {
	int parentIndex = parent(h, i);

	// if the current node is greater than its parent then swap them
	if (parentIndex != -1 && h->array[i] > h->array[parentIndex]) {
		int temp = h->array[parentIndex];
		h->array[parentIndex] = h->array[i];
		h->array[i] = temp;

		// after swap, continue to percolate up until this element is satisfies 
		// the heap properties
		percolateUp(h, parentIndex);
	}
}

int deleteMax(Heap *h) {
	if (h->count == 0) {
		cout << "Heap is NULL\n";
		return -1;
	}

	// replacing the last element with the first element and reduce the heap size
	int data = h->array[0];
	h->array[0] = h->array[h->count - 1];
	h->count--; // reducing the heap size

	// after replacing the last element, the tree may not satisfy the heap 
	// property. We heapify (Percolate Down) this element
	heapify(h, 0); // at 0 index

	return data;
}

void resizeHeap(Heap *h) {
	// ** NOTE: DO NOT mix realloc with new
	
	// ---------------------- Using C ---------------------- //
	/* // old way doing stuff */
	/* int *oldArray = h->array; */
	/* h->array = (int *) malloc(h->capacity * 2 * sizeof(int)); */
	/* for (int i = 0; i < h->capacity; i++) { */
	/* 	h->array[i] = oldArray[i]; */
	/* } */
	/* h->capacity *= 2; */
	/* free(oldArray); */

	/* // better way */
	/* h->capacity *= 2; */
	/* h->array = (int *) realloc(h->array, h->capacity * sizeof(int)); */

	// --------------------- Using C++ --------------------- //
	int *oldArray = h->array;
	h->array = new int[h->capacity * 2];
	for (int i = 0; i < h->capacity; i++) {
		h->array[i] = oldArray[i];
	}
	h->capacity *= 2;
	delete(oldArray);

	cout << "The head has been resized!!\n";
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

	delete(h->array);
	h->array = NULL;

	delete(h);
	h = NULL;
}

void buildHeap(Heap *h, int array[], int n) {
	if (!h) {
		cout << "Empty stack\n";
		return;
	}
	while (n > h->capacity) {
		resizeHeap(h);
	}

	for (int i = 0; i < n; i++) {
		h->array[i] = array[i];
	}
	h->count = n;

	// index of the last non-leaf node
	int startIndex = (n / 2) - 1;

	// Perform reverse Level Order Traversal from last non-leaf 
	// node and heapify each node
	for (int i = startIndex; i >= 0; i--) {
		heapify(h, i);
	}
}

void heapSort(int array[], int n) {
	/* Heap *h = createHeap(n, 0); */
	Heap *h = new Heap(n, 0);

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

void printHeap(Heap *h) {
	for (int i = 0; i < h->count; i++) {
		cout << h->array[i] << " ";
	}
}
