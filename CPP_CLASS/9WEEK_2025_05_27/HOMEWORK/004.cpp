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
        num = rand() % 100 + 1;
    }

    int minIndex = min_element(arr.begin(), arr.end()) - arr.begin();
    swap(arr[0], arr[minIndex]);

    cout << "Modified Array: ";
    for (int n : arr) cout << n << " ";
    cout << endl;
    return 0;
}