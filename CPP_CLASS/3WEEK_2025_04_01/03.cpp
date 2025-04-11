#include <iostream>
using namespace std;

int main() {

	float num1 = numeric_limits<float>::max();
	float num2 = numeric_limits<float>::min();

	cout << "Max value of float: " << num1 << endl;
	cout << "Min value of float: " << num2 << endl;

	double num3 = numeric_limits<double>::max();
	double num4 = numeric_limits<double>::min();

	cout << "Max value of double: " << num3 << endl;
	cout << "Min value of double: " << num4 << endl;

	return 0;
}