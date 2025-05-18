#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Two {
private:
	int x;
	char data;
public:
	Two(int x, char data) : x(x), data(data) {}
	int getX() { return x; }
	char getData() { return data; }
	void setX(int newX) { x = newX; }
	void setData(char newData) { data = newData; }
};

int main() {
	Two two(5, 'A');
	cout << "Two x: " << two.getX() << ", data: " << two.getData() << endl;
	two.setX(8);
	two.setData('B');
	cout << "Two updated x: " << two.getX() << ", data: " << two.getData() << endl;

	return 0;
}