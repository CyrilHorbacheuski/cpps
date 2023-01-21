#include <iostream>

using namespace std;

template<class T>
class Array {
public:
    T* massive;
    int length;

    Array(T* _arg, int _l) {
        massive = _arg;
        length = _l;
    }
    Array(const Array<T> &_arg) { // copy constructor
        for (int i = 0; i < _arg.length; i++)
            addElement(_arg.massive[i]);

        length = _arg.length;
    }
    Array() {}
    ~Array() {}

    Array operator |(Array _rightOperand) { // override arrays concat
        int newLength = length + _rightOperand.length;

        T* newMassive = new T[newLength];

        for (int i = 0; i < length; i++) {
            newMassive[i] = massive[i];
        }
        for (int i = length-1; i < _rightOperand.length; i++) {
            newMassive[i] = _rightOperand.massive[i];
        }
        Array<T> obj;

        obj.massive = newMassive;

        return obj;

    }

    void addElement(T _elem) {
        T* newMassive = new T[length + 1];
        
        for (int i = 0; i < length; i++) {
            newMassive[i] = massive[i];
        }
        newMassive[length++] = _elem;

        massive = newMassive;
    }

    void checkInfo() {
        for (int i = 0; i < length; i++) {
            cout << massive[i] << " | ";
        }
    }

};

int main() {

    int* a1 = new int[0];
    int* a2 = new int[0];

    Array<int> mas1(a1, 0);
    mas1.addElement(5);
    mas1.addElement(-2);

    Array<int> mas2 = mas1; // using copy constructor

    mas1.addElement(6);

    mas2.addElement(1);

    mas1.checkInfo();
    mas2.checkInfo();

    Array<int> masConcat = mas1 | mas2;

    masConcat.checkInfo();

    return 0;
}
