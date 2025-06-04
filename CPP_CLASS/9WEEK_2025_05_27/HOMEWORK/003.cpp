#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main() {
    srand(time(0));
    vector<int> arr(10);
    double sum = 0;
    for (int &num : arr) {
        num = rand() % 100 + 1;
        sum += num;
    }

    double mean = sum / arr.size();
    double variance = 0;
    for (int num : arr) {
        variance += (num - mean) * (num - mean);
    }
    variance /= arr.size();
    double stddev = sqrt(variance);

    cout << "Array: ";
    for (int n : arr) cout << n << " ";
    cout << "\nMean: " << mean << ", Std Dev: " << stddev << endl;
    return 0;
}