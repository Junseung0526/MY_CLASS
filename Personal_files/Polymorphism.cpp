#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void makeSound()
    {
        cout << "동물이 소리를 냅니다!" << endl;
    }
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        cout << "멍멍!" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        cout << "야옹~" << endl;
    }
};

int main()
{
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();
    animal2->makeSound();
    
    return 0;
}
