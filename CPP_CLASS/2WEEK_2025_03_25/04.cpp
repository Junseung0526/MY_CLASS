#include <iostream>
using namespace std;

int main() {
    int hours, minutes, seconds;
    int total;

    cout << "�ð��� �Է��ϼ��� (�ð�, ��, ��): ";
    cin >> hours >> minutes >> seconds;

    total = (hours * 3600) + (minutes * 60) + seconds;

    cout << "�� " << total << "���Դϴ�." << endl;

    return 0;
}