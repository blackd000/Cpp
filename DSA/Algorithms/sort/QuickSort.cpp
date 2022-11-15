#include <iostream>
#include <cstdlib>

#define MAX 10

using std::cout;
using std::endl;

// - Algorithm:
// 	quickSort():
// 		1) If there are ONE or NO elements in the array to be sorted, then return (base case).
// 		2) Pick an element in the array to serve as the "pivot" point. (Usually the right-most
// 		element in the array is used).
// 		3) Split the array into two parts (partition) – one with elements smaller than 
// 		the pivot put them to the left side of the pivot and the other with elements larger 
// 		than the pivot put them to the right side of the pivot.
// 		4) Recursively repeat the algorithm for both halves of the original array.
//
// 	// - Hoare’s Partition Scheme.
// 	partition():
// 		1) Initializing two indexes that start at two ends
// 		2) The two indexes move toward each other until an INVERSION (A greater value 
// 		on the left side and smaller value on the right side) is found.
// 		3) When an inversion is found, two values are swapped and the process is repeated. 
// 		4) If those two index are met then if pivot are smaller than index value then swap 
// 		so the index to partition is itself, else not swap so the index to partition is 
// 		the pivot index (edge case).


// - *Worst case Complexity: O(n2)
// - Best case Complexity: O(nlogn)
// - Average case Complexity: O(nlogn)
//
// - Worst case space Complexity: O(1)
void quickSort(int arr[], int n);
void quickSort(int arr[], int lowIndex, int highIndex);

int partition(int arr[], int lowIndex, int highIndex, int pivot);

void swap(int arr[], int indexOne, int indexTwo);

void printArray(int arr[], int n);

int main() {
	srand((unsigned) time(NULL));

	int arr[MAX];

	for (int i = 0; i < MAX; i++) {
		int random = (rand() % 1000) + 1;
		arr[i] = random;
	}

	cout << "Before:\n";
	printArray(arr, MAX);

	quickSort(arr, MAX);

	cout << "After:\n";
	printArray(arr, MAX);

	return 0;
}

void quickSort(int arr[], int n) {
	quickSort(arr, 0, n - 1);
}

void quickSort(int arr[], int lowIndex, int highIndex) {
	// if one or no elements in the array, return
	if (lowIndex >= highIndex) {
		return;
	}

	// choose the pivot as the right-most element in the array (randomly)
	int randomIndexPivot = (rand() % (highIndex - lowIndex)) + lowIndex;
	swap(arr, randomIndexPivot, highIndex);
	int pivot = arr[highIndex];

	// left of this partitionIndex contains smaller elements than this partitionIndex element
	// right of this partitionIndex contains larger elements than this partitionIndex element
	int partitionIndex = partition(arr, lowIndex, highIndex, pivot);

	quickSort(arr, lowIndex, partitionIndex - 1);
	quickSort(arr, partitionIndex + 1, highIndex);
}

int partition(int arr[], int lowIndex, int highIndex, int pivot) {
	int leftPointer = lowIndex;
	int rightPointer = highIndex - 1;

	while (leftPointer < rightPointer) {
		// find left-most element GREATER than pivot
		while (arr[leftPointer] <= pivot && leftPointer < rightPointer) {
			leftPointer++;
		}
		// find right-most element SMALLER than pivot
		while (arr[rightPointer] >= pivot && leftPointer < rightPointer) {
			rightPointer--;
		}

		swap(arr, leftPointer, rightPointer);
	}

	// edge case ==> swap if the pivot is less than the stop element (which is
	// where leftPointer equal to rightPointer) so the return index is itself (leftPointer), 
	// else not swap and the return index is the pivot index (highIndex)
	if (pivot < arr[leftPointer]) {
		swap(arr, leftPointer, highIndex);
	} else {
		leftPointer = highIndex;
	}

	return leftPointer;
}

void swap(int arr[], int indexOne, int indexTwo) {
	int temp = arr[indexOne];
	arr[indexOne] = arr[indexTwo];
	arr[indexTwo] = temp;
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
