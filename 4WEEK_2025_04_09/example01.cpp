#include <iostream>
using namespace std;

int main() {

    int number;
    cout << "Enter the number: ";
    cin >> number;

    int firstnum = number / 10;

    int secondnum = (number % 10) * 10;

    cout << firstnum + secondnum << endl;
    return 0;
}