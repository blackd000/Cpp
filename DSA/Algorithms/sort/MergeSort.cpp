#include <iostream>
#include <cstdlib>

#define MAX 10

using std::cout;
using std::endl;

void mergeSort(int arr[], int n);
void merge(int arr[], int leftArray[], int leftSize, int rightArray[], int rightSize);
void printArray(int arr[], int n);

int main() {
	// Providing a seed value
	srand((unsigned) time(NULL));

	// int random = offset + (rand() % range);
	// - offset: The starting point for the range of random numbers
	// - range: The number of values between first and the last possible 
	// random number including the limits.

	int arr[MAX];

	for (int i = 0; i < MAX; i++) {
		int random = 1 + (rand() % 1000);
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

void merge(int arr[], int leftArray[], int leftSize, int rightArray[], int rightSize) {
	int leftIndex = 0, rightIndex = 0, arrIndex = 0;

	while (leftIndex < leftSize && rightIndex < rightSize) {
		if (leftArray[leftIndex] <= rightArray[rightIndex]) {
			arr[arrIndex] = leftArray[leftIndex];
			leftIndex++;
		} else {
			arr[arrIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		arrIndex++;
	}

	while (leftIndex < leftSize) {
		arr[arrIndex] = leftArray[leftIndex];
		leftIndex++;
		arrIndex++;
	}
	while (rightIndex < rightSize) {
		arr[arrIndex] = rightArray[rightIndex];
		rightIndex++;
		arrIndex++;
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
