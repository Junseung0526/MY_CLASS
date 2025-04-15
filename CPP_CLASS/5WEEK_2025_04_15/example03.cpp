#include <iostream>
using namespace std;

int main() {
    int num;
    int sum = 0;
    int count = 0;
    double avg = 0.0;

    do {
        cout << "Enter the number (1000 to stop): ";
        cin >> num;

        if (num == 1000) break;

        sum += num;
        count++;
    } while (true);

    if (count > 0) {
        avg = static_cast<double>(sum) / count;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << avg << endl;
    }
    else {
        cout << "No valid input entered." << endl;
    }

    return 0;
}
