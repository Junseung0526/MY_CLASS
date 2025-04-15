#include <iostream>
using namespace std;

int main() {
    int type, size;

    cout << "Enter pattern type (1-4): ";
    cin >> type;
    cout << "Enter pattern size (0-9): ";
    cin >> size;


    switch (type) {
    case 1: {
        for (int i = 1; i <= size; i++) {
            for (int j = 0; j < i; j++) {
                cout << "*";
            }
            cout << endl;
        }
        break;
    }

    case 2: {
        for (int i = size; i >= 1; i--) {
            for (int j = 0; j < size - i; j++) {
                cout << " ";
            }
            for (int j = 0; j < i; j++) {
                cout << "*";
            }
            cout << endl;
        }
        break;
    }

    case 3: {
        for (int i = size; i >= 1; i--) {
            for (int j = 0; j < size - i; j++) {
                cout << " ";
            }
            for (int j = 0; j < i; j++) {
                cout << "*";
            }
            cout << endl;
        }
        break;
    }

    case 4: {
        for (int i = 1; i <= size; i++) {
            for (int j = 0; j < size - i; j++) {
                cout << " ";
            }
            for (int j = 0; j < i; j++) {
                cout << "*";
            }
            cout << endl;
        }
        break;
    }

    default:
        cout << "Invalid type!" << endl;
    }

    return 0;
}
