#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int *a = (int*) malloc(50 * sizeof(int));

	a[0] = 2;
	a[1] = 3;

	for (int i = 0; i < 2; i++) {
		printf("%d ", a[i]);
	}

	free(a);
	return 0;
}
