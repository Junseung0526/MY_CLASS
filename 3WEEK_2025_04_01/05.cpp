#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;

    if (num < 0) {
        num = -num;
    }

    int firstDigit = num;
    while (firstDigit >= 10) {
        firstDigit /= 10;
    }

    int secondDigit = (num / 10) % 10;

    int thirdDigit = (num / 100) % 10;

    cout << "First digit: " << firstDigit << endl;

    if (num >= 10) {
        cout << "Second digit: " << secondDigit << endl;
    }
    else {
        cout << "There is no second digit." << endl;
    }

    if (num >= 100) {
        cout << "Third digit: " << thirdDigit << endl;
    }
    else {
        cout << "There is no third digit" << endl;
    }

    return 0;
}