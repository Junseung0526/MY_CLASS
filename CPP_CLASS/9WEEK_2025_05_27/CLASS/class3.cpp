#include <iostream>
#include "circle.h"
using namespace std;


int main() {

	Circle circles[3];
	circles[0] = Circle(3.0);
	circles[1] = Circle(4.0);
	circles[2] = Circle(5.0);

	for (int i = 0; i < 3; i++) {
		cout << "Information about circle [ " << i << " ]" << endl;
		cout << "Radius: " << circles[i].getRadius() << " ";
		cout << "Area: " << circles[i].getArea() << " ";
		cout << "Perimter: " << circles[i].getPerimter() << " ";
	}

	return 0;
}