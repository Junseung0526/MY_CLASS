#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;

    int start = (a < b) ? a : b;
    int end = (a > b) ? a : b;

    cout << "\nOdd numbers between " << start << " and " << end << ":" << endl;
    for (int i = start; i <= end; i++) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }

    cout << "\n\nEven numbers between " << start << " and " << end << ":" << endl;
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}
