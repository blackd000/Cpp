#include <iostream>

using std::cout;

// - Algorithm:
// 	1) Begin with the mid element of the whole array as a search key.
// 	2) If the value of the search key is equal to the item then return an 
// 	index of the search key.
// 	3) Or if the value of the search key is less than the item in the middle 
// 	of the interval, narrow the interval to the lower half.
// 	4) Otherwise, narrow it to the upper half.
// 	5) Repeatedly check from the second point until the value is found or the interval is empty.


// - Time complexity: O(logn)
// - Space complexity: O(1)
int binarySearchIterative(int array[], int n, int target);

// - Time complexity: O(logn)
// - Space complexity: O(logn)
int binarySearchRecursive(int array[], int low, int high, int target);

int main() {
	int array[] = { 1, 2, 5, 8, 18, 12, 19 }; // n = 7
	int n = 7;

	cout << binarySearchIterative(array, n, 2);
	/* cout << binarySearchRecursive(array, 0, n - 1, 12); */

	return 0;
}

int binarySearchIterative(int array[], int n, int target) {
	int low = 0, high = n - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (target == array[mid]) {
			return mid;
		} else if (target < array[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return -1;
}

int binarySearchRecursive(int array[], int low, int high, int target) {
	if (low > high) {
		return -1;
	}

	int mid = low + (high - low) / 2;

	if (target == array[mid]) {
		return mid;
	} else if (target < array[mid]) {
		return binarySearchRecursive(array, low, mid - 1, target);
	} else {
		return binarySearchRecursive(array, mid + 1, high, target);
	}
}
