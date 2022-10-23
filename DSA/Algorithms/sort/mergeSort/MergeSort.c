#include "MergeSort.h"

/* // declare */
/* void mergeSort(int *arr, int l, int r); */
/* void mergeTheArray(int *arr, int l, int m, int r); */
/* void printArray(int *arr, int n); */

// define
void mergeSort(int *arr, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		mergeTheArray(arr, l, m, r);
	}
}

void mergeTheArray(int *arr, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int *left = (int *) malloc(n1 * sizeof(int));
	int *right = (int *) malloc(n2 * sizeof(int));

	for (int i = 0; i < n1; i++) {
		left[i] = arr[l + i];
	}
	for (int i = 0; i < n2; i++) {
		right[i] = arr[m + i + 1];
	}

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		} else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k++] = left[i++];
	}
	while (j < n2) {
		arr[k++] = right[j++];
	}

	free(left);
	free(right);
}

void printArray(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}
