// Multiple inheritance
// Problem: Inherit from multiple base classes

#include <iostream>
#include <string>
using namespace std;

// TODO: Create multiple inheritance:
// - Base class 1: Flyable (altitude, speed)
// - Base class 2: Swimmable (depth, swimSpeed)
// - Derived class: Duck (inherits from both)
// - Handle potential naming conflicts
// - Demonstrate multiple inheritance usage

class Flyable {
protected:
    int altitude;
    int speed;

public:
};

class Swimmable {
protected:
    int depth;
    int swimSpeed;

public:
};

class Duck : public Flyable, public Swimmable {
private:
    string name;
    string species;

public:
};

int main() {
    // TODO: Create Duck object and use both interfaces
    return 0;
}
