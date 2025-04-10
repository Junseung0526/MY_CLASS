#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile("example.txt");
    if (outFile.is_open())
    {
        outFile << "Hello, File I/O!\n";
        outFile << "C++에서 파일을 다루는 방법을 배우고 있어요.\n";
        outFile.close();
        cout << "파일에 데이터 저장 완료! ✅" << endl;
    }
    else
    {
        cout << "파일을 열 수 없습니다. ❌" << endl;
    }

    return 0;
}