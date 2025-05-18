#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	void print() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
	void setXY(int newX, int newY) {
		x = newX;
		y = newY;
	}
	double getDistance(const Point& other) {
		return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
	}
};

int main() {
	Point p1(3, 4), p2(0, 0);
	p1.print();
	p2.print();
	cout << "Distance: " << p1.getDistance(p2) << endl;

	return 0;
}