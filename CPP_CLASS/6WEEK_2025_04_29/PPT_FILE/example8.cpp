#include <iostream>
using namespace std;

int larger(int fst, int scd) {
	int max;
	if (fst > scd) {
		max = fst;
	}
	else {
		max = scd;
	}

	return max;
}

int main() {

	int first, second;
	cout << "ù ��° ���ڸ� �Է��ϼ���.: ";
	cin >> first;

	cout << "�� ��° ���ڸ� �Է��ϼ���.: ";
	cin >> second;

	cout << "�� �� �߿� ū �� = " << larger(first, second);
	return 0;
}