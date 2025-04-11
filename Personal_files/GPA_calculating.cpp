#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	int mid, final, homework, att;
	double total;
	string grade;

	cout << "Enter midterm score : ";
	cin >> mid;
	if (mid < 0 || mid > 100) {
		cout << "잘못된 입력입니다." << endl;
		return 0;
	}
	else {
		cout << "Enter final score : ";
		cin >> final;

		if (final < 0 || final > 100) {
			cout << "잘못된 입력입니다." << endl;
			return 0;
		}
		else {
			cout << "Enter homework score : ";
			cin >> homework;
			if (homework < 0 || homework > 100) {
				cout << "잘못된 입력입니다." << endl;
				return 0;
			}
			else {
				cout << "Enter attendance score : ";
				cin >> att;

				if (att < 0 || att > 10) {
					cout << "잘못된 입력입니다." << endl;
					return 0;
				}

			}

		}

	}


	total = (mid * 0.3) + (final * 0.3) + (homework * 0.3) + (att * 0.1);

	if (total >= 95) {
		grade = "A+";
	}
	else if (total >= 90) {
		grade = "A";
	}
	else if (total >= 80) {
		grade = "B";
	}
	else if (total >= 70) {
		grade = "C";
	}
	else if (total >= 60) {
		grade = "D";
	}
	else {
		grade = "F";
	}


	cout << "Total score: " << total << endl;
	cout << "Grade: " << grade << endl;

	if (total >= 95 && att == 10) {
		cout << "장학생입니다!" << endl;
	}



	return 0;
}
