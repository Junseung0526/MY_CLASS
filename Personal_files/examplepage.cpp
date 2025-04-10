#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "동물이 소리를 냅니다." << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "멍멍" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "야옹" << endl;
    }
};

int main()
{

    Animal* Animal1 = new Dog();
    Animal* Animal2 = new Cat();

    Animal1->sound();
    Animal2->sound();

    delete Animal1;
    Animal1 = nullptr;
    delete Animal2;
    Animal2 = nullptr;

    return 0;
}