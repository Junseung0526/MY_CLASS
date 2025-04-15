#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int perLine = 5;

    for (int i = 1; i <= 100; i++) {
        if (i % 7 == 0) {
            cout << i << "\t";
            count++;

            if (count % perLine == 0) {
                cout << endl;
            }
        }
    }

    return 0;
}