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
		cout << "회문입니다." << endl;
	}
	else {
		cout << "회문이 아닙니다." << endl;
	}

	return 0;
}