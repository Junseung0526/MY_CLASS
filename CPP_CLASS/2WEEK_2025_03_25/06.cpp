#include <iostream>
using namespace std;

int main() {
    double side;
    double area;
    double perimeter;

    cout << "���簢���� ���� ���̸� �Է��ϼ���: ";
    cin >> side;

    area = side * side;
    perimeter = 4 * side;

    cout << "���簢���� ����: " << area << endl;
    cout << "���簢���� �ѷ�: " << perimeter << endl;

    return 0;
}