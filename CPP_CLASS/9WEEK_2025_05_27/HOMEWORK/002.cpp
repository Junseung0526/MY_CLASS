#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
    srand(time(0));
    vector<int> arr(10);
    for (int &num : arr) {
        num = rand() % 10 + 1; // 1~10
    }

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    cout << "Array: ";
    for (int n : arr) cout << n << " ";
    cout << "\nMin: " << minVal << ", Max: " << maxVal << endl;
    return 0;
}