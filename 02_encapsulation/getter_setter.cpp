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
    const double minValidPrice = 0.01;
    const double epsilon = 1e-3;

public:
    // Constructor & Destructor
    Product(const string& name = "", const double& price = 0.0, const int& stock = 0)
        : name(name), price(price), stock(stock) {}
    ~Product() {}

    // Getter
    string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }
    int getStock() const {
        return stock;
    }

    // Setters with validation
    bool setName(const string& name) {
        if (!name.empty()) {
            this->name = name;
            return true;
        }
        return false;
    }
    bool setPrice(const double& price) {
        if (price >= minValidPrice) {
            this->price = price;
            return true;
        }
        return false;
    }
    bool setStock(const int& stock) {
        if (stock >= 0) {
            this->stock = stock;
            return true;
        }
        return false;
    }

    // Business Method
    bool buyProduct(const int& quantity) {
        if (quantity > 0) {
            stock += quantity;
            return true;
        }
        return false;
    }
    bool sellProduct(const int& quantity) {
        if (quantity <= stock) {
            stock -= quantity;
            return true;
        }
        return false;
    }
    void displayProduct() const {
        cout << "\n===Product Description===" << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << stock << endl;
    }

    // Utility Method
    double getTotalValue() {
        return stock * price;
    }
    bool isInStock() const {
        return stock > 0;
    }
};

int main() {
    // TODO: Test getter/setter validation

    Product p1;
    Product p2("item", 5.5, 10);
    p1.displayProduct();
    p2.displayProduct();

    cout << "\nTotal Inventry Cost: " << p2.getTotalValue() << endl;

    p1.setName("prod");
    p1.setPrice(3.5);
    p1.buyProduct(10);
    p1.displayProduct();

    return 0;
}
