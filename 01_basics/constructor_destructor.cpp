// Constructor and Destructor demonstration
// Problem: Understand object lifecycle and initialization

#include <iostream>
#include <string>
using namespace std;

// TODO: Create a BankAccount class with:
// - Default constructor
// - Parameterized constructor
// - Copy constructor
// - Destructor
// - Demonstrate different ways to create objects

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    // Default constructor
    BankAccount() : accountNumber(""), accountHolder(""), balance(0.0) {
        cout << "Object created with default constructor." << endl;
    }

    // Parameterized constructor
    BankAccount(string acNum, string acHold, double balance)
        : accountNumber(acNum), accountHolder(acHold), balance(balance) {
        cout << "Object created: " << accountNumber << endl;
    }

    // Copy constructor
    BankAccount(const BankAccount& other)
        : accountNumber(other.accountNumber), accountHolder(other.accountHolder),
          balance(other.balance) {
        cout << "Object created with copy constructor" << endl;
    }

    // Destructor
    ~BankAccount() {
        cout << "Object destroyed: " << accountNumber << endl;
    }

    // Getters
    string getAccountNumber() const {
        return accountNumber;
    }
    string getAccountHolder() const {
        return accountHolder;
    }
    double getBalance() const {
        return balance;
    }

    // Display Info
    void displayInfo() const {
        cout << "\n===Account details===" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Balance: " << balance << endl;
    }
};

int main() {
    // TODO: Create objects using different constructors

    BankAccount account1;
    account1.displayInfo();

    BankAccount account2("1234", "Aditya Kumar", 50000000.0);
    account2.displayInfo();

    BankAccount account3 = account2;
    account3.displayInfo();

    return 0;
}
