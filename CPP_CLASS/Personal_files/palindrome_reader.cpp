#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {

	string str;
	cout << "Enter a word: ";
	cin >> str;

	int len = str.length();
	bool isPalindrome = true;


	for (int i = 0; i < len / 2; i++) {
		if (tolower(str[i]) != tolower(str[len - 1 - i])) {
			isPalindrome = false;
			break;
		}
	}

	if (isPalindrome) {
		cout << "ȸ���Դϴ�." << endl;
	}
	else {
		cout << "ȸ���� �ƴմϴ�." << endl;
	}

	return 0;
}