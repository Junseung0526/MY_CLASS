#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Person {
private:
	string name;
	string email;
	string phone;
public:
	Person(string name = "", string email = "", string phone = "")
		: name(name), email(email), phone(phone) {
	}

	string getName() { return name; }
	string getEmail() { return email; }
	string getPhone() { return phone; }

	void setName(string newName) { name = newName; }
	void setEmail(string newEmail) { email = newEmail; }
	void setPhone(string newPhone) { phone = newPhone; }
};

int main() {
	Person person("ȫ�浿", "hong@example.com", "010-1234-5678");
	cout << "Name: " << person.getName() << ", Email: " << person.getEmail() << ", Phone: " << person.getPhone() << endl;

	return 0;
}