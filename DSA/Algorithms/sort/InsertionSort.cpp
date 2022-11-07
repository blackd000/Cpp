#include <iostream>

using std::cout;
using std::endl;

// - Algorithm: 
// 		1) Iterate from arr[1] to arr[N] over the array. 
// 		2) Compare the current element (key) to its predecessor. 
// 		3) If the key element is smaller than its predecessor. Move 
// 		the greater elements one position up to make space for the 
// 		swapped element, continue to compare key to the elements before.

// - Worst case complexity: O(n2)
// - *Best case complexity: O(n)
// - Average case complexity: O(n2)
//
// - Worst case space complexity: O(n2) total, O(1) auxiliary
void insertionSort(int arr[], int n);

void printArray(int arr[], int n);

int main() {
	int arr[] = { 8, 1, 3, 2, 15, 4 }; // n = 6
	int n = 6;

	printArray(arr, n);

	insertionSort(arr, n);

	printArray(arr, n);

	return 0;
}

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];

		int j = i;
		// not doing a swap here but look up all the items we have 
		// seen so far and if insertValue (key) is smaller than them then
		// we should shift them to the right to open space to insert insertValue
		while (j >= 1 && key < arr[j - 1]) {
			arr[j] = arr[j - 1];
			j--;
		}

		arr[j] = key;
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
