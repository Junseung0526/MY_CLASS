#include <iostream>
using namespace std;

double clacExarnings(double rate, double hours = 40);

int main() {

	cout << "Employee 1 pay: " << clacExarnings(22.0) << endl;
	cout << "Employee 2 pay: " << clacExarnings(12.50,18) << endl;

	return 0;
}

double clacExarnings(double rate, double hours) {
	double pay;
	pay = hours * rate;
	return pay;
}
