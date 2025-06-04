#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    set<int> uniqueNums;
    while (uniqueNums.size() < 20) {
        uniqueNums.insert(rand() % 100 + 1);
    }

    vector<int> even, odd;
    for (int n : uniqueNums) {
        (n % 2 == 0 ? even : odd).push_back(n);
    }

    cout << "Even: ";
    for (int n : even) cout << n << " ";
    cout << "\nOdd: ";
    for (int n : odd) cout << n << " ";
    cout << endl;
    return 0;
}