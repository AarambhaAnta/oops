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
    double altitude;
    double speed;
    bool isFlying;

public:
    Flyable(const double& a = 0.0, const double& s = 0.0) : altitude(a), speed(s), isFlying(false) {
        cout << "---Flyable Constructor---" << endl;
    };
    virtual ~Flyable() {
        cout << "---Flyable Destructor---" << endl;
    }

    // Getter
    double getAltitude() const {
        return altitude;
    }
    double getSpeed() const {
        return speed;
    }

    // Setter
    bool setAltitude(const double& a) {
        if (a > 0.0) {
            altitude = a;
            return true;
        }
        return false;
    }
    bool setSpeed(const double& s) {
        if (s > 0.0) {
            speed = s;
            return true;
        }
        return false;
    }

    virtual void fly() {
        isFlying = true;
        cout << "---Flying---" << endl;
    }
    virtual void land() {
        isFlying = false;
        cout << "---Landed---" << endl;
    }

    void getFlightInfo() const {
        cout << "\n===Flight Info===" << endl;
        cout << "Altitude: " << altitude << endl;
        cout << "Speed: " << speed << endl;
        cout << "Flying: " << isFlying << endl;
    }
};

class Swimmable {
protected:
    double depth;
    double swimSpeed;
    bool isSwimming;

public:
    Swimmable(const double& d = 0.0, const double& s = 0.0)
        : depth(d), swimSpeed(s), isSwimming(false) {
        cout << "---Swimmable Constructor---" << endl;
    }
    virtual ~Swimmable() {
        cout << "---Swimmable Destructor---" << endl;
    }

    // Getter
    double getDepth() const {
        return depth;
    }
    double getSwimSpeed() const {
        return swimSpeed;
    }

    // Setter
    bool setDepth(const double& d) {
        if (d > 0.0) {
            depth = d;
            return true;
        }
        return false;
    }
    bool setSwimSpeed(const double& s) {
        if (s > 0.0) {
            swimSpeed = s;
            return true;
        }
        return false;
    }

    virtual void swim() {
        isSwimming = true;
        cout << "---Swimming---" << endl;
    }

    virtual void dive() {
        isSwimming = false;
        cout << "---Diving---" << endl;
    }

    void getSwimInfo() const {
        cout << "\n===Swim Info===" << endl;
        cout << "Depth: " << depth << endl;
        cout << "Speed: " << swimSpeed << endl;
        cout << "Swimming: " << isSwimming << endl;
    }
};

class Duck : public Flyable, public Swimmable {
private:
    string name;
    string species;
    bool inWater;
    bool onLand;

public:
    Duck(const string& name = "", const string& species = "", const double& altitude = 0.0,
         const double& speed = 0.0, const double& depth = 0.0, const double& swimSpeed = 0.0)
        : Flyable(altitude, speed), Swimmable(depth, swimSpeed), name(name), species(species),
          inWater(true), onLand(false) {
        cout << "---Duck Constructor---" << endl;
        isSwimming = true;
    }

    // Getter
    string getName() const {
        return name;
    }
    string getSpecies() const {
        return species;
    }

    bool quack() {
        if (!name.empty()) {
            cout << "---quacking---" << endl;
            return true;
        }
        return false;
    }

    bool waddle() {
        if (name.empty())
            return false;
        cout << "---Walking---" << endl;
        return true;
    }
    bool preen() {
        if (name.empty())
            return false;
        cout << "---Cleaning---" << endl;
        return true;
    }
    bool takeOffFromWater() {
        if (!inWater)
            return false;
        cout << "---Leaving water---" << endl;
        inWater = false;
        onLand = true;
        Flyable::fly();
        return true;
    }
    bool landOnWater() {
        if (!onLand)
            return false;
        cout << "---Entering water---" << endl;
        inWater = true;
        onLand = false;
        Swimmable::swim();
        return true;
    }
    bool performAerialDive() {
        if (inWater)
            return false;
        inWater = true;
        onLand = false;
        Swimmable::dive();
        return true;
    }
    bool move() {
        if (inWater)
            return false;
        cout << "---Moving---" << endl;
        return true;
    }
    void displayAllCapabilities() {
        Flyable::getFlightInfo();
        Swimmable::getSwimInfo();
        cout << "---Duck Specific Info---" << endl;
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "In water: " << inWater << endl;
        cout << "On Land: " << onLand << endl;
    }
};

int main() {
    // TODO: Create Duck object and use both interfaces

    cout << "===Multiple Inheritance Demo - Duck Class===" << endl;

    Duck duck("Donald", "Mallard", 100.0, 50.0, 5.0, 10.0);

    duck.quack();
    duck.waddle();
    duck.preen();
    duck.move();

    duck.displayAllCapabilities();


    return 0;
}
