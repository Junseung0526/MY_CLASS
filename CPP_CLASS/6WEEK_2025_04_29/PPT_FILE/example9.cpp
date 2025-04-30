#include <iostream>
using namespace std;

int input();
bool process(int year);
void output(int year, bool result);

int main() {

	int year = input();
	bool result = process(year);
	output(year, result);


	return 0;
}

int input() {

	int year;
	do {
		cout << "Enter a year after 1582: ";
		cin >> year;
	} while (year <= 1582);

	return year;
}


bool process(int year) {

	bool criterial1 = (year % 4 == 0);
	bool criterial2 = (year % 100 != 0) || (year % 400 == 0);

	return (criterial1) && (criterial2);
}


void output(int year, bool result) {

	if (result) {
		cout << "Year " << year << " is a leap year.";
	}
	else {
		cout << "Year " << year << " is not a leap year.";
	}

	return;
}