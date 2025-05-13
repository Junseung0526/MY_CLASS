#include <iostream>
using namespace std;

int global;

int main() {

	static int sLocal;
	auto int aLocal;
	cout << "Global = " << global << endl;
	cout << "Static Local = " << sLocal << endl;
	cout << "Automatic Local = " << aLocal << endl;

	return 0;
}