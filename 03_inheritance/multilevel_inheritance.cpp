// Multilevel inheritance
// Problem: Create a chain of inheritance

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// TODO: Create multilevel inheritance:
// - Base: Animal (name, age)
// - Derived: Mammal (furColor, warmBlooded)
// - Further derived: Dog (breed, loyalty)
// - Show how properties pass down the chain
// - Demonstrate method overriding at each level

class Animal {
private:
    string name;
    int age;

public:
    Animal(string name = "", int age = 0) : name(name), age(age) {
        cout << "Animal Constructor..." << endl;
    }
    virtual ~Animal() {
        cout << "Animal Destructor..." << endl;
    }

    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    virtual void makeSound() const {
        cout << "Animal sounding..." << endl;
    }
    virtual void displayInfo() const {
        cout << "<--Animal Info-->" << endl;
        cout << "Animal Name: " << name << endl;
        cout << "Animal Age: " << age << endl;
    }
};

class Mammal : public Animal {
private:
    string furColor;
    bool warmBlood;

public:
    Mammal(string name = "", int age = 0, string furColor = "", bool warmBlood = false)
        : Animal(name, age), furColor(furColor), warmBlood(warmBlood) {
        cout << "Mammal Constructor..." << endl;
    }
    virtual ~Mammal() {
        cout << "Mammal Destructor..." << endl;
    }

    string getFurColor() const {
        return furColor;
    }
    bool isWarmBlooded() const {
        return warmBlood;
    }
    void makeSound() const override {
        cout << "Mammal Sounding..." << endl;
    }
    void displayInfo() const override {
        Animal::displayInfo();
        cout << "<--Mammal Info-->" << endl;
        cout << "Mammal Fur Color: " << furColor << endl;
        cout << "Mammal is Warm Blooded: " << warmBlood << endl;
    }
};

class Dog : public Mammal {
private:
    string breed;
    int loyalty;

public:
    Dog(string name = "Buddy", int age = 1, string furColor = "Brown", bool warmBlood = true,
        string breed = "Mixed", int loyalty = 75)
        : Mammal(name, age, furColor, warmBlood), breed(breed), loyalty(loyalty) {
        cout << "Dog Constructor..." << endl;
    }
    virtual ~Dog() {
        cout << "Dog Destructor..." << endl;
    }

    string getBreed() const {
        return breed;
    }
    int getLoyalty() const {
        return loyalty;
    }
    void makeSound() const override {
        cout << "Woof, Woff..." << endl;
    }
    void displayInfo() const override {
        Mammal::displayInfo();
        cout << "<--Dog Info-->" << endl;
        cout << "Dog Breed: " << breed << endl;
        cout << "Dog Loyalty: " << loyalty << endl;
    }
};

int main() {
    // TODO: Create Dog object and show multilevel inheritance

    cout << "\n===Multilevel Inheritance Demo===\n" << endl;

    Dog defaultDog;
    defaultDog.displayInfo();
    cout << endl;

    Dog myDog("Max", 3, "Golden", true, "Golden Retriever", 95);
    myDog.displayInfo();
    cout << endl;

    Animal* animalPtr = &myDog;
    Mammal* mammalPtr = &myDog;

    cout << "Using Animal pointer: ";
    animalPtr->makeSound();

    cout << "Using Mammal pointer: ";
    mammalPtr->makeSound();

    cout << "Using Dog object: ";
    myDog.makeSound();

    cout << "\nAccessibility Check..." << endl;
    cout << "Name(from Animal): " << myDog.getName() << endl;
    cout << "Fur Color(from Mammal): " << myDog.getFurColor() << endl;

    cout << "\nRelationship testing(Is-A)..." << endl;
    cout << "myDog type: " << typeid(myDog).name() << endl;
    cout << "Animal type: " << typeid(Animal).name() << endl;
    cout << "Mammal type: " << typeid(Mammal).name() << endl;
    cout << endl;

    return 0;
}
