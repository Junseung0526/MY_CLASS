#include <iostream>
using namespace std;

int getData() {
	int data;
	do {
		cout << "���� ������ �Է��ϼ���: ";
		cin >> data;
	} while (data <= 0);
	return data;
}

int main() {
	int number = getData();
	cout << "���� �������� ���� = " << number % 10;
	return 0;
}