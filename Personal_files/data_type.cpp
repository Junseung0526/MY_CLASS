#include <iostream>
using namespace std;

int main() {

    int num1;           //4byte
    unsigned int num2;  //4byte

    cout << "Size of int: " << sizeof(num1) << endl;
    cout << "Size of unsigned int: " << sizeof(num2) << endl;
    cout << '\n' << endl;

    char cha1;          //1byte
    unsigned char cha2; //1byte

    cout << "Size of char: " << sizeof(cha1) << endl;
    cout << "Size of unsigned char: " << sizeof(cha2) << endl;
    cout << '\n' << endl;

    short num3;             //2byte
    unsigned short num4;    //2byte

    cout << "Size of short: " << sizeof(num3) << endl;
    cout << "Size of unsigned char: " << sizeof(num4) << endl;
    cout << '\n' << endl;

    long num5;              //4byte
    unsigned long num6;     //4byte
    long long num7;         //8byte

    cout << "Size of long: " << sizeof(num5) << endl;
    cout << "Size of unsigned long: " << sizeof(num6) << endl;
    cout << "Size of long long: " << sizeof(num7) << endl;
    cout << '\n' << endl;

    double num8;            //8byte
    long double num9;       //same as double

    cout << "Size of double: " << sizeof(num8) << endl;
    cout << "Size of long double: " << sizeof(num9) << endl;
    cout << '\n' << endl;
    return 0;
}