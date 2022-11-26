#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

void thapPhanThanhNhiPhan(int number);

int main() {
	thapPhanThanhNhiPhan(339);

	cout << endl;
	return 0;
}

void thapPhanThanhNhiPhan(int number) {
	stack<int> S;

	while (number > 0) {
		S.push(number % 2);
		number /= 2;
	}

	while (!S.empty()) {
		cout << S.top();
		S.pop();
	}
}
