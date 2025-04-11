#include <iostream>
using namespace std;

class Animal
{
public:
    void makeSound()
    {
        cout << "동물이 소리를 냅니다!" << endl;
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        cout << "멍멍!" << endl;
    }
};

int main()
{
    Dog myDog;
    myDog.makeSound();
    myDog.bark();
    return 0;
}
