#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("example.txt");
    
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "파일을 열 수 없습니다. ❌" << endl;
    }

    return 0;
}
