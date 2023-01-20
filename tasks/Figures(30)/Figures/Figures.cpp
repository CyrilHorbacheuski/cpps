#include <iostream>

#define M_PI 3.14159265358979323846

using namespace std;

class Point {
public:
    int x;
    int y; 

    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    ~Point() {}

    virtual float area() = 0;
};

class Circle: Point {
public: 
    int radius;

    Circle(int _x, int _y, int _radius): Point(_x, _y) {
        radius = _radius;
    }
    ~Circle() {}

    float area() override {
        return M_PI * pow(radius, 2);
    }
};

class Cylinder: Circle {
public:
    int height;

    Cylinder(int _x, int _y, int _radius, int _height): Circle(_x, _y, _radius) {
        height = _height;
    }
    ~Cylinder() {}

    float volume() {
        return M_PI * pow(radius, 2)*height;
    }
    float area() override {
        return 2*M_PI *radius*(height + radius);
    }
};

int main() {

    Circle c(2, 5, 17);
    cout << "Circle area: " << c.area() << endl << endl;

    Cylinder cyl(2, 5, 17, 20);
    cout << "Cylinder area: " << cyl.area() << endl << "Cylinder volume: " << cyl.volume() << endl << endl;


    return 0;
}

