#include <iostream>
#include <string>

using namespace std;

/*
 * remember:**
 * - struct -> members are public by default
 * - class 	-> private are private by default
 * */

// // use struct
/* struct YoutubeChannel { */
/* 	string name; */
/* 	int subCount; */

/* 	YoutubeChannel(string name, int subCount) { */
/* 		this->name = name; */
/* 		this->subCount = subCount; */
/* 	} */
/* }; */

class YoutubeChannel {
public:
	string name;
	int subCount;

	YoutubeChannel(string name, int subCount) {
		this->name = name;
		this->subCount = subCount;
	}
};

// overloading operator
ostream &operator<<(ostream &Cout, YoutubeChannel &ytChannel) {
	Cout << "Name: " << ytChannel.name << endl;
	Cout << "Subscribers: " << ytChannel.subCount << endl;

	return Cout;
}

int main() {
	YoutubeChannel yt1("Hava", 0);
	YoutubeChannel yt2("My channel", 19999);

	cout << yt1.name << " " << yt1.subCount << endl << endl;

	cout << yt1 << yt2;

	return 0;
}
