#include <iostream>

using namespace std;

template<class T>
class CustomVector {
public:
    T* array;
    int length;

    class Iterator {
    public:
        Iterator(T* curr) :current(curr) {}

        Iterator& operator =(const Iterator& other) {
            if (this != &other)
                current = other.current;

            return *this;
        }
        Iterator& operator ++() {
            ++current;
            return *this;
        }

        Iterator operator ++(int i) {
            Iterator tmp(current);
            ++current;

            return tmp;
        }

        friend bool operator == (const Iterator& a, const Iterator& b) {
            return a.current == b.current;
        }
        friend bool operator != (const Iterator& a, const Iterator& b) {
            return a.current != b.current;
        }

        T& operator *() {
            return *current;
        }

        T* operator ->() {
            return current;
        }

    private:
        T* current;
    };


    CustomVector(int _first) {
        array = new int[1];
        array[0] = _first;
        length = 1;
    }

    void pushBack(const int& value) {
        int* tmp = array;
        array = new int[length + 1];

        for (int i = 0; i < length; i++) array[i] = tmp[i];

        array[length++] = value;
    }
    void remove(int index) {
        for (int i = index + 1; i < length; ++i) {
            array[i - 1] = array[i];
        }
        --length;
    }
    int maxNumber() {
        int max = array[0];

        for (int i = 0; i < length; ++i) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        return max;
    }

    Iterator begin() {
        return Iterator(array);
    }

    Iterator end() {
        return Iterator(array+length);
    }
};


int main() {
    CustomVector<int> vect(5);

    vect.pushBack(-100);
    vect.pushBack(3);
    vect.pushBack(25);
    vect.remove(2);
    vect.pushBack(58);
    vect.pushBack(0);

    for (auto a: vect) {
        cout << a << " | ";
    }

    cout << "\n\n" << "Max number in array is: " << vect.maxNumber();
    
    return 0;
}
