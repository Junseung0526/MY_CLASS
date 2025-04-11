#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 100;

bool isValidScore(int score, int max);
string grade_calculate(double total);
void printResult(int n, double totals[], string grades[], bool isScholar[]);

int main() {
	int n;
	cout << "학생 수를 입력하세요: ";
	cin >> n;

	// [0]: mid, [1]: final, [2]: hw, [3]: att
	int scores[MAX][4];
	double totals[MAX];
	string grades[MAX];
	bool isScholar[MAX];

	for (int i = 0; i < n; i++) {
		cout << "\n▶ " << i + 1 << "번 학생 점수 입력" << endl;


		for (int j = 0; j < 4; j++) {
			string label = (j == 0 ? "중간고사" : j == 1 ? "기말고사" : j == 2 ? "과제" : "출석");
			int maxScore = (j == 3 ? 10 : 100);

			cout << label << " 점수: ";
			cin >> scores[i][j];

			if (!isValidScore(scores[i][j], maxScore)) return 0;
		}


		totals[i] = scores[i][0] * 0.3 + scores[i][1] * 0.3 + scores[i][2] * 0.3 + scores[i][3] * 0.1;


		grades[i] = grade_calculate(totals[i]);
		isScholar[i] = (totals[i] >= 95 && scores[i][3] == 10);
	}


	printResult(n, totals, grades, isScholar);

	return 0;
}


bool isValidScore(int score, int max) {
	if (score < 0 || score > max) {
		cout << "잘못된 입력입니다." << endl;
		return false;
	}
	return true;
}


string grade_calculate(double total) {
	if (total >= 95) return "A+";
	else if (total >= 90) return "A";
	else if (total >= 80) return "B";
	else if (total >= 70) return "C";
	else if (total >= 60) return "D";
	else return "F";
}


void printResult(int n, double totals[], string grades[], bool isScholar[]) {
	cout << fixed << setprecision(1);
	cout << "\n\n====== 성적 결과표 ======" << endl;
	cout << "No.  Total   Grade   Scholarship" << endl;
	cout << "-------------------------------" << endl;

	for (int i = 0; i < n; i++) {
		cout << setw(2) << i + 1 << "   "
			<< setw(6) << totals[i] << "   "
			<< setw(5) << grades[i] << "   "
			<< (isScholar[i] ? "Yes" : "-") << endl;
	}
}