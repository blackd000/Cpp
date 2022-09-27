#include <stdio.h>
#include <stdlib.h>

void testCountingSort();
void getData(int*, int*, int);
void countSort1(int*, int);
void countSort2(int*, int);
int maxValue(int*, int);
int minValue(int*, int);
void printArray(int*, int);

int main() {
	testCountingSort();

	return 0;
}

void testCountingSort() {
	int data[100];
	int n;

	while (1) {
		system("clear"); // system("cls") for windows
		printf("\t**********Input Data**********\n");
		printf("1) data = [ 1, 2, 1, 1 ]\n");
		printf("2) data = [ 5, 2, 7, 4, -2, 2 ]\n");
		printf("3) data = [ 5, 2, -5, 8, 7, -2, 2, 3, 3, 6, 2, 6, -1, 1, 2, 7, -2, 5, 2, 4, 9 ]\n");
		printf("4) data = [ 1, 10000, 200 ]\n");
		printf("0) Exit\n");
		printf("\t******************************\n");

		int input;
		printf("Xin lua chon: ");
		scanf("%d", &input);

		switch (input) {
		case 1:
		case 2:
		case 3:
		case 4:
			getData(data, &n, input);

			printArray(data, n);
			countSort2(data, n);
			printArray(data, n);

			break;
		case 0:
			return;
		default:
			printf("Nhap lai di!!\n");
		}

		printf("Press any key to continue...");
		getchar(); getchar(); // system("pause") for windows
	}
}

void getData(int* data, int* n, int number) {
	FILE* inputFile = NULL;
	if ((inputFile = fopen("testCountingSort.txt", "r")) == NULL) {
		printf("LOI INPUT FILE!!!!!\n");
		return;
	}

	int i = 1;
	while (i++ < number) {
		int j = 0, j2, buff;
		fscanf(inputFile, "%d", &buff);
		while (j < buff && fscanf(inputFile, "%d", &j2) != EOF) {
			j++;
		}
	}

	fscanf(inputFile, "%d", n);
	/* printf("%d\n", *n); */

	int i2 = 0, buff2;
	while (i2 < *n && fscanf(inputFile, "%d", &buff2) != EOF) {
		data[i2++] = buff2;
	}

	fclose(inputFile);
}

void countSort1(int* data, int n) {
	int max = maxValue(data, n), min = minValue(data, n);
	const int MAX = max - min + 1;
	int* countArray = (int*) (calloc(MAX, sizeof(int)));

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

	free(countArray);
}

void countSort2(int* data, int n) {
	int max = maxValue(data, n), min = minValue(data, n);
	const int MAX = max - min + 1;
	int* countArray = (int*) (calloc(MAX, sizeof(int)));

	// index = value - min
	for (int i = 0; i < n; i++) {
		countArray[data[i] - min]++;
	}

	// O(MAX)
	for (int i = 1; i < MAX; i++) {
		countArray[i] += countArray[i - 1];
	}

	int output[n]; 
	for (int i = n - 1; i >= 0; i--) {
		int positionInArray = countArray[data[i] - min] - 1;
		output[positionInArray] = data[i];
		countArray[data[i] - min]--;
	}

	for (int i = 0; i < n; i++) {
		data[i] = output[i];
	}

	free(countArray);
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
