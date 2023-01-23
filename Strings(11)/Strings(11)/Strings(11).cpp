#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int find(char* str, int n, char x) {
    for (int i = 0; i < n; i++)
        if (str[i] == x)
            return i;
    return -1;
}

void removeChar(char* str, int* n, int index) {
    char x = str[index];
    while ((index = find(str, *n, x)) != -1)
    {
        for (int i = index; i < *n; i++)
        {
            str[i] = str[i + 1];
        }
        (*n)--;
    }
}


class String {
public:
    char* str;
    int length;

    String() {}

    String(char* _str, int _l) {
        str = new char[_l+1];
        memcpy(str, _str, _l + 1);
        length = _l;
    }
    String(const String & _otherStr) {
        str = new char[_otherStr.length+1];
        length = _otherStr.length;
        memcpy(str, _otherStr.str, length+1);
    }
    ~String() { 
        delete[] str;
    }

    String& operator -(const String _right) {
        
        try {
            // hel - lohh = o

            int llength = length;
            char* left = new char[llength+1];
            memcpy(left, str, llength+1);

            for (int i = 0; i < _right.length; i++)
            {
                char fd = _right.str[i];
                for (int j = 0; j < llength; j++)
                {
                    if (left[j] == fd)
                    {
                        removeChar(left, &llength, j);
                    }
                }
            }
            
            String* tmp = new String(left, llength);
            return *tmp;
        }
        catch (...) {
            cerr << "Bad arguments" << endl << endl;
        }

    }
};




int main() {
    char* str1 = new char[5] { 'm', 'a', 'm', 'a', '\0'};
    char* str2 = new char[2] { 'a', '\0'};

    String a(str1, 4);
    String b(str2, 1);

    String c = a - b;


    cout << c.str;

    return 0;
}
