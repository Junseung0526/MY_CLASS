#include <iostream>
using namespace std;

void fun(int& y);

int main() {

	int x = 10;
	fun(x);
	cout << "Value of x in main: " << x << endl;
	return 0;
}

void fun(int& y) {
	y++;
	cout << "Value of y in fun: " << y << endl;
	return;
}