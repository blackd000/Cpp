#include <stdio.h>

long long giaiThua(int i) {
	if (i == 1 || i == 0) {
		return 1;
	}

	return (giaiThua(i - 1) * i);
}

long long giaiThua1(int i) {
	int sum = 1;
	for (int a = 2; a <= i; a++) {
		sum *= a;
	}

	return (sum);
}

long long toHop(int n, int k) {
	/* return (giaiThua(n) / (giaiThua(n - k) * giaiThua(k))); */
	return (giaiThua1(n) / (giaiThua1(n - k) * giaiThua1(k)));
}

int main() {

	printf("Ket qua: %lld", toHop(5, 2));

	return 0;
}
