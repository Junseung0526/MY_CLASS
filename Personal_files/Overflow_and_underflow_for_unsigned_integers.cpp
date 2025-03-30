#include <iostream>
#include <limits>
using namespace std;

int main() {

	unsigned int num1 = numeric_limits <unsigned int>::max();
	unsigned int num2 = numeric_limits <unsigned int>::min();
	
	cout << "The value of maximum unsigned int: " << num1 << endl;
	cout << "The value of minimum unsigned int: " << num2 << endl;

	num1 += 1;
	num2 -= 1;

	cout << "The value of num1 + 1 after overflow: " << num1 << endl;
	cout << "The value of num2 - 1 after overflow: " << num2 << endl;

	cout << "\n" << endl;

	int num3 = numeric_limits <int> ::max();
	int num4 = numeric_limits <int> ::min();

	cout << "Value of maximum signed int:" << num3 << endl;
	cout << "Value of minimum signed int:" << num4 << endl;

	num3 += 1;
	num4 -= 1;

	cout << "The value of num3 + 1 after overflow" << num3 << endl;
	cout << "The value of num4 - 1 after overflow" << num4 << endl;

	return 0;
}