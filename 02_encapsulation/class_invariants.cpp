// Class invariants and data validation
// Problem: Maintain object state consistency

#include <iostream>
#include <string>
using namespace std;

// TODO: Create a Date class with:
// - Private: day, month, year
// - Validation to ensure valid dates
// - Methods to add days, months, years
// - Maintain invariants (valid date always)
// - Handle edge cases (leap years, month boundaries)

class Date {
private:
    int day;
    int month;
    int year;

    // Helper methods
    bool isLeapYear(const int& year) const {};
    int getDayInMonth(const int& month) const {};

    // Validate and maintain class invariant
    bool isValidDate(const int& month) const {};

public:
    // Constructor with validation

    // Getter

    // Display date

    // Add date while maintaing class invariant

    // Add month while maintaing class invariant

    // Add year while maintaing class invariant

    // Set date with validation

    // Validity check for date
};

int main() {
    // TODO: Test date validation and operations
    return 0;
}
