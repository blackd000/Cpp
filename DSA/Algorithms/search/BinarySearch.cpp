#include <iostream>

using std::cout;

// - Algorithm:
// 	FUNCTION int binarySearchIterative(int array[], int n, int target)
// 		INITIALIZE low = 0 and high = n - 1
// 		WHILE low still less than or equal to high
// 			INITIALIZE mid = low + (high - low) / 2 to find middle point in array
// 			IF target is equal to the element at the mid point
// 				RETURN mid means has been found
// 			ELSE IF target is less than the element at the mid point
// 				SET high = m - 1 means to move to the left half
// 			ELSE target is greater or equal to the element at the mid point
// 				SET low = m + 1 means to move to the right half
// 			END IF
// 		END WHILE
// 		RETURN -1 indicate that the element is not found
//
// - Time complexity: O(logn)
// - Space complexity: O(1)
int binarySearchIterative(int array[], int n, int target);

// - Algorithm:
// 	FUNCTION int binarySearchRecursive(int array[], int low, int high, int target)
// 		IF low is greater than high // this is BASE CASE
// 			RETURN -1
// 		INITIALIZE mid = low + (high - low) / 2 to find middle point
// 		IF target is equal to the element at the mid point
// 			RETURN mid means has been found
// 		ELSE IF target is less than the element at the mid point
// 			RETURN the call recursively on the left half
// 		ELSE target is greater or equal to the element at the mid point
// 			RETURN the call recursively on the right half
// 		END IF
//
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
