#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    virtual void makeSound() = 0;
    virtual void move() = 0;

    virtual ~Animal() {}
};

class Lion : public Animal
{
public:
    void makeSound() override
    {
        cout << "Lion: Roar!" << endl;
    }

    void move() override
    {
        cout << "Lion: Runs swiftly on land." << endl;
    }
};

class Fish : public Animal
{
public:
    void makeSound() override
    {
        cout << "Fish: almost silent." << endl;
    }

    void move() override
    {
        cout << "Fish: Swims through water." << endl;
    }
};

int main()
{
    Lion lion1;
    Fish fish1;

    Animal *animals[2];
    animals[0] = &lion1;
    animals[1] = &fish1;

    cout << "Animal Behavior:" << endl;
    cout << "-----------------" << endl;

    for (int i = 0; i < 2; i++)
    {
        animals[i]->makeSound();
        animals[i]->move();
        cout << endl;
    }
}