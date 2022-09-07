#include <iostream>
#include "includes/calculation.h"

using namespace std;

/* char *recommendFood(char firstLetter); */
const char *recommendFood(char firstLetter);

int main() {
	cout << "Today I want to eat " << recommendFood('a') << endl;
	cout << add(100, 32) << endl;

	return 0;
}

const char *recommendFood(char firstLetter) {
	if (firstLetter = 'a') {
		return "Banana";
	} else {
		return "Buka";
	}
}
