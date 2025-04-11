#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 7; j++) {
            if (j == 1 || j == 7 || i == 3)
                cout << "H";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}