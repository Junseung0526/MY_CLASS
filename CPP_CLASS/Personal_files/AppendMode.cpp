#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("example.txt", ios::app);

    if (outFile.is_open()) {
        outFile << "이 내용은 기존 파일 끝에 추가됩니다! 🔥 //Written By AppendMode.cpp\n";
        outFile.close();
        cout << "새로운 내용 추가 완료! ✅" << endl;
    } else {
        cout << "파일을 열 수 없습니다. ❌" << endl;
    }

    return 0;
}
