#include "LengthConnectedCells.h"

int getMaxOnes(int arr[][5], int rMax, int cMax) {
	int maxSize = 0;
	int size = 0;

	int **countArr;
	countArr = (int **) malloc(rMax * sizeof(int *));
	for (int i = 0; i < rMax; i++) {
		countArr[i] = (int *) calloc(cMax, sizeof(int));
	}

	/* for (int i = 0; i < rMax; i++) { */
	/* 	for (int j = 0; j < cMax; j++) { */
	/* 		printf("%d ", countArr[i][j]); */
	/* 	} */
	/* 	printf("\n"); */
	/* } */

	for (int i = 0; i < rMax; i++) {
		for (int j = 0; j < cMax; j++) {
			if (arr[i][j] == 1) {
				findMaxBlock(arr, i, j, rMax, cMax, size, countArr, &maxSize);
			}
		}
	}

	return maxSize;
}

void findMaxBlock(int arr[][5], int row, int column, int rMax, int cMax, int size, int **countArr, int *maxSize) {
	if (row > rMax || column > cMax)  {
		return;
	}

	countArr[row][column] = 1;
	size++;

	if (size > *maxSize) {
		*maxSize = size;
	}

	int direction[][2] = {
		{ -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 },
		{ 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }
	};

	for (int i = 0; i < 8; i++) {
		int newRow = row + direction[i][0];
		int newColumn = column + direction[i][1];

		int value = getVal(arr, newRow, newColumn, rMax, cMax);

		if (value > 0 && !countArr[newRow][newColumn]) {
			findMaxBlock(arr, newRow, newColumn, rMax, cMax, size, countArr, maxSize);
		}
	}

	countArr[row][column] = 0;
}

int getVal(int arr[][5], int i, int j, int l, int h) {
	if (i < 0 || i >= l || j < 0 || j >= h) {
		return 0;
	} else {
		return arr[i][j];
	}
}

void printArray(int arr[][5], int rMax, int cMax) {
	for (int i = 0; i < rMax; i++) {
		for (int j = 0; j < rMax; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
