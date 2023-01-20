#include <iostream>
#include <string>

using namespace std;

template<typename T>
class CustomString {
public:
    T value;

    CustomString(T _val) {
        value = _val;
    }
    CustomString(const CustomString &_arg) { // copy constructor
        this->value = _arg.value;
    }
  
    CustomString() {} // default constructor
    ~CustomString() {}

    void operator() (T _v) { // override initialize operator
        value = _v;
    }

    void print() {
        cout << value << endl;
    }
};


int main() {

    string arg = "Hello, friend";
    string argTwo = "bad void";

    CustomString<string> *ex = new CustomString<string>(arg);
    CustomString<string> *exTwo = new CustomString<string>(argTwo);
    CustomString<string> copy = *ex;

    ex->print();
    exTwo->print();
    copy.print();

    return 0;
}
