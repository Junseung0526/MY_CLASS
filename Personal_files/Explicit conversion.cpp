#include <iostream>
using namespace std;

int main()
{
	// Declaration
	double x = 23.56;
	int y = 30;
	// Allowing implicit conversion 
	cout << "Without casting:" << x + y << endl;
	// Forcing explicit conversion 
	cout << "With casting:" << static_cast <int> (x) + y;
	return 0;

}