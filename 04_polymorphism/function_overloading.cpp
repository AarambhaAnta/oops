// Function overloading
// Problem: Multiple functions with same name but different parameters

#include <iostream>
using namespace std;

// TODO: Create a Calculator class with:
// - Overloaded add() methods for different data types
// - add(int, int), add(double, double), add(int, double)
// - Overloaded constructors
// - Demonstrate compile-time polymorphism

class Calculator {
private:
    string name;
    string version;
    static int count;

public:
    Calculator(string name = "", string version = "") : name(name), version(version) {
        cout << "Calculator Constructor..." << endl;
    }
    ~Calculator() {
        cout << "Calculator Destructor..." << endl;
    }

    // Function overloading
    int add(int a, int b) {
        count++;
        return a + b;
    }
    double add(int a, double b) {
        count++;
        return (double)a + b;
    }
    double add(double a, int b) {
        count++;
        return a + (double)b;
    }
    double add(double a, double b) {
        count++;
        return a + b;
    }
    int subtract(int a, int b) {
        count++;
        return a - b;
    }
    double subtract(int a, double b) {
        count++;
        return (double)a - b;
    }
    double subtract(double a, int b) {
        count++;
        return a - (double)b;
    }
    double subtract(double a, double b) {
        count++;
        return a - b;
    }
    int multiply(int a, int b) {
        count++;
        return a * b;
    }
    double multiply(int a, double b) {
        count++;
        return (double)a * b;
    }
    double multiply(double a, int b) {
        count++;
        return a * (double)b;
    }
    double multiply(double a, double b) {
        count++;
        return a * b;
    }

    // Getters
    string getName() const {
        return name;
    }
    string getVersion() const {
        return version;
    }

    // Setters
    bool setName(string name) {
        if (name.empty())
            return false;
        this->name = name;
        return true;
    }
    bool setVersion(string version) {
        if (version.empty())
            return false;
        this->version = version;
        return true;
    }
    static int getCoumputationCount() {
        return count;
    }
};
int Calculator::count = 0;

int main() {
    // TODO: Test function overloading

    cout << "\n===Function Overloading Demonstration===" << endl;
    Calculator calc1;
    Calculator calc2("Boy", "v.1");

    cout << "Int Addition: " << calc1.add(3, 5) << endl;
    cout << "Double Addtion: " << calc2.add(3.5, 5.3) << endl;

    cout << "Int Product: " << calc1.multiply(3, 5) << endl;
    cout << "Double Product: " << calc2.multiply(3.5, 2) << endl;

    cout << "Int Difference: " << calc1.subtract(2, 3) << endl;
    cout << "Double Difference: " << calc2.subtract(3, 2.5) << endl;

    cout << "Total Computation: " << Calculator::getCoumputationCount() << endl;
    return 0;
}
