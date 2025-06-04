#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    vector<int> arr(10), even, odd;
    for (int &num : arr) {
        num = rand() % 100 + 1;
        (num % 2 == 0 ? even : odd).push_back(num);
    }

    cout << "Even: ";
    for (int n : even) cout << n << " ";
    cout << "\nOdd: ";
    for (int n : odd) cout << n << " ";
    cout << endl;
    return 0;
}