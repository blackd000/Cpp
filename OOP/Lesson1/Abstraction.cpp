#include <iostream>
/* #include <vector> */

using namespace std;

class SmartPhone {
public:
	virtual void takeSelfie() = 0;
	virtual void recordVideo() = 0;
	virtual void makeCall() = 0;
};

class Android:public SmartPhone {
public:
	void takeSelfie() {
		cout << "Android Take selfie bitch\n";
	}

	void recordVideo() {
		cout << "Android I am recording my video\n";
	}

	void makeCall() {
		cout << "Android is calling\n";
	}
};

class IPhone:public SmartPhone {
public:
	void takeSelfie() {
		cout << "IPhone selfie bitch\n";
	}

	void recordVideo() {
		cout << "IPhone record video\n";
	}

	void makeCall() {
		cout << "IPhone is calling\n";
	}
};

int main() {
	SmartPhone *phone[3];
	
	phone[0] = new Android();
	phone[0]->takeSelfie();
	phone[0]->recordVideo();
	phone[0]->makeCall();

	cout << endl;

	phone[1] = new IPhone();
	phone[1]->takeSelfie();
	phone[1]->recordVideo();
	phone[1]->makeCall();

	return 0;
}
