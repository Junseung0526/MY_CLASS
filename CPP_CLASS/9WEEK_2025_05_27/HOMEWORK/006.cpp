#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

int main() {
    srand(time(0));
    set<int> s;
    while (s.size() < 10) {
        s.insert(rand() % 100 + 1);
    }

    cout << "Unique array: ";
    for (int n : s) cout << n << " ";
    cout << endl;
    return 0;
}