#include <iostream>
using namespace std;


void pattern(int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; i++) {
			cout << "*";
		}
		cout << endl;
	}
}


int main() {

	int patternSize;

	do {
		cout << "패던의 크기를 입력하세요.";
		cin >> patternSize;
	} while (patternSize <= 0);

	pattern(patternSize);
	return 0;
}