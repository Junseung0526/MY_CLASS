#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));

	for (int i = 0; i < 5; ++i) {
		cout << "¼¼Æ® " << i + 1 << ": ";
		for (int j = 0; j < 10; ++j) {
			int num = rand() % 90 + 10;
			cout << num << " ";
		}
		cout << "/n";
	}

	return 0;
}
