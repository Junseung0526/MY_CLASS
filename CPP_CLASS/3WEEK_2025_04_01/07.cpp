#include <iostream>
using namespace std;

int main() {
    int hours;

    cout << "Enter hours: ";
    cin >> hours;


    int day = (hours / 24) % 7;
    int last_hour = hours % 24;

    
    cout << "Day: " << day << " and " << "Hour: " << last_hour << endl;

    return 0;
}