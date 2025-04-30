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
	cout << "첫 번째 숫자를 입력하세요.: ";
	cin >> first;

	cout << "두 번째 숫자를 입력하세요.: ";
	cin >> second;

	cout << "두 수 중에 큰 것 = " << larger(first, second);
	return 0;
}