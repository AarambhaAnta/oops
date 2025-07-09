// Static members and methods
// Problem: Understand class-level vs instance-level members

#include <iostream>
using namespace std;

// TODO: Create a Counter class with:
// - Static variable to count total objects
// - Static method to get count
// - Instance methods to increment/decrement
// - Demonstrate static vs non-static behavior

class Counter {
private:
    static int objCount;
    int value;

public:
    Counter(const int& val = 0) : value(val) {
        ++objCount;
    }
    ~Counter() {};

    // getters
    static int getTotalCount() {
        return objCount;
    }
    int getValue() const {
        return value;
    }
    // setters

    // utility
    void increment() {
        ++value;
    }
    void decrement() {
        --value;
    }
};

int Counter::objCount = 0;

int main() {
    // TODO: Create multiple objects and show static behavior

    Counter c1;
    Counter c2(202);
    cout << "\nCounter 1 value: " << c1.getValue() << endl;
    cout << "Counter 2 value: " << c2.getValue() << endl;
    cout << "Total Object Count: " << Counter::getTotalCount() << endl;

    Counter c3;
    c3.increment();
    c3.increment();
    cout << "\nCounter 3 value: " << c3.getValue() << endl;
    c3.decrement();
    cout << "Counter 3 value: " << c3.getValue() << endl;
    cout << "Total Object Count: " << Counter::getTotalCount() << endl;
    return 0;
}
