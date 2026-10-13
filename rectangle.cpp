#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;
    double length;

public:
    // Default constructor
    Rectangle() : width(0.0), length(0.0) {}

    // Parameterized constructor
    Rectangle(double w, double l) : width(0.0), length(0.0)
    {
        setWidth(w);
        setLength(l);
    }

    // Setters (reject negative values)
    void setWidth(double w)
    {
        if (w >= 0)
        {
            width = w;
        }
        else
        {
            cout << "Invalid width. Must be non-negative." << endl;
        }
    }

    void setLength(double l)
    {
        if (l >= 0)
        {
            length = l;
        }
        else
        {
            cout << "Invalid length. Must be non-negative." << endl;
        }
    }

    // Getters
    double getWidth() const { return width; }
    double getLength() const { return length; }

    // Calculations
    double calculateArea() const { return width * length; }
    double calculatePerimeter() const { return 2 * (width + length); }
};

int main()
{
    // Example 1: default constructor, then set dimensions
    Rectangle rect1;
    rect1.setWidth(5.0);
    rect1.setLength(10.0);

    cout << "Rectangle 1" << endl;
    cout << "Width: " << rect1.getWidth() << endl;
    cout << "Length: " << rect1.getLength() << endl;
    cout << "Area: " << rect1.calculateArea() << endl;
    cout << "Perimeter: " << rect1.calculatePerimeter() << endl;
    cout << endl;

    // Example 2: parameterized constructor
    Rectangle rect2(3.5, 7.2);

    cout << "Rectangle 2" << endl;
    cout << "Width: " << rect2.getWidth() << endl;
    cout << "Length: " << rect2.getLength() << endl;
    cout << "Area: " << rect2.calculateArea() << endl;
    cout << "Perimeter: " << rect2.calculatePerimeter() << endl;
    cout << endl;

    return 0;
}
