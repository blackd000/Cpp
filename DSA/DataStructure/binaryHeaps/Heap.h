#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

struct heap {
	int *array;
	int count; // number of elements in Heap
	int capacity; // Size of Heap
	int heapType; // Min Heap or Max Heap
};
typedef struct heap Heap;

Heap *createHeap(int, int);
int parent(Heap *, int);
int leftChild(Heap *, int);
int rightChild(Heap *, int);
int getMaximum(Heap *);
void heapify(Heap *, int);
void percolateUp(Heap *, int);
int deleteMax(Heap *);
void resizeHeap(Heap *);
void insert(Heap *, int);
void destroyHeap(Heap *);
void buildHeap(Heap *, int *, int);
void heapSort(int *, int);
void printHeap(Heap *);

#endif
