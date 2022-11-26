#include <iostream>
#include "Heap.h"

using std::cout;
using std::endl;

void test1();
void test2();

int main() {
	/* test1(); */
	test2();

	cout << endl;
	return 0;
}

void test1() {
	/* Heap *h = createHeap(1, 0); */
	Heap *h = new Heap(1, 0);

	insert(h, 3);
	insert(h, 100);
	insert(h, 24);
	insert(h, 12);
	insert(h, 39);

	cout << endl;
	printHeap(h);
	cout << endl;

	cout << "\nParent of index 3 is: " << h->array[parent(h, 3)] << endl;

	cout << "Left child and right child of location 1 is: ";
	cout << h->array[leftChild(h, 1)] << " and " << h->array[rightChild(h, 1)] << endl;

	/* percolateDown(h, 0); */

	// delete max value of the heap
	cout << "\nI have just removed first element (max value) in Heap: " << deleteMax(h) << endl;

	cout << endl;
	printHeap(h);
	cout << endl;
}

void test2() {
	// test heap sort
	int array[] = { 1, 5, 14, 2, 10, 21, 18, 3, 11, 8, 7, 12 }; // n = 12
	int n = 12;

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	heapSort(array, n);

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
