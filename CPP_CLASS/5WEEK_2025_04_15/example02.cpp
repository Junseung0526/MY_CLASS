#include <iostream>
using namespace std;

int main() {
    int type, size;

    cout << "Enter pattern type (1: Reverse Triangle, 2: Triangle): ";
    cin >> type;
    cout << "Enter number of lines: ";
    cin >> size;

    switch (type) {
    case 1: {

        for (int i = size; i >= 1; i--) {
            for (int j = 0; j < size - i; j++) {
                cout << " ";
            }
            for (int j = 0; j < (2 * i - 1); j++) {
                cout << "*";
            }
            cout << endl;
        }
        break;
    }

    case 2: {
        for (int i = 1; i <= size; i++) {
            for (int j = 0; j < size - i; j++) {
                cout << " ";
            }
            for (int j = 0; j < (2 * i - 1); j++) {
                cout << "*";
            }
            cout << endl;
        }
        break;
    }

    default:
        cout << "Invalid pattern type!" << endl;
    }

    return 0;
}
