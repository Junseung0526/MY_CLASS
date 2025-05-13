#include <iostream>
#include <ctime>
#include <cstdlib>  
using namespace std;

class RandomInteger {
private:
	int low;
	int high;
	int value;

public:
	RandomInteger(int low, int high);
	~RandomInteger();
	RandomInteger(const RandomInteger& random) = delete;

	void print() const;
};


RandomInteger::RandomInteger(int lw, int hh)
	: low(lw), high(hh) {
	srand(time(0));
	value = rand() % (high - low + 1) + low;

}


RandomInteger::~RandomInteger() {

}


void RandomInteger::print() const {
	cout << value << endl;
}


int main() {
	RandomInteger r(100, 200);
	cout << "Random number between 100 and 200" << endl;
	r.print();

	RandomInteger r2(400, 600);
	cout << "Random number between 400 and 600" << endl;
	r2.print();

	RandomInteger r3(1500, 2000);
	cout << "Random number between 1500 and 2000" << endl;
	r3.print();

	return 0;
}
