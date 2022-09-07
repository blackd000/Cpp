#include <iostream>

#include "Car.h"
#include "Engine.h"

int main() {
	Car car(3);

	std::cout << car.subtract(9, 8);

	return 0;
}
