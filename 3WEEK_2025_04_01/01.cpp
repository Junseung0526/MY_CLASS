#include <iostream>
using namespace std;

int main() {

	short num1 = numeric_limits<short>::max();
	short num2 = numeric_limits<short>::min();

	cout << "Max value of short: " << num1 << endl;
	cout << "Min value of short: " << num2 << endl;

	unsigned int num3 = numeric_limits<unsigned int>::max();
	unsigned int num4 = numeric_limits<unsigned int>::min();

	cout << "Max value of unsigned int: " << num3 << endl;
	cout << "Min value of unsigned int: " << num4 << endl;

	return 0;
}