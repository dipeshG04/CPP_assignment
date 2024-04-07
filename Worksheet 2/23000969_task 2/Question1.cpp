#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int area() const {
        return width * height;
    }

    bool isSquare() const {
        return width == height;
    }
};

Rectangle inputRectangle() {
    int width, height;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    return Rectangle(width, height);
}

int main() {

    cout << "Enter dimensions for rectangle 1:" << endl;
    Rectangle rect1 = inputRectangle();

    cout << "Enter dimensions for rectangle 2:" << endl;
    Rectangle rect2 = inputRectangle();

    int area1 = rect1.area();
    int area2 = rect2.area();

    cout << "Area of rectangle 1: " << area1 << endl;
    cout << "Area of rectangle 2: " << area2 << endl;

    cout << "Is rectangle 1 a square? " << (rect1.isSquare() ? "Yes" : "No") << endl;
    cout << "Is rectangle 2 a square? " << (rect2.isSquare() ? "Yes" : "No") << endl;

    return 0;
}
