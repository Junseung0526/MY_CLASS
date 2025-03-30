#include <iostream>
#include <limits>
using namespace std;

int main() {

	double num1 = +numeric_limits <double> ::max();
	double num2 = -numeric_limits <double> ::max();

	cout << "The value of maximum double:" << num1 << endl;
	cout << "The value of minimum double:" << num2 << endl;

	num1 *= 1000.00;
	num2 *= 1000.00;
	
	cout << "The value of num2 * 1000 after underflow:" << num2 << endl;

	return 0;
}