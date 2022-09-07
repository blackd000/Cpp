#ifndef CAR
#define CAR

class Car {
private:
	std::string name;
	int age;
public:
	Car(int a);
	double subtract(double a, double b);
	std::string info();
	~Car();
};

#endif // CAR
