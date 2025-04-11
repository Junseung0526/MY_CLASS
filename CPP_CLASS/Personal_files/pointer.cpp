/* 
👉 메모리 주소를 저장하는 변수
👉 C++ 의 가장 중요한 개념 중 하나 !

📌 포인터를 배우면 ?
✅ 변수의 메모리 주소를 직접 다룰 수 있음
✅ 배열, 동적 할당(new, delete) 을 이해하는 데 필수
✅ C++ 의 핵심 개념인 포인터와 참조를 완벽하게 익힐 수 있음

✅ &는 "주소를 얻는 연산자"
✅ *는 "포인터를 통해 값을 가져오거나 변경하는 연산자"

*/
#include <iostream>
using namespace std;

int main()
{
    int num = 10;
    int* ptr = &num;

    cout << "num의 값: " << num << endl;
    cout << "num의 주소: " << &num << endl;
    cout << "ptr의 값: " << ptr << endl;
    cout << "ptr이 가르키는 값: " << *ptr << endl;


    int a = 0526;
    int *p = &a;

    cout << "\n"; //enter 

    cout << a << endl; //a의 값
    cout << &a << endl; //a의 주소
    cout << p << endl; //p의 값
    cout << *p << endl; //p가 가리키는 값




    return 0;
}