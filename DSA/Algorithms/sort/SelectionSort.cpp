#include <iostream>

using std::cout;
using std::endl;

// - Algorithm:
// 		1. Find the minimum value in the list compare to the current value
// 		2. Swap it with the value in the current position
// 		3. Repeat this process for all the elements until the entire array 
// 		is sorted


// - Worst, Best, Average case complexity : O(n2)
//
// - Worst case space complexity: O(1) auxiliary
void selectionSort(int arr[], int n);

void printArray(int arr[], int n);

int main() {
	int arr[] = { 3, 1, 19, 8, 2, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, n);

	selectionSort(arr, n);

	printArray(arr, n);

	return 0;
}

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
