#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;

    if (num < 0) {
        num = -num;
    }

    if (num < 10) {
        cout << "Reverse Order: " << num << endl;
    }
    else if (num < 100) {
        cout << "Reverse Order: " << (num % 10) << (num / 10) << endl;
    }
    else {
        cout << "Reverse Order: " << (num % 10) << (num / 10 % 10) << (num / 100) << endl;
    }

    return 0;
}