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
    Counter(const int& val = 0) : value(val) {}
    ~Counter() {};

    // getters

    // setters
};
int main() {
    // TODO: Create multiple objects and show static behavior
    return 0;
}
