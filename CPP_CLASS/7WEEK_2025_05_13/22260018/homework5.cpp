#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Address {
private:
	string city;
	string cityName;
	string stateName;
	string zipcode;
public:
	Address(string city = "", string cityName = "", string stateName = "", string zipcode = "")
		: city(city), cityName(cityName), stateName(stateName), zipcode(zipcode) {
	}

	string getCity() { return city; }
	string getCityName() { return cityName; }
	string getStateName() { return stateName; }
	string getZipcode() { return zipcode; }

	void setCity(string c) { city = c; }
	void setCityName(string cn) { cityName = cn; }
	void setStateName(string sn) { stateName = sn; }
	void setZipcode(string zc) { zipcode = zc; }
};

int main() {

	Address addr("서울", "강남구", "서울특별시", "12345");
	cout << "City: " << addr.getCity() << ", CityName: " << addr.getCityName()
		<< ", State: " << addr.getStateName() << ", Zipcode: " << addr.getZipcode() << endl;


	return 0;
}