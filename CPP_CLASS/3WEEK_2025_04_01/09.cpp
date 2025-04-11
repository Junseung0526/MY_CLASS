#include <iostream>
using namespace std;

int main() {
    long total_seconds;

    cout << "Enter total seconds: ";
    cin >> total_seconds;


    long hours = total_seconds / 3600;
    long minutes = (total_seconds % 3600) / 60;
    long seconds = total_seconds % 60;


    cout << total_seconds << "Seconds: "<< hours << " hours, "<< minutes << " minutes, and "<< seconds << " seconds." << endl;

    return 0;
}