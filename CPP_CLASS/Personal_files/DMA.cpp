#include <iostream>
using namespace std;;

int main (){
 
    int* p = new int;

    cout << "정수를 입력하세요: ";
    cin >> *p;
    cout << "입력한 값: " << *p << endl;

    delete p;
    p = nullptr;

    return 0;
}