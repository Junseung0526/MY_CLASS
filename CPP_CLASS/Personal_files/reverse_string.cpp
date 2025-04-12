#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	cout << "Enter the string: ";
	cin >> str;

	int length = str.length();
	string reversed = "";

	for (int i = length - 1; i >= 0; i--) {
		reversed += str[i];
	}

	cout << reversed << endl;



	return 0;
}