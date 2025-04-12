#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;


void deposit(int& balance);
void withdraw(int& balance);
void checkBalance(int balance);
void logTransaction(const string& type, int amount, int balance);

int main() {
    int balance = 0;
    int menu;

    while (true) {
        cout << "\n===== ATM 메뉴 =====" << endl;
        cout << "1. 입금\n2. 출금\n3. 잔액 조회\n4. 종료" << endl;
        cout << "====================" << endl;
        cout << "메뉴 선택: ";
        cin >> menu;

        switch (menu) {
        case 1:
            deposit(balance);
            break;
        case 2:
            withdraw(balance);
            break;
        case 3:
            checkBalance(balance);
            break;
        case 4:
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        default:
            cout << "잘못된 메뉴입니다. 1~4 중에서 선택해주세요." << endl;
        }
    }
}

// 입금 함수
void deposit(int& balance) {
    int amount;
    cout << "입금할 금액: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "0보다 큰 금액만 입금 가능합니다." << endl;
        return;
    }
    balance += amount;
    cout << "입금 완료!" << endl;
    logTransaction("입금", amount, balance);
}

// 출금 함수
void withdraw(int& balance) {
    int amount;
    cout << "출금할 금액: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "0보다 큰 금액만 출금 가능합니다." << endl;
        return;
    }
    else if (amount > balance) {
        cout << "잔액이 부족합니다!" << endl;
        return;
    }
    balance -= amount;
    cout << "출금 완료!" << endl;
    logTransaction("출금", amount, balance);
}

// 잔액 조회 함수
void checkBalance(int balance) {
    cout << "현재 잔액: " << balance << "원" << endl;
}

// 로그 기록 함수 (날짜 + 시간 포함)
void logTransaction(const string& type, int amount, int balance) {
    ofstream log("log.txt", ios::app);
    if (log.is_open()) {
        time_t now = time(0);
        tm* local = localtime(&now);

        char timeStr[100];
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", local);

        log << "[" << timeStr << "] " << type << " " << amount << "원 → 잔액: " << balance << "원\n";
        log.close();
    }
    else {
        cout << "로그 파일을 열 수 없습니다!" << endl;
    }
}
