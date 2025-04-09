#include <iostream>
using namespace std;

int main() {
    int each, quantity;
    double discount = 0.0;

    cout << "Enter price per item: ";
    cin >> each;

    cout << "Enter quantity: ";
    cin >> quantity;

    if (quantity >= 100) {
        discount = 0.10;
    }
    else if (quantity >= 50) {
        discount = 0.05;
    }
    else if (quantity >= 10) {
        discount = 0.03;
    }
    else {
        discount = 0.0;
    }

    double total = each * quantity;
    double final_price = total * (1 - discount);

    cout << "Original price: " << total << "원" << endl;
    cout << "Discount: " << (discount * 100) << "%" << endl;
    cout << "Final price: " << final_price << "원" << endl;

    return 0;
}
