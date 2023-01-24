#include <iostream>

using namespace std;

template<class T>
class Matrix {
public:
    int columnsCount;
    int rowsCount;

    T** value;


    Matrix(int n, int m) {
        rowsCount = n;
        columnsCount = m;

        value = new T * [n];
        for (int i = 0; i < n; i++)
            value[i] = new T[m];
    }
    Matrix() {}
    ~Matrix() {}

    Matrix<T> operator + (const Matrix<T>& obj)
    {
        if (rowsCount != obj.rowsCount || columnsCount != obj.columnsCount)
            return Matrix<T>();

        Matrix<T> tmp(rowsCount, columnsCount);

        for (int i = 0; i < rowsCount; i++)
            for (int j = 0; j < columnsCount; j++)
                tmp.value[i][j] = value[i][j] + obj.value[i][j];

        return tmp;
    }

    void checkMatrix() {
        for (int i = 0; i < rowsCount; i++) {
            cout << endl;
            for (int j = 0; j < columnsCount; j++) {
                cout << value[i][j] << " | ";
            }
        }
        cout << endl;
    }
};

int main() {
    Matrix<int> a(5, 5);
    Matrix<int> b(5, 5);

    for (int i = 0; i < a.columnsCount; i++)
        for (int j = 0; j < a.rowsCount; j++)
            a.value[i][j] = 1;

    for (int i = 0; i < b.columnsCount; i++)
        for (int j = 0; j < b.rowsCount; j++)
            b.value[i][j] = 2;

    a.checkMatrix();
    b.checkMatrix();

    
    Matrix<int> c = a + b;
    c.checkMatrix();

    return 0;
}
