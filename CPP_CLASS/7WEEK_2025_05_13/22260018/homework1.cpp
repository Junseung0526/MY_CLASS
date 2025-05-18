#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class One {
private:
	int x, y;
public:
	One(int x, int y) : x(x), y(y) {}
	int getX() { return x; }
	int getY() { return y; }
};

int main() {
	One one(10, 20);
	cout << "One x: " << one.getX() << ", y: " << one.getY() << endl;

	return 0;
}