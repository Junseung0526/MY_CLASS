#include <iostream>
using namespace std;

int main() {

	int score1, score2, score3;
	cout << "Enter your score (3): ";
	cin >> score1 >> score2 >> score3;

	int avg_score = (score1 + score2 + score3) / 3;

	if (avg_score >= 90) {
		cout << "A" << endl;
		cout << "Your AVG: " << avg_score << endl;
	}
	else if (avg_score >= 80) {
		cout << "B" << endl;
		cout << "Your AVG: " << avg_score << endl;
	}
	else if (avg_score >= 70) {
		cout << "C" << endl;
		cout << "Your AVG: " << avg_score << endl;
	}
	else if (avg_score >= 60) {
		cout << "D" << endl;
		cout << "Your AVG: " << avg_score << endl;
	}
	else {
		cout << "F" << endl;
		cout << "Your AVG: " << avg_score << endl;
	}
	
	return 0;
}