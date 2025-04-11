#include <iostream>
using namespace std;

int main() {

    int n1, n2, n3;
    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;


    int min = (n1 < n2) ? ((n1 < n3) ? n1 : n3) : ((n2 < n3) ? n2 : n3);

    cout << "The smallest number is: " << min << endl;

    return 0;
}