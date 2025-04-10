#include <iostream>
using namespace std;

struct student
{
    string name;
    int age;
    double grade;
};


int main() {
    student s1 = {"홍길동", 20, 95.5};
    cout << "이름: " << s1.name << ", 나이: " << s1.age << ", 성적: " << s1.grade << endl;

    return 0;
}