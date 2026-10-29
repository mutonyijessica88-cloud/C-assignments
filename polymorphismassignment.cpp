#include <iostream>
#include <string>
using namespace std;
class Animal
{
public:
    virtual void makeSound() const
    {
        cout << "The animal makes a sound." << endl;
    }
    virtual ~Animal() = default;
};
class Dog : public Animal
{
private:
    string name;

public:
    Dog(string animalName) : name(animalName) {};
    void makeSound() const override
    {
        cout << name << " says: Woof!" << endl;
    }
};
class Cat : public Animal
{
private:
    string name;

public:
    Cat(string animalName) : name(animalName) {};
    void makeSound() const override
    {
        cout << name << " says: Meow!" << endl;
    }
};
int main()
{

    Animal *animal1 = new Dog("Buddy");
    Animal *animal2 = new Cat("Whiskers");

    animal1->makeSound();
    animal2->makeSound();

    delete animal1;
    delete animal2;

    return 0;
}