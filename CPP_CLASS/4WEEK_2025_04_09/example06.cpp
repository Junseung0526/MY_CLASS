#include <iostream>
using namespace std;

int main() {

	int n_class;
	int price = 10;
	int total_price;

	cout << "Enter your number of class: ";
	cin >> n_class;

	if (n_class <= 12) {
		 total_price = n_class * price;

	}
	else {
		 total_price = n_class;
	}


	cout << "Your price: " << total_price << endl;

	return 0;
}