#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

int main() {
	srand(time(0));

	int random_num = rand() % 101;
	int tries = 0;
	int num;


	while (true) {
		cout << "Enter the number: ";
		cin >> num;
		tries++;

		if (num == random_num) {
			cout << "That's correct! You guessed it in " << tries << " tries!" << endl;
			break;
		}
		else if (num > random_num) {
			cout << "Down!" << endl;
		}
		else if (num < random_num) {
			cout << "Up!" << endl;
		}
	}


	return 0;
}
