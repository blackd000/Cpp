#include <stdio.h>

// - Time Complexity: O(n). 
// - Space Complexity: O(n) for recursive stack space.
int isArraySorted(int arr[], int n);

int main() {
	int arr[] = { 1, 2, 5, 4 }; // n = 4
	int n = 4;

	printf("is sorted: %d", isArraySorted(arr, n));

	printf("\n");
	return 0;
}

int isArraySorted(int arr[], int n) {
	if (n == 1) {
		return 1;
	}

	return (arr[n - 1] < arr[n - 2] ? 0 : isArraySorted(arr, n - 1));
}
