// Class invariants and data validation
// Problem: Maintain object state consistency

#include <iomanip>
#include <iostream>
#include <sstream>
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
    bool isLeapYear(const int& y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
    int getDayInMonth(const int& m, const int& y) const {
        if (m == 2) {
            return isLeapYear(y) ? 29 : 28;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        return 31;
    }

    // Validate and maintain class invariant
    bool isValidDate(const int& d, const int& m, const int& y) const {
        if (d < 1 || m < 1 || m > 12 || y < 1) {
            return false;
        }
        return d <= getDayInMonth(m, y);
    }

public:
    // Constructor with validation
    Date(const int& d = 1, const int& m = 1, const int& y = 2000) {
        if (!isValidDate(d, m, y)) {
            cout << "Invalid date..." << endl;
            day = 1;
            month = 1;
            year = 2000;
        } else {
            day = d;
            month = m;
            year = y;
        }
    }
    // Getter
    int getDay() const {
        return day;
    }
    int getMonth() const {
        return month;
    }
    int getYear() const {
        return year;
    }
    // Display date
    string toString() const {
        ostringstream oss;
        oss << setfill('0') << setw(2) << day << '/' << setw(2) << month << '/' << setw(4) << year;
        return oss.str();
    }
    void display() const {
        cout << this->toString() << endl;
    }
    // Set date while maintaing class invariant
    bool setDay(const int& d) {
        if (d <= getDayInMonth(month, year) && d >= 1) {
            day = d;
            return true;
        } else {
            cout << "Invalid day..." << endl;
            return false;
        }
    }
    bool setMonth(const int& m) {
        if (m >= 1 && m <= 12 && day <= getDayInMonth(m, year)) {
            month = m;
            return true;
        } else {
            cout << "Invalid month..." << endl;
            return false;
        }
    }
    bool setYear(const int& y) {
        if (y > 0) {
            year = y;
            return true;
        }
        return false;
    }
    // Set date with validation
    bool setDate(const int& d, const int& m, const int& y) {
        if (!isValidDate(d, m, y)) {
            cout << "Invalid date..." << endl;
            return false;
        } else {
            day = d;
            month = m;
            year = y;
            return true;
        }
    }
    // Add date with class invariant
    void addDays(const int& d) {
        if (d < 0) {
            cout << "Invalid number of days..." << endl;
            return;
        }
        day += d;
        while (day > getDayInMonth(month, year)) {
            day -= getDayInMonth(month, year);
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
    void addMonths(const int& m) {
        if (m < 0) {
            cout << "Invalid number of months..." << endl;
            return;
        }
        month += m;
        while (month > 12) {
            month -= 12;
            year++;
        }
        int maxDays = getDayInMonth(month, year);
        if (day > maxDays) {
            day = maxDays;
        }
    }
    void addYears(const int& y) {
        if (y < 0) {
            cout << "Invalid number of years..." << endl;
            return;
        }
        year += y;
        if (month == 2 && day == 29 && !isLeapYear(year)) {
            day = 28;
        }
    }
    // Validity check for date
    bool isValid() const {
        return isValidDate(day, month, year);
    }
    // Number of days in a year
    int dayOfYear() const {
        int m = 1;
        int days = this->day;
        while (m < this->month) {
            days += getDayInMonth(m++,year);
        }
        return days;
    }
};

int main() {
    // TODO: Test date validation and operations

    cout << "\n===Class Invariants Example===" << endl;

    Date date1(15, 6, 2023);
    cout << "Date 1: ";
    date1.display();
    cout << "(Valid: " << date1.isValid() << ")" << endl;

    Date date2(2, 5, 2020);
    cout << "Date 2: ";
    date2.display();
    date2.addDays(500);
    cout << "Adding 500 days to Date 2: ";
    date2.display();
    cout << "(Valid: " << date1.isValid() << ")" << endl;

    return 0;
}
