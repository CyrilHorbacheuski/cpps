#include <iostream>

#define M_PI 3.14159265358979323846

using namespace std;

class A {
public:
    int x1;
    int y1;

    A(int _x1, int _y1) {
        x1 = _x1;
        y1 = _y1;
    }
    ~A() {}
};

class B: public A  {
public:
    int x2;
    int y2;

    B(int _x1, int _y1, int _x2, int _y2): A(_x1, _y1) {
        x2 = _x2;
        y2 = _y2;
    }
    ~B() {}

    float squarArea() {
        return (pow(x1 - x2, 2) + pow(y1 - y2, 2)) / 2;
    }
};

class C : public B {
public:
    int x3;
    int y3;

    C(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3) : B(_x1, _y1, _x2, _y2) {
        x3 = _x3;
        y3 = _y3;
    }
    ~C() {}

    float parallelepipedVolume() {
        return this->squarArea()*(x3 - x1);
    }
};


int main() {

    C paralel(2, 2, 6, 2, 5, 4);
    
    cout << "Volume: " << paralel.parallelepipedVolume() << endl << endl;


    return 0;
}


