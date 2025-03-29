#include <iostream>
using namespace std;

int main() {

	//Declarations
	bool x = true;
	char y = 'A';
	short z = 14;
	float t = 24.5;
	//Type conversion from bool to int
	cout << "Implicit promotion of data types" << endl;
	cout << "-----------------------------------------" << endl;


	cout << "Type of x + 100: " << typeid(x + 100).name() << endl;
	cout << "Valuie of x + 100: " << x + 100 << endl;
	//Type conversion from char to int
	cout << "Type of y + 1000: " << typeid(y + 1000).name() << endl;
	cout << "Value of y + 1000" << y + 1000 << endl;
	//Type of converison from short to int
	cout << "Type of z * 100: " << typeid(z * 100).name() << endl;
	cout << "Value of z * 100: " << z * 100 << endl;
	//Type of conversion from float to double
	cout << "Type of t + 15000.2: " << typeid(t +15000.2).name() << endl;
	cout << "Value of t + 15000,2: " << t + 15000.2 << endl;
	cout << "-----------------------------------------" << endl;


	cout << "\n" << endl;
	cout << "Implicit type conversion (no side effect)" << endl;
	cout << "-----------------------------------------" << endl;

	int x2 = 123;
	long y2 = 140;
	double z2 = 114.56;


	cout << "Type of x2 + y2: " << typeid(x2 + y2).name() << endl;
	cout << "Value of x2 + y2: " << x2 + y2 << endl;
	cout << "Type of x2 + y + z2: " << typeid(x2 + y2 + z2).name() << endl;
	cout << "Value of x2 + y2 + z2: " << x2 + y2 + z2 << endl;
	cout << "-----------------------------------------" << endl;

	cout << "\n" << endl;
	cout << "Implicit type conversion (with side effect)" << endl;
	cout << "-----------------------------------------" << endl;

	int x3;
	double y3;

	x3 = 23.67;
	y3 = 130;
	
	cout << "Type of x= 23.67: " << typeid(x = 23.67).name() << endl;
	cout << "Value of x after assignment: " << x << endl << endl;

	cout << "Type of y = 130:" << typeid (y = 130).name() << endl;
	cout << "Value of y after assignment:" << y << endl;


	cout << "-----------------------------------------" << endl;
	return 0;
}