#include <iostream>
using namespace std;

void sayhello() {
    cout << "Hello, C++!" << endl;
}

int square(int num) {
    return num * num;
}

int add(int a, int b) {
    return a + b;
}

void printArray(int arr[], int size) {
    for (int i = 0; i< size ; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    sayhello();

    int result = square(5); // 5의 제곱 계산
    cout << "5의 제곱은 " << result << "입니다." << endl;

    int sum = add(7, 3); // 7 + 3
    cout << "7 + 3 = " << sum << endl;

    int number[5] = {1,2,3,4,5};

    printArray(number, 5);
    return 0;
}

