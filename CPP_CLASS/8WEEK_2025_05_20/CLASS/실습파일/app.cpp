#include "circle.h"

int main() {
	Circle Circle1(5.2);
	cout << "Radius: " << Circle1.getRadius() << endl;
	cout << "Area: " << Circle1.getArea() << endl;
	cout << "Parimeter: " << Circle1.getParimeter() << endl;

	Circle Circle2(Circle1);
	cout << "Radius: " << Circle1.getRadius() << endl;
	cout << "Area: " << Circle1.getArea() << endl;
	cout << "Parimeter: " << Circle1.getParimeter() << endl;

	Circle Circle3;
	cout << "Radius: " << Circle1.getRadius() << endl;
	cout << "Area: " << Circle1.getArea() << endl;
	cout << "Parimeter: " << Circle1.getParimeter() << endl;
}