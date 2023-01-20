#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

#define Error "ERROR"

class ForString {
public:
    string value;

    ForString() {}
    ForString(string _v) {
        value = _v;
    }
    ForString(const ForString  &_arg) {
        this->value = _arg.value;
    }
    ~ForString() {}

    ForString operator -(ForString _right) {
        try {
            int lengthCondition;

            if (value.length() > _right.value.length()) {
                lengthCondition = _right.value.length();
            }
            else {
                throw true;
            }

            value.erase(value.find(_right.value), lengthCondition);

            return value;
        }
        catch (...) {
            cerr << "Bad arguments" << endl << endl;
            return value;
        }

        
    }

    void print() {
        cout << this->value << endl;
    }
};

int main() {
    ForString a("mama");
    ForString b("mamamia");

    ForString c = b; // use copy constructor

    ForString bad = a - b; // exception will be thrown
    bad.print();

    ForString good = c - a; // all good
    good.print();


    return 0;
}
