#include <iostream>
using namespace std;

int main(){

    int number[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {  // 배열 크기만큼 반복
        cout << "number[" << i << "] = " << number[i] << endl;
    }

    int size = sizeof(number) / sizeof(number[0]); // 배열 크기 계산

    cout << " " << endl;

    cout << "number_Size is " << size << endl;


    return 0;
}