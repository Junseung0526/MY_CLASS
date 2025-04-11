#include <iostream>
using namespace std;

int main() {
    int hours, minutes, seconds;

    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;
    cout << "Enter seconds: ";
    cin >> seconds;

    int total_seconds = (hours * 3600) + (minutes * 60) + seconds;

    cout << "Total seconds: "  << total_seconds << endl;
    return 0;
}