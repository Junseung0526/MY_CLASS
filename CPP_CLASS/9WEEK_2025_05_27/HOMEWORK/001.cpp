#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    vector<int> arr(100);
    for (int &num : arr) {
        num = rand() % 101 + 100; // 100~200
    }

    for (int i = 0; i < 100; ++i) {
        cout << arr[i] << "\t";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    return 0;
}