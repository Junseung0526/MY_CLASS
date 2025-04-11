#include <iostream>
using namespace std;

int main() {
	
    int num;
    cout << "Enter the number: ";
    cin >> num;

    if (num < 0) {
        num = -num;
    }d

    if (num < 10) {
        cout << "There is no second digit." << endl;
    }
    else {
        int secondDigit = (num / 10) % 10;
        cout << "Second digit: " << secondDigit << endl;
    }

	return 0;
}