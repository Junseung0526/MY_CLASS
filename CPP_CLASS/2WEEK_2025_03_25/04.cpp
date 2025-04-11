#include <iostream>
using namespace std;

int main() {
    int hours, minutes, seconds;
    int total;

    cout << "시간을 입력하세요 (시간, 분, 초): ";
    cin >> hours >> minutes >> seconds;

    total = (hours * 3600) + (minutes * 60) + seconds;

    cout << "총 " << total << "초입니다." << endl;

    return 0;
}