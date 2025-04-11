#include <iostream>
using namespace std;

int main() {
    double side;
    double area;
    double perimeter;

    cout << "정사각형의 변의 길이를 입력하세요: ";
    cin >> side;

    area = side * side;
    perimeter = 4 * side;

    cout << "정사각형의 면적: " << area << endl;
    cout << "정사각형의 둘레: " << perimeter << endl;

    return 0;
}