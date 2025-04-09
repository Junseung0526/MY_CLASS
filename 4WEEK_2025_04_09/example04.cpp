#include <iostream>
#include <string>
using namespace std;

int main() {
	string price;
	cout << "Enter your car type: ";
	cin >> price;

	if (price == "c") {
		cout << "2$" << endl;
	}
	else if (price == "b") {
		cout << "3$" << endl;
	}
	else if (price == "t") {
		cout << "3$" << endl;
	}
	else {
		cout << "Unknown type!" << endl;
	}

	return 0;
}