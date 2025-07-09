// Getter and Setter methods
// Problem: Provide controlled access to private data

#include <iostream>
#include <string>
using namespace std;

// TODO: Create a Product class with:
// - Private: price, stock
// - Getters that return values
// - Setters with validation (price > 0, stock >= 0)
// - Methods to buy/sell products
// - Demonstrate controlled access

class Product {
private:
    string name;
    double price;
    int stock;

public:
    // Constructor & Destructor
    Product(const string& name = "", const double& price = 0.0, const int& stock = 0)
        : name(name), price(price), stock(stock) {}
    // Getter & Setter

    // Utilities
};

int main() {
    // TODO: Test getter/setter validation
    return 0;
}
