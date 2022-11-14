#include <iostream>
#include <cstdlib>

#define MAX 10

using std::cout;
using std::endl;

// - Algorithm:
// 		1) Iterate from the last element (arr[n - 1]) to near first element (arr[1])
// 		2) In the inner loop compare two adjacent (lien ke) elements and swap if needed
// 		3) Continue to compare until reach the index iterater of the outer loop


// - Worst, Best, Average case complexity : O(n2)
//
// - Worst case space complexity: O(1)
void bubbleSort(int arr[], int n);

// - We can improve it by using one extra FLAG. No more swaps 
// indicate the completion of sorting. If the list is already 
// sorted, we can use this flag to skip the remaining passes.
//
// - Worst case complexity : O(n2)
// - *Best case complexity: O(n).
// - Average case complexity : O(n2)
void bubbleSortImprove(int arr[], int n);

void printArray(int arr[], int n);

int main() {
	int arr[MAX];

	// Providing a seed value
	srand((unsigned) time(NULL));

	for (int i = 0; i < MAX; i++) {
		int random = (rand() % 6) + 1;
		arr[i] = random;
	}

	cout << "Before:\n";
	printArray(arr, MAX);

	/* bubbleSort(arr, MAX); */
	bubbleSortImprove(arr, MAX);

	cout << "After:\n";
	printArray(arr, MAX);

	return 0;
}

void bubbleSort(int arr[], int n) {
	for (int pass = n - 1; pass > 0; pass--) {
		for (int j = 0; j < pass; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void bubbleSortImprove(int arr[], int n) {
	bool flag = true;
	for (int pass = n - 1; pass > 0 && flag; pass--) {
		flag = false;

		for (int j = 0; j < pass; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				flag = true;
			}
		}
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
