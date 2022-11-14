#include <iostream>
#include <cstdlib>

#define MAX 10

using std::cout;
using std::endl;

// - Algorithm:
// 		mergeSort():
// 			1) Create a base case that if length is less than or equal to 1 (only 1 element
// 			remain in array) then return
// 			2) Find the middle point to divide the array into two halves (mid = n / 2)
// 			3) Create two array, left array has mid size, right array has n - mid size
// 			4) Call mergeSort() for left array
// 			5) Call mergeSort() for right array
// 			6) Call merge() to merge the two halves SORTED array in step 4 and 5
//
// 		merge():
// 			1) While left array and right array has element, compare each element of left
// 			and right
// 			2) If left element is less than right array, insert left element in merge array
// 			and vice versa
// 			3) While left array or right array has element then copy them to the merge array


// - Worst, Best, Average case complexity : Θ(nlogn)
//
// - Worst case space complexity: Θ(n) auxiliary
void mergeSort(int arr[], int n);

void merge(int arr[], int leftArray[], int leftSize, int rightArray[], int rightSize);

void printArray(int arr[], int n);

int main() {
	// Providing a seed value
	srand((unsigned) time(NULL));

	int arr[MAX];

	for (int i = 0; i < MAX; i++) {
		int random = (rand() % 1000) + 1;
		arr[i] = random;
	}

	cout << "Before:\n";
	printArray(arr, MAX);

	mergeSort(arr, MAX);

	cout << "After:\n";
	printArray(arr, MAX);

	return 0;
}

void mergeSort(int arr[], int n) {
	if (n <= 1) {
		return;
	}

	int midIndex = n / 2;
	int leftSize = midIndex, rightSize = n - midIndex;

	int *leftArray = new int[leftSize];
	int *rightArray = new int[rightSize];

	for (int i = 0; i < leftSize; i++) {
		leftArray[i] = arr[i];
	}
	for (int i = leftSize; i < n; i++) {
		rightArray[i - leftSize] = arr[i];
	}

	mergeSort(leftArray, leftSize);
	mergeSort(rightArray, rightSize);
	merge(arr, leftArray, leftSize, rightArray, rightSize);

	delete[] leftArray;
	delete[] rightArray;
}

void merge(int mergeArray[], int leftArray[], int leftSize, int rightArray[], int rightSize) {
	int leftIndex = 0, rightIndex = 0, mergeIndex = 0;

	while (leftIndex < leftSize && rightIndex < rightSize) {
		if (leftArray[leftIndex] <= rightArray[rightIndex]) {
			mergeArray[mergeIndex] = leftArray[leftIndex];
			leftIndex++;
		} else {
			mergeArray[mergeIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		mergeIndex++;
	}

	while (leftIndex < leftSize) {
		mergeArray[mergeIndex] = leftArray[leftIndex];
		leftIndex++;
		mergeIndex++;
	}
	while (rightIndex < rightSize) {
		mergeArray[mergeIndex] = rightArray[rightIndex];
		rightIndex++;
		mergeIndex++;
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
