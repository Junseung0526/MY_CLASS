#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int arr[6][6] = {0};

    // 0~5까지는 데이터, 6번째 행과 열은 합계
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            arr[i][j] = rand() % 100 + 100; // 100~199
            arr[i][5] += arr[i][j];
            arr[5][j] += arr[i][j];
        }
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}