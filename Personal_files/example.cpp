#include <iostream>
using namespace std;

int main() {
    string name;
    int age;

    cout << "이름을 입력하세요: ";
    cin >> name; // 이름 입력

    cout << "나이를 입력하세요: ";
    cin >> age; // 나이 입력

    cout << "안녕하세요, " << name << "님! 당신의 나이는 " << age << "살입니다." << endl;

    return 0;
}
