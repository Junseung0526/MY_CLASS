#include <iostream>
using namespace std;

int getData() {
	int data;
	do {
		cout << "양의 정수를 입력하세요: ";
		cin >> data;
	} while (data <= 0);
	return data;
}

int main() {
	int number = getData();
	cout << "가장 오른쪽의 숫자 = " << number % 10;
	return 0;
}