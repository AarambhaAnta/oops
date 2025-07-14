// Diamond problem and virtual inheritance
// Problem: Resolve ambiguity in diamond inheritance

#include <iostream>
#include <string>
using namespace std;

// TODO: Create diamond inheritance problem:
// - Base: Person (name, age)
// - Derived: Student (studentId), Teacher (subject)
// - Multiple derived: TeachingAssistant (from both)
// - Show diamond problem
// - Solve using virtual inheritance

class Person {
private:
    string name;
    int age;

public:
    Person(string name = "", int age = 0) : name(name), age(age) {
        cout << "Person Constructor..." << endl;
    }
    virtual ~Person() {
        cout << "Person Destructor..." << endl;
    }
};

class Student : public Person {
private:
    int studentId;

public:
    Student(string name = "", int age = 0, int studentId = 0)
        : Person(name, age), studentId(studentId) {
        cout << "Student Constructro..." << endl;
    }
    virtual ~Student() {
        cout << "Student Destructor..." << endl;
    }
};

class Teacher : public Person {
private:
    string subject;

public:
    Teacher(string name = "", int age = 0, string subject = "")
        : Person(name, age), subject(subject) {
        cout << "Teacher Constructor..." << endl;
    }
    virtual ~Teacher() {
        cout << "Teacher Destructor..." << endl;
    }
};

class TeachingAssistant {};

int main() {
    // TODO: Demonstrate diamond problem and solution
    return 0;
}
