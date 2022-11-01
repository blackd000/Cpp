#ifndef HEAP_H
#define HEAP_H

#include <iostream>

using std::cout;
using std::endl;

/* struct heap { */
/* 	int *array; */
/* 	int count; // number of elements in Heap */
/* 	int capacity; // Size of Heap */
/* 	int heapType; // Min Heap or Max Heap */
/* }; */
/* typedef struct heap Heap; */

class Heap {
public:
	int *array;
	int count; // number of elements in Heap
	int capacity; // Size of Heap
	int heapType; // Min Heap or Max Heap

	Heap(int capacity, int heapType) {
		this->capacity = capacity;
		this->heapType = heapType;
		count = 0;
		array = new int[this->capacity];
	}
};

/* // - Time Complexity: O(1) */
/* Heap *createHeap(int capacity, int heapType); */

// - All i stands for for index
// - Time Complexity: O(1).
int parent(Heap *h, int i);

// - Time Complexity: O(1).
int leftChild(Heap *h, int i);

// - Time Complexity: O(1).
int rightChild(Heap *h, int i);

// - Time Complexity: O(1).
int getMaximum(Heap *h);

// - Percolate Down (heapify) the element at location i
// - Time Complexity: O(logn). Heap is a complete binary tree and 
// in the worst case we start at the root and  come down to the leaf. 
// This is equal to the height of the complete binary tree. 
// - Space Complexity: O(1)
void heapify(Heap *h, int i);

// - Time complexity: O(logn)
void percolateUp(Heap *h, int i);

// *** NOTE: Deleting an element uses heapify (Percolate Down)
// - Time Complexity: O(logn). (Same as Heapify function)
int deleteMax(Heap *h);

void resizeHeap(Heap *);

// *** NOTE: Inserting an element uses Percolate Up.
// - Time Complexity: O(logn). The explanation is the same as 
// that of the Heapify function. 
void insert(Heap *, int);

void destroyHeap(Heap *);

// - Time Complexity: O(n).
void buildHeap(Heap *, int *, int);

// - Time Complexity: O(nlogn). As we remove the elements from the 
// heap, the values become sorted (since maximum elements are always 
// root only). Since the time complexity of both the insertion algorithm 
// and deletion algorithm is O(logn) (where n is the number of items 
// in the heap), the time complexity of the heap sort algorithm is O(nlogn)
void heapSort(int *, int);

void printHeap(Heap *);

#endif
