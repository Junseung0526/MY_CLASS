#include <iostream>
#include <cmath>
using namespace std;

int main() {

	char ch;
	int count = 0;

	while (cin >> noskipws >> ch) {

		if (isalpha(ch)) {
			count++;
		}

		ch = toupper(ch);
		cout << ch;
	}
	cout << "알파벳 문자의 개수 = " << count;
	return 0;
}