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
    const int curYear = 2025;

public:
    // Constructor
    Vehicle(const string& b = "", const string& m = "", const int& y = 0)
        : brand(b), model(m), year(y) {}
    ~Vehicle() {}

    // Getters
    string getBrand() const {
        return brand;
    }
    string getModel() const {
        return model;
    }
    int getYear() const {
        return year;
    }
    int getAge() const {
        return curYear - year;
    }

    // Setters

    // Utility
    virtual void displayInfo() const {
        cout << "\n===Vehicle Info===" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle {
protected:
    int doors;
    string fuelType;

public:
    // Constructor
    Car(const string& b = "Toyota", const string& m = "", const int& y = 0, const int& d = 4,
        const string& f = "")
        : Vehicle(b, m, y), doors(d), fuelType(f) {}
    ~Car() {}

    // Getters
    int getDoors() const {
        return doors;
    }
    string getFuelType() const {
        return fuelType;
    }
    // Setters

    // Utility
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "===Car Info===" << endl;
        cout << "Doors: " << doors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

int main() {
    // TODO: Create objects and show inheritance

    cout << "\n===Single Inheritance Testing===" << endl;
    Car c1;
    Car c2("Rolls Royce", "Phantom", 2024, 5, "Hybrid");
    c1.displayInfo();
    c2.displayInfo();

    Vehicle* vehiclePrt = &c2;
    vehiclePrt->displayInfo();
    cout << "\n===Parent Class Pointer Access===" << endl;
    cout << "Brand: " << vehiclePrt->getBrand() << endl;

    // `Vehicle*` pointer can only access the methods of `Vehicle` class
    // to access the `Car` class methods use `dynamic_cast<Car*>(vehiclePtr)`
    // cout << "Fuel Type: " << vehiclePrt.getFuelType() << endl;

    Car* c3 = dynamic_cast<Car*>(vehiclePrt);
    cout << "\n===Dynamic Cast===" << endl;
    cout << "Brand: " << c3->getBrand() << endl;
    cout << "Fuel Type: " << c3->getFuelType() << endl;

    return 0;
}
