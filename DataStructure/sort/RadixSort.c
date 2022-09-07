#include <stdio.h>

void sort(int*, int);
void radixSort(int*, int);
void countingSort(int*, int, int);
int maxValue(int*, int);
void printArray(int*, int);

int main() {
	/* int data[] = { 5, 2891, 78, 4, 2, 2 }; // n = 6 */
	int data[] = { 77, 100, 99 }; // n = 3
	/* int data[] = { 1012, -5221, 921, 2212, -3234, 4753, 3417, 1532, 1020 }; // n = 9 */
	/* int data[] = { -1012, -5221, -921, -2212, -3234, -4753, -3417, -1532, -1020 }; // n = 9 */

	int n = 3;

	printArray(data, n);
	sort(data, n);
	printArray(data, n);

	return 0;
}

void sort(int* data, int n) {
	int negativeData[n], positiveData[n];
	int index1 = 0, index2 = 0;

	for (int i = 0; i < n; i++) {
		if (data[i] < 0) {
			negativeData[index1++] = -data[i];
		} else {
			positiveData[index2++] = data[i];
		}
	}

	if (index1 > 0) {
		radixSort(negativeData, index1);
		for (int i = index1 - 1, j = 0; i >= 0; i--, j++) {
			data[j] = -negativeData[i];
		}
	}

	if (index2 > 0) {
		radixSort(positiveData, index2);
		for (int i = index1, j = 0; i < n; i++, j++) {
			data[i] = positiveData[j];
		}
	}
}

void radixSort(int* data, int n) {
	int max = maxValue(data, n);
	for (int exp = 1; max/exp != 0; exp *= 10) {
		countingSort(data, n, exp);
	}
}

void countingSort(int* data, int n, int exp) {
	const int MAX = 10;
	int countArray[MAX] = { 0 };

	// index = value - min
	for (int i = 0; i < n; i++) {
		countArray[(data[i] / exp) % 10]++;
	}

	for (int i = 1; i < MAX; i++) {
		countArray[i] += countArray[i - 1];
	}

	int output[n]; // luu tru stored values
	for (int i = n - 1; i >= 0; i--) {
		int positionInArray = countArray[(data[i] / exp) % 10] - 1;
		output[positionInArray] = data[i];
		countArray[(data[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++) {
		data[i] = output[i];
	}
}

int maxValue(int* data, int n) {
	int max = data[0];
	for (int i = 1; i < n; i++) {
		if (data[i] > max) {
			max = data[i];
		}
	}
	return max;
}

void printArray(int* data, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	printf("\n\n");
}
