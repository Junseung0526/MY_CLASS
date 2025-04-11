#include <iostream>
using namespace std;

int main() {

	long num1 = numeric_limits<long>::max();
	long num2 = numeric_limits<long>::min();

	cout << "Max value of long: " << num1 << endl;
	cout << "Min value of long" << num2 << endl;

	long long num3 = numeric_limits<long long>::max();
	long long num4 = numeric_limits<long long>::min();

	cout << "Max value of long long: " << num3 << endl;
	cout << "Min value of long long: " << num4 << endl;

	return 0;
}