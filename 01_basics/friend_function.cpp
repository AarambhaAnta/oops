// Friend functions and classes
// Problem: Access private members from outside the class

#include <iostream>
using namespace std;

// TODO: Create a Rectangle class with:
// - Private width and height
// - Friend function to calculate area
// - Friend class that can access private members
// - Demonstrate friend functionality

class RectangleHelper;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(const double& w = 0.0, const double& h = 0.0) : width(w), height(h) {}
    ~Rectangle() {}

    // getters
    double getWidth() const {
        return width;
    }
    double getHeight() const {
        return height;
    }

    // friend zone
    friend double calculateArea(const Rectangle& rect);
    friend RectangleHelper;
    friend void displayInfo(const Rectangle& rect);
};

double calculateArea(const Rectangle& rect) {
    return rect.width * rect.height;
}

class RectangleHelper {
private:
public:
    double calculatePerimeter(const Rectangle& rect) {
        return 2 * (rect.width + rect.height);
    }
    void scale(Rectangle& rect, const double& fact) {
        rect.width *= fact;
        rect.height *= fact;
    }
};

void displayInfo(const Rectangle& rect) {
    cout << "\n===Rectangle===" << endl;
    cout << "Height: " << rect.getHeight() << endl;
    cout << "Width: " << rect.getWidth() << endl;
    cout << "Area: " << calculateArea(rect) << endl;
    RectangleHelper helper;
    cout << "Perimeter: " << helper.calculatePerimeter(rect) << endl;
}

int main() {
    // TODO: Use friend functions and classes

    Rectangle rect1;
    displayInfo(rect1);

    Rectangle rect2(5.0,3.4);
    displayInfo(rect2);

    

    return 0;
}
