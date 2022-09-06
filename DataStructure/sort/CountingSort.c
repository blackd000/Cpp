#include <stdio.h>
#include <string.h>

#define RANGE 1001

void countSort1(int*, int);
void countSort2(int*, int);
int maxValue(int*, int);
int minValue(int*, int);
void printArray(int*, int);

int main() {
	/* int data[] = { 1, 2, 1, 1 }; // n = 4 */
	/* int data[] = { 5, 2, 7, 4, -2, 2 }; // n = 6 */
	int data[] = { 5, 2, -5, 8, 7, -2, 2, 3, 3, 6, 2, 6, -1, 1, 2, 7, -2, 5, 2, 4, 9 }; // n = 21
	/* int data[] = { 1, 10000, 200 }; // n = 3 */
	int n = 21;

	printArray(data, n);
	countSort2(data, n);
	printArray(data, n);

	return 0;
}

void countSort1(int* data, int n) {
	int max = maxValue(data, n), min = minValue(data, n);
	const int MAX = max - min + 1;
	int countArray[MAX] = { 0 };

	// index = value - min
	for (int i = 0; i < n; i++) {
		countArray[data[i] - min]++;
	}

	int arrayIndex = 0;
	// O(MAX)
	for (int i = 0; i < MAX; i++) { // giam dan ==> for (int i = MAX; i >= 0; i--)
		while (countArray[i] > 0) {
			data[arrayIndex++] = i + min;
			countArray[i]--;
		}
	}
}

void countSort2(int* data, int n) {
	int max = maxValue(data, n), min = minValue(data, n);
	const int MAX = max - min + 1;
	int countArray[MAX] = { 0 };

	// index = value - min
	for (int i = 0; i < n; i++) {
		countArray[data[i] - min]++;
	}

	// O(MAX)
	for (int i = 1; i < MAX; i++) {
		countArray[i] += countArray[i - 1];
	}

	int output[n]; // luu tru stored values
	for (int i = n - 1; i >= 0; i--) {
		int positionInArray = countArray[data[i] - min] - 1;
		output[positionInArray] = data[i];
		countArray[data[i] - min]--;
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

int minValue(int *data, int n) {
	int min = data[0];
	for (int i = 1; i < n; i++) {
		if (data[i] < min) {
			min = data[i];
		}
	}
	return min;
}

void printArray(int* data, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	printf("\n\n");
}
