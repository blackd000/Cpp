#include <stdio.h>
#include "LengthConnectedCells.h"

int main() {
	int arr[][5] = {
		{ 1, 1, 0, 0, 0 },
		{ 0, 1, 1, 0, 0 },
		{ 0, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 1, 0, 1, 1 }
	};

	/* printf("%d", getVal(arr, 1, 2, 5, 5)); */
	/* printf("\n"); */
	/* getMaxOnes(arr, 5, 5); */

	printArray(arr, 5, 5);
	printf("\nNumber of maximum 1s are %d\n", getMaxOnes(arr, 5, 5));
	
	return 0;
}
