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

class Employee {
private:
    double salary;
    int id;

protected:
    string department;

public:
    string name;

    // Constructor & destructor
    Employee(const string& name = "", const int& id = 0, const string& dep = "",
             const double& salary = 0.0)
        : salary(salary), id(id), department(dep), name(name) {
        cout << "===Object created===" << endl;
        cout << "ID: " << id << endl;
    }
    ~Employee() {}
    // Getters & Setters;
    int getId() const {
        return id;
    }
    double getSalary() const {
        return salary;
    }
    string getDepartment() const {
        return department;
    }
    void setDepartment(const string& dep) {
        this->department = dep;
    }
    void setSalary(const double& salary) {
        if (salary > 0.0)
            this->salary = salary;
    }
    // Utilities
    void displayInfo() const {
        cout << "\n===Employee Info===" << endl;
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    // TODO: Show how encapsulation protects data

    Employee e1;
    Employee e2("John Smith", 80005, "hardware", 500.55);
    e1.displayInfo();
    e2.displayInfo();

    return 0;
}
