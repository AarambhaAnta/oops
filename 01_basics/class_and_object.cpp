// Basic class and object implementation
// Problem: Create a simple class with attributes and methods

#include <iostream>
#include <string>
using namespace std;

// TODO: Implement a Student class with:
// - Private attributes: name, age, grade
// - Public methods: setters, getters, displayInfo()
// - Constructor and destructor

class Student {
private:
    string name;
    int age;
    double grade;

public:
    // Default constructor
    Student() : name(""), age(0), grade(0.0) {
        cout << "Student object created with default constructor" << endl;
    }

    // Parameterized constructor
    Student(string name, int age, double grade) : name(name), age(age), grade(grade) {
        cout << "Student object created: " << name << endl;
    }

    // Destructor
    ~Student() {
        cout << "Student object destroyed: " << name << endl;
    }

    // Getters
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    double getGrade() const {
        return grade;
    }

    // Setters
    void setName(string name) {
        this->name = name;
    }
    void setAge(int age) {
        if (age < 0) {
            cout << "Invalid age..." << endl;
            return;
        }
        this->age = age;
    }
    void setGrade(double grade) {
        if (grade < 0.0 || grade > 100.0) {
            cout << "Invalid grade..." << endl;
            return;
        }
        this->grade = grade;
    }

    // Display info
    void displayInfo() const {
        cout << "Student Info:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    // TODO: Create objects and demonstrate basic functionality

    cout << "===Student class Demo===" << endl;

    Student s1;
    Student s2("Alice", 20, 80.5);

    s1.setName("Bob");
    s1.setAge(22);
    s1.setGrade(92.0);

    cout << "\nStudent 1:" << endl;
    s1.displayInfo();

    cout << "\nStudent 2:" << endl;
    s2.displayInfo();

    cout << "\nTesting getters:" << endl;
    cout << "Student 1 name: " << s1.getName() << endl;
    cout << "Student 2 grade: " << s2.getGrade() << endl;

    return 0;
}
