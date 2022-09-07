#include <stdio.h>
#include <math.h>

double tinhE(int x);
double giaiThua(int x);

int main() {
	int n, x;
	printf("Nhap x:\n");
	scanf("%d", &x);

	printf("Ket qua: %lf\n", tinhE(x));

	return 0;
}

double tinhE(int x) {
	double sum = 0;
	int i = 0;
	while (pow(x, i) / giaiThua(i) > 1e-10) {
		sum += pow(x, i) / giaiThua(i);
		i++;
	}

	return (sum);
}

double giaiThua(int x) {
	int sum = 1;
	for (int i = 2; i <= x; i++) {
		sum *= i;
	}

	return ((double) sum);
}
