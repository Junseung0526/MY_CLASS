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
        cout << "\n===== ATM �޴� =====" << endl;
        cout << "1. �Ա�\n2. ���\n3. �ܾ� ��ȸ\n4. ����" << endl;
        cout << "====================" << endl;
        cout << "�޴� ����: ";
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
            cout << "���α׷��� �����մϴ�." << endl;
            return 0;
        default:
            cout << "�߸��� �޴��Դϴ�. 1~4 �߿��� �������ּ���." << endl;
        }
    }
}

// �Ա� �Լ�
void deposit(int& balance) {
    int amount;
    cout << "�Ա��� �ݾ�: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "0���� ū �ݾ׸� �Ա� �����մϴ�." << endl;
        return;
    }
    balance += amount;
    cout << "�Ա� �Ϸ�!" << endl;
    logTransaction("�Ա�", amount, balance);
}

// ��� �Լ�
void withdraw(int& balance) {
    int amount;
    cout << "����� �ݾ�: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "0���� ū �ݾ׸� ��� �����մϴ�." << endl;
        return;
    }
    else if (amount > balance) {
        cout << "�ܾ��� �����մϴ�!" << endl;
        return;
    }
    balance -= amount;
    cout << "��� �Ϸ�!" << endl;
    logTransaction("���", amount, balance);
}

// �ܾ� ��ȸ �Լ�
void checkBalance(int balance) {
    cout << "���� �ܾ�: " << balance << "��" << endl;
}

// �α� ��� �Լ� (��¥ + �ð� ����)
void logTransaction(const string& type, int amount, int balance) {
    ofstream log("log.txt", ios::app);
    if (log.is_open()) {
        time_t now = time(0);
        tm* local = localtime(&now);

        char timeStr[100];
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", local);

        log << "[" << timeStr << "] " << type << " " << amount << "�� �� �ܾ�: " << balance << "��\n";
        log.close();
    }
    else {
        cout << "�α� ������ �� �� �����ϴ�!" << endl;
    }
}
