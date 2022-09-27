#include <stdio.h>
#include <stdlib.h>

void testRadixSort();
void getData(int*, int*, int);
void sort(int*, int);
void radixSort(int*, int);
void countingSort(int*, int, int);
int maxValue(int*, int);
void printArray(int*, int);

int main() {
	testRadixSort();

	return 0;
}

void testRadixSort() {
	int data[100];
	int n;

	while (true) {
		system("clear"); // system("cls") for windows
		printf("\t**********Input Data**********\n");
		printf("1) data = [ 369, 512, 711, 982, 147, 565, 911, 769 ]\n");
		printf("2) data = [ 77, 100, 99 ]\n");
		printf("3) data = [ 1012, -5221, 921, 2212, -3234, 4753, 3417, 1532, 1020 ]\n");
		printf("4) data = [ 5, 2891, 78, 4, 2, 2 ]\n");
		printf("5) data = [ -1012, -5221, -921, -2212, -3234, -4753, -3417, -1532, -1020 ]\n");
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
		case 5:
			getData(data, &n, input);

			printArray(data, n);
			sort(data, n);
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
	if ((inputFile = fopen("testRadixSort.txt", "r")) == NULL) {
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
