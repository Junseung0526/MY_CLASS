#include <iostream>
using namespace std;

int num = 5;

int main() {

	int num = 25;
	cout << "Value of Global num: " << ::num << endl;
	cout << "Value of Local num: " << num << endl;

	return 0;
}