#include <iostream>
using namespace std;

int main() {
    int num;
    int positiveCount = 0;
    int negativeCount = 0;

    cout << "Enter numbers (0 to stop):\n";

    while (true) {
        cin >> num;

        if (num == 0) {
            break;
        }

        if (num > 0) {
            positiveCount++;
        }
        else if (num < 0) {
            negativeCount++;
        }
    }

    cout << "Positive numbers: " << positiveCount << endl;
    cout << "Negative numbers: " << negativeCount << endl;

    return 0;
}
