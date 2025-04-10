#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
public:
    
    BankAccount ( string a, double b){
        accountNumber = a;
        balance = b;
    }

    double getBalance(){
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;  // ✅ 입금 처리
            cout << amount << "원 입금 완료!" << endl;
        } else {
            cout << "❌ 입금 금액은 0보다 커야 합니다!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "❌ 잔액 부족! 출금 실패!" << endl;
        } else {
            balance -= amount;  // ✅ 출금 처리
            cout << amount << "원 출금 완료!" << endl;
        }
    }
};

int main() {
    BankAccount myAccount("123-456-789", 10000);
    cout << "▶ 초기 잔액: " << myAccount.getBalance() << "원" << endl;

    myAccount.deposit(5000);
    cout << "▶ 5000원 입금 후 잔액: " << myAccount.getBalance() << "원" << endl;

    myAccount.withdraw(3000);
    cout << "▶ 3000원 출금 후 잔액: " << myAccount.getBalance() << "원" << endl;

    myAccount.withdraw(20000);  // ❌ 잔액 부족 테스트

    return 0;
}