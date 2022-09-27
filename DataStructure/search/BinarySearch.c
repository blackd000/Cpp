#include <stdio.h>

int binarySearch(int*, int, int, int);

int main() {
	int array[] = { 1, 2, 5, 8, 18, 12, 19 }; // n = 7
	int n = 7;

	printf("%d", binarySearch(array, 0, n, 19));
}

int binarySearch(int* array, int l, int r, int target) {
	while (l < r) {
		int m = (l + r) / 2;
		
		if (target == array[m]) {
			return m;
		} else if (target < array[m]) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	return -1;
}
