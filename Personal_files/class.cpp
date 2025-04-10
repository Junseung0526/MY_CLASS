#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void introduce(){
        cout << "안녕하세요, 저는 " << name << "입니다!" << endl;

    }
};

int main() {

    Student s1;
    s1.name = "홍길동";
    s1.age = 20;
    s1.introduce();

    return 0;
}
