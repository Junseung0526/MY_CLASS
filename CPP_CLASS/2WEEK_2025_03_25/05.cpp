#include <iostream>
using namespace std;

int main() {

	int num1;
	int num2;
	int num3;
	int num4;
	int sum;

	cout << "첫 번째 숫자를 입력해주세요: ";
	cin >> num1;

	cout << "두 번째 숫자를 입력해주세요: ";
	cin >> num2;

	cout << "세 번째 숫자를 입력해주세요: ";
	cin >> num3;

	cout << "네 번째 숫자를 입력해주세요: ";
	cin >> num4;

	sum = num1 + num2 + num3 + num4;

	cout << "모든 숫자의 합: " << sum << endl;


	return 0;
}