#include <stdio.h>

long C(int n, int k) {
	if (k == 0 || k == n) {
		return 1;
	} else if (k > 0 || k < n) {
		return (C(n - 1, k) + C(n - 1, k - 1));
	}
}

int main() {

	printf("Ket qua: %ld", C(5, 2));

	return 0;
}
