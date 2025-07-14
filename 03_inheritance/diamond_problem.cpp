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

    // Getters
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }

    virtual void displayInfo() const {
        cout << "<--Person Info-->" << endl;
        cout << "Person Name: " << name << endl;
        cout << "Person Age: " << age << endl;
    }
};

class Student : public Person {
private:
    string studentId;

public:
    Student(string name = "", int age = 0, string studentId = 0)
        : Person(name, age), studentId(studentId) {
        cout << "Student Constructro..." << endl;
    }
    virtual ~Student() {
        cout << "Student Destructor..." << endl;
    }

    // Getter
    string getStudentId() const {
        return studentId;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "\n<--Student Info-->" << endl;
        cout << "Student Id: " << studentId << endl;
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

    // Getter
    string getSubject() const {
        return subject;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "\n<--Teacher Info-->" << endl;
        cout << "Teacher Subject: " << subject << endl;
    }
};

class TeachingAssistant : public Student, public Teacher {
public:
    TeachingAssistant(string name = "", int age = 0, string studentId = "", string subject = "")
        : Student(name, age, studentId), Teacher(name, age, subject) {
        cout << "TeachingAssistant Constructor..." << endl;
    }
    ~TeachingAssistant() {
        cout << "TeachingAssistant Desturctor..." << endl;
    }

    void displayInfo() const override {
        Student::displayInfo();
        Teacher::displayInfo();
    }
};

int main() {
    // TODO: Demonstrate diamond problem and solution

    cout << "\n===Diamond Problem Demonstration===\n" << endl;

    TeachingAssistant ta("Alice", 25, "ST001", "Computer Science");
    // cout << "Name: " << ta.getName() << endl;  // Compilation erro due to ambiguity
    cout << "\nName: " << ta.Student::getName() << endl;
    ta.displayInfo();

    return 0;
}
