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
    double flightSpeed;
    bool isFlying;

public:
    Flyable(const double& a = 0.0, const double& s = 0.0) : altitude(a), flightSpeed(s), isFlying(false) {
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
        return flightSpeed;
    }
    bool getIsFlying() const {
        return isFlying;
    }

    // Setter
    bool setAltitude(const double& a) {
        if (a > 0.0) {
            altitude = a;
            return true;
        }
        return false;
    }
    bool setFlightSpeed(const double& s) {
        if (s > 0.0) {
            flightSpeed = s;
            return true;
        }
        return false;
    }

    // Flight operations
    virtual void startFlying() {
        if (!isFlying) {
            isFlying = true;
            cout << "---Starting Flight---" << endl;
        }
    }
    virtual void stopFlying() {
        if (isFlying) {
            isFlying = false;
            altitude = 0.0;
            cout << "---Landing---" << endl;
        }
    }

    virtual void adjustFlightSpeed(const double& newSpeed) {
        if (isFlying && newSpeed > 0.0) {
            flightSpeed = newSpeed;
            cout << "---Adjusting flight speed to " << newSpeed << "mph---" << endl;
        }
    }

    void getFlightInfo() const {
        cout << "\n===Flight Info===" << endl;
        cout << "Altitude: " << altitude << " feet" << endl;
        cout << "Flight Speed: " << flightSpeed << " mph" << endl;
        cout << "Currently Flying: " << (isFlying ? "YES" : "NO") << endl;
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
    bool getIsSwimming() const {
        return isSwimming;
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

    // Swimming operations
    virtual void startSwimming() {
        if (!isSwimming) {
            isSwimming = true;
            cout << "---Starting Swimming---" << endl;
        }
    }

    virtual void stopSwimming() {
        if (isSwimming) {
            isSwimming = false;
            depth = 0.0;
            cout << "---Surfacing---" << endl;
        }
    }

    virtual void dive() {
        if (isSwimming) {
            depth += 5.0;
            cout << "---Diving deeper to " << depth << " feet---" << endl;
        }
    }

    virtual void adjustSwimSpeed(const double& newSpeed) {
        if (isSwimming && newSpeed > 0.0) {
            swimSpeed = newSpeed;
            cout << "---Adjusting swim speed to " << newSpeed << " mph---" << endl;
        }
    }

    void getSwimInfo() const {
        cout << "\n===Swim Info===" << endl;
        cout << "Depth: " << depth << " feet" << endl;
        cout << "Swim Speed: " << swimSpeed << " mph" << endl;
        cout << "Currently Swimming: " << (isSwimming ? "YES" : "NO") << endl;
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
        // Ducks start in water by default
        isSwimming = true;
    }

    virtual ~Duck() {
        cout << "---Duck Destructor for " << name << "---" << endl;
    }

    // Getter
    string getName() const {
        return name;
    }

    string getSpecies() const {
        return species;
    }

    bool isInWater() const {
        return inWater;
    }

    bool isOnLand() const {
        return onLand;
    }

    // Duck-specific behaviors
    void quack() const {
        cout << name << " says: QUACK QUACK!" << endl;
    }

    void waddle() const {
        if (onLand) {
            cout << name << " is waddling on land" << endl;
        } else {
            cout << name << " cannot waddle while in water" << endl;
        }
    }

    void preen() const {
        cout << name << " is preening its feathers" << endl;
    }

    // Override flying methods to handle duck-specific logic
    void startFlying() override {
        if (inWater) {
            cout << name << " is taking off from water..." << endl;
            inWater = false;
            onLand = false;
        } else if (onLand) {
            cout << name << " is taking off from land..." << endl;
        }
        Flyable::startFlying();
    }

    void stopFlying() override {
        if (isFlying) {
            cout << name << " is choosing where to land..." << endl;
            Flyable::stopFlying();
            // Default landing is on water
            landOnWater();
        }
    }

    // Overrding swimming methods to handle duck-specific logic
    void startSwimming() override {
        if (!inWater) {
            cout << name << " is entering the water..." << endl;
            inWater = true;
            onLand = false;
        }
        Swimmable::startSwimming();
    }

    void stopSwimming() override {
        if (isSwimming) {
            cout << name << " is getting out of water..." << endl;
            Swimmable::stopSwimming();
            inWater = false;
            onLand = true;
        }
    }

    // Duck-specific combined behaviors
    void takeOffFromWater() {
        if (inWater && !isFlying) {
            cout << "\n" << name << " preparing for water takeoff..." << endl;
            stopSwimming();
            startFlying();
        } else {
            cout << name << " cannot take off from water (not in water or already flying)" << endl;
        }
    }
    void landOnWater() {
        if (!inWater) {
            cout << "\n" << name << " landing on water..." << endl;
            inWater = true;
            onLand = false;
            startSwimming();
        }
    }
    void landOnLand() {
        if (!onLand) {
            cout << "\n" << name << " landing on land..." << endl;
            inWater = false;
            onLand = true;
            if (isSwimming)
                stopSwimming();
            if (isFlying)
                Flyable::stopFlying();
        }
    }
    void performAerialDive() {
        if (isFlying) {
            cout << '\n' << name << " performing aerial dive..." << endl;
            stopFlying();
            startSwimming();
            dive();
        } else {
            cout << name << " must be flying to perform aerial dive" << endl;
        }
    }

    // Movement coordination
    void move() {
        if (isFlying) {
            cout << name << " is flying through the air" << endl;
        } else if (isSwimming) {
            cout << name << " is swimming through the water";
        } else if (onLand) {
            waddle();
        } else {
            cout << name << " is resting" << endl;
        }
    }

    // Display all capabilities
    void displayAllCapabilities() {
        cout << "\n=== " << name << " (" << species << ") Complete Status ===" << endl;

        // Duck-specific info
        cout << "\n---Duck Info---" << endl;
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "In water: " << (inWater ? "YES" : "NO") << endl;
        cout << "On Land: " << (onLand ? "YES" : "NO") << endl;

        // Flight capabilities
        Flyable::getFlightInfo();

        // Swimming capabilities
        Swimmable::getSwimInfo();

        // Current activity
        cout << "\n---Current Activity---" << endl;
        if(isFlying){
            cout << "Currently: Flying at " << altitude << " feet" << endl;
        }else if(isSwimming){
            cout << "Currently: Swimming at " << depth << " feet detph" << endl;
        }else if(onLand){
            cout << "Currently: Resting on land" << endl;
        }else{
            cout << "Currently: Floating on water surface" << endl;
        }
    }
};

int main() {
    // TODO: Create Duck object and use both interfaces

    cout << "===Multiple Inheritance Demo - Duck Class===" << endl;

    cout << "\n1. Creating Duck Object..." << endl;
    Duck duck("Donald", "Mallard", 0.0, 45.0, 2.0, 8.0);

    cout << "\n2. Testing basic duck behaviors..." << endl;
    duck.quack();
    duck.preen();
    duck.move();

    cout << "\n3. Testing swimming capabilities..." << endl;
    duck.startSwimming();
    duck.adjustSwimSpeed(12.0);
    duck.dive();
    duck.dive();

    cout << "\n4. Testing flying capabilities..." << endl;
    duck.takeOffFromWater();
    duck.adjustFlightSpeed(55.0);
    duck.setAltitude(150.0);

    cout << "\n5. Testing combined behaviors..." << endl;
    duck.performAerialDive();
    duck.takeOffFromWater();
    duck.landOnLand();
    duck.waddle();


    return 0;
}
