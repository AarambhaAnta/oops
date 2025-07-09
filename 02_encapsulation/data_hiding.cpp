// Data hiding and access specifiers
// Problem: Implement proper encapsulation with private/protected/public

#include <iostream>
#include <string>
using namespace std;

// TODO: Create an Employee class with:
// - Private: salary, id
// - Protected: department
// - Public: name, getter/setter methods
// - Validate data in setters
// - Demonstrate data hiding principles

class Empolyee {
private:
    double salary;
    int id;

protected:
    string department;

public:
    string name;

    // Constructor & destructor

    // Getters & Setters;

    // Utilities
};

int main() {
    // TODO: Show how encapsulation protects data
    return 0;
}
