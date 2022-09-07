#include <iostream>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;

class Person {
protected:
	string name;
	int age;
	list<string> friends;

public:
	Person(string name, int age, list<string> friends) {
		this->name = name;
		this->age = age;
		this->friends = friends;
	}

	string getName() {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	int getAge() {
		return age;
	}

	void setAge(int age) {
		if (age >= 0 && age < 250) {
			this->age = age;
		}
	}

	virtual void practice() = 0; // pure virtual function == public abstract method --> abstract class

	void sayHello() {
		cout << "Hello mr." << name << " you are " << age << endl;
		cout << "This is your friends: ";

		for (string f : friends) {
			cout << f << " ";
		}

		cout << endl;
	}

	void addFriends(list<string> moreFriends) {
		for (string moreFriend : moreFriends) {
			friends.push_back(moreFriend);
		}
	}
}; // phai co cham phay

class Student:public Person {
private:
	string university;
	int score;
public:
	Student(string name, int age, list<string> friends, string university, int score):Person(name, age, friends) {
		this->university = university;
		this->score = score;
	}

	string getUniversity() {
		return university;
	}

	void setUniversity(string university) {
		this->university = university;
	}

	void practice() {
		cout << "Student writes some things on " << name << "'s notebook\n";
		score++;
	}
};

class Worker:public Person {
private:
	int salary;
public:
	Worker(string name, int age, list<string> friends, int salary):Person(name, age, friends) {
		this->salary = salary;
	}

	void practice() {
		cout << "Worker name " << name << " works their ass off to make money\n";
		salary++;
	}
};

int main() {
	/* // create person */
	/* Person person1("Dong", 19, {"Tay", "Nam", "Bac"}); */
	/* person1.sayHello(); */
	/* person1.addFriends({"Diep", "Giap"}); */
	/* person1.sayHello(); */

	/* // create Student inherits from Person */
	Student student1("Tay", 21, {"Bakan", "Suka"}, "KMA", 25);
	/* student1.sayHello(); */
	/* student1.practice(); */

	/* 
	 * class have atleast 1 pure virtual function is abstract classes
	 * - and abstract classes can not make an instance
	 * */

	// polymorphism
	Person *a = new Student("Bac", 12, {"Kulan", "Yasuo", "Mankeep"}, "OOX", 29);
	Person *b = &student1;

	/* a->sayHello(); */
	/* a->practice(); */
	/* cout << endl; */
	/* b->sayHello(); */

	// more polymorphism
	Person *person[5] = { a, b };
	person[2] = new Student("Hana", 19, {"Ba", "Hai"}, "XXo", 99);

	for (int i = 0; i < 3; i++) {
		person[i]->sayHello();
		cout << endl;
	}

	return 0;
}
