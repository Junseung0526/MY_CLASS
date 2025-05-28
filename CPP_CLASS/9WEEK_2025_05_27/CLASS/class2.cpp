#include <iostream>
using namespace std;

int main() {

	int numberDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	int month;
	do {
		cout << "Enter the month number (1 to 12): ";
		cin >> month;
	} while (month < 1 || month>12);
	cout << "There are " << numberDay[month];
	cout << " days in this month";
	return 0;
}