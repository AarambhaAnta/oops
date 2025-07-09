// Single inheritance
// Problem: Create a hierarchy with base and derived classes

#include <iostream>
#include <string>
using namespace std;

// TODO: Create inheritance hierarchy:
// - Base class: Vehicle (brand, model, year)
// - Derived class: Car (doors, fuelType)
// - Demonstrate method inheritance
// - Show constructor chaining
// - Access base class members

class Vehicle {
protected:
    string brand;
    string model;
    int year;

public:
    // Constructor

    // Getters

    // Setters

    // Utility
};

class Car : public Vehicle {
protected:
    int doors;
    string fuelType;

public:
    // Constructor

    // Getters

    // Setters

    // Utility
};

int main() {
    // TODO: Create objects and show inheritance
    return 0;
}
