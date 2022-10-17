#include <stdio.h>
#include "MergeSort.c"

int main() {
	int arr[] = { 38, 27, 43, 3, 9, 82, 10 }; // n = 7
	/* int arr[] = { 38, 27 }; */
	int n = 7;

	printArray(arr, n);
	mergeSort(arr, 0, n);
	printArray(arr, n);

	return 0;
}
