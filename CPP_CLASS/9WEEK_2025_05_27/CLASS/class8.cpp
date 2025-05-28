#include <iostream>
#include <iomanip>
using namespace std;

void findStudentAverage(int const scores[][3], double stdAver[], int rowsize, int colsize) {
    for (int i = 0; i < rowsize; i++) {
        int sum = 0;
        for (int j = 0; j < colsize; j++) {
            sum += scores[i][j];
        }
        double average = static_cast<double>(sum) / colsize;
        stdAver[i] = average;
    }
}

void findTestAverage(int const scores[][3], double testAver[], int rowsize, int colsize) {
    for (int j = 0; j < colsize; j++) {
        int sum = 0;
        for (int i = 0; i < rowsize; i++) {
            sum += scores[i][j];
        }
        double average = static_cast<double>(sum) / rowsize;
        testAver[j] = average;
    }
}

int main() {

    const int rowsize = 5;
    const int colsize = 3;
    int scores[rowsize][colsize] = {
        {90, 80, 70},
        {85, 95, 75},
        {88, 76, 92},
        {100, 90, 80},
        {80, 93, 87}
    };

    double stdAver[rowsize];
    double testAver[colsize];

    findStudentAverage(scores, stdAver, rowsize, colsize);
    findTestAverage(scores, testAver, rowsize, colsize);

    cout << "Test scores and student averages" << endl;
    cout << "--------------------------------" << endl;

    for (int i = 0; i < rowsize; i++) {
        for (int j = 0; j < colsize; j++) {
            cout << setw(8) << scores[i][j];
        }
        cout << fixed << setprecision(2) << " | " << stdAver[i] << endl;
    }

    cout << "--------------------------------" << endl;
    cout << "Test averages: ";
    for (int j = 0; j < colsize; j++) {
        cout << fixed << setprecision(2) << testAver[j];
    }
    cout << endl;

    return 0;
}
