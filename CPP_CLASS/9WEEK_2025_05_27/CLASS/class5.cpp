#include <iostream>
using namespace std;

void multiplyByTwo(int numbers[], int size) {
	for (int i = 0; i < size; i++) {
		numbers[i] *= 2;
	}
	return;
}

void print(const int numbers[], int size) {
	for (int i = 0; i < size; i++) {
		cout << numbers[i] << " ";
	}
	return;
}

int main() {

	int numbers[5] = { 150,170,190,110,130 };
	print(numbers, 5);
	multiplyByTwo(numbers, 5);
	print(numbers, 5);

	return 0;
}