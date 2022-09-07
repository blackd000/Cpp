#include <iostream>
#include <string>

#include "Car.h"

Car::Car(int a) {
	std::cout << "This is car " << a << std::endl;
}

double Car::subtract(double a, double b) {
	return (a - b);
}

std::string Car::info() {
	return ("Hava");
}

Car::~Car() {

}
