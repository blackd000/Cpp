#include <iostream>

using std::cout;
using std::endl;

// - Algorithm:
// 		1) Build a max heap from the input data. 
// 		2) At this point, the maximum element is stored at the root 
// 		of the heap. Replace it with the last item of the heap followed 
// 		by reducing the size of the heap by 1. Finally, heapify the 
// 		root of the tree. 
// 		3) Repeat step 2 while the size of the heap is greater than 1.


// - Worst case performance: Θ(nlogn)
// - Best case performance: Θ(nlogn)
// - Average case performance: Θ(nlogn)
//
// - Worst case space complexity: Θ(n) total, Θ(1) auxiliary
void heapSort(int arr[], int n);

void heapify(int arr[], int n, int index);

void printHeap(int arr[], int n);

int main() {
	/* int arr[] = { 19, 14, 1, 5, 3, 9, 7 }; */
	int arr[] = { 3, 1, 9, 5, 2, 18, 7 };
	int n = 7;

	printHeap(arr, n);
	heapSort(arr, n);
	printHeap(arr, n);

	return 0;
}

void heapSort(int arr[], int n) {
	// build max Heap (heapify at the last non-leaf node)
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	for (int i = n - 1; i > 0; i--) {
		// move the current root to end
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		// call heapify at location 1 on the REDUCED heap (size = i which is n--)
		heapify(arr, i, 0);
	}
}

void heapify(int arr[], int n, int index) {
	int max = index;
	int leftChild = index * 2 + 1;
	int rightChild = index * 2 + 2;

	if (leftChild < n && arr[leftChild] > arr[max]) {
		max = leftChild;
	}

	if (rightChild < n && arr[rightChild] > arr[max]) {
		max = rightChild;
	}

	if (max != index) {
		int temp = arr[index];
		arr[index] = arr[max];
		arr[max] = temp;

		heapify(arr, n, max);
	}
}

void printHeap(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
