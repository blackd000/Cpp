#include <iostream>

using std::cout;
using std::endl;

// - Algorithm:
// Similer to Binary Search exept for how "data point" is choosed
// CT: pos = low + (((target - arr[low]) * (high - low)) / (arr[high] - arr[low]))
int interpolationSearch(int arr[], int n, int target);

int main() {
	int array[] = { 1, 2, 5, 8, 18, 12, 19 }; // n = 7
	int n = 7;

	cout << interpolationSearch(array, n, 8);

	cout << endl;
	return 0;
}

int interpolationSearch(int arr[], int n, int target) {
	int low = 0, high = n - 1;

	while (low <= high) {
		int pos = low + (((target - arr[low]) * (high - low)) / (arr[high] - arr[low]));

		if (target == arr[pos]) {
			return pos;
		} else if (target < arr[pos]) {
			high = pos - 1;
		} else {
			low = pos + 1;
		}
	}

	return -1;
}
