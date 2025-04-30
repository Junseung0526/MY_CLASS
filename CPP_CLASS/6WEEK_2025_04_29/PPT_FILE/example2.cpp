#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int a, b, c;
	double term;

	cout << "Enter the value of confficient a: ";
	cin >> a;

	cout << "Enter the value of confficient b: ";
	cin >> b;

	cout << "Enter the value of confficient c: ";
	cin >> c;



	term = pow(b, 2) - 4 * a * c;
	if (term < 0) {
		cout << "There is no root!" << endl;
	}
	else if (term == 0) {
		cout << "The two roots are equal." << endl;
		cout << "x1 = x2 = " << -b / (2 * a) << endl;
	}
	else {
		cout << "There are two distinct roots: " << endl;
		cout << "x1 = " << (-b + sqrt(term) / (2 * a)) << endl;
		cout << "x2 = " << (-b - sqrt(term) / (2 * a)) << endl;
	}

	return 0;
}