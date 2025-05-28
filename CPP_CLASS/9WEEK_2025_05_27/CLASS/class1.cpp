#include <iostream>
using namespace std;

int main() {
	const int CAPACITY = 10;
	int numbers[CAPACITY];
	int size;

	do {
		cout << "Enter the size (1 and 10): ";
		cin >> size;
	} while (size < 1 || size > 10);

	cout << "Enter " << size << " integer(s): ";
	for (int i = 0; i < size; i++) {
		cin >> numbers[i];
	}

	cout << "Integer(s) in reversed order: ";
	for (int i = size - 1; i >= 0; i--) {
		cout << numbers[i] << " ";
	}

	return 0;
}
