#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

template <typename T>
class VectorClass {
public:
	vector<T> array;

	VectorClass(vector<T> _array) {
		array = _array;
	}

	~VectorClass() {}

	void push(T value) {
		array.push_back(value);
	}
	void print() {
		for (int i = 0; i < array.size(); i++) {
			cout << i + 1 << ") " << array[i] << endl;
		}
		cout << endl << endl;
	}
	VectorClass operator + (VectorClass s) {
		int exitConditionValue = array.size() > s.array.size() ? s.array.size() : array.size();

		if (sizeof(T) == sizeof(int)) {
			cout << "int: " << endl;
			
			for (int i = 0; i < exitConditionValue; i++) {
				array[i] += s.array[i];
			}
		}
		if(sizeof(T) == sizeof(string)) {
			cout << "string: " << endl;

			for (int i = 0; i < exitConditionValue; i++) {
				array[i] += s.array[i];
			}
		}
		if (sizeof(T) == sizeof(bool)) {
			cout << "bool: " << endl;

			for (int i = 0; i < exitConditionValue; i++) {
				array[i] = array[i] + s.array[i];
			}
		}

		return array;
	}
};


int main() {

	vector<int> arg1 = { 3, 1, -2, -4, 19 };
	vector<int> arg2 = { 7, 9, 12, 14, -9, 1, 1 };

	vector<string> arg3 = { "sdg", "hah", "mama", "idi" };
	vector<string> arg4 = { "abc", "loh" };

	vector<bool> arg5 = { true, false, true, false, false, true };
	vector<bool> arg6 = { false, true, true, false, true };

	VectorClass<int> a(arg2);
	VectorClass<int> b(arg1);

	VectorClass<string> as(arg3);
	VectorClass<string> bs(arg4);

	VectorClass<bool> ab(arg5);
	VectorClass<bool> bb(arg6);


	VectorClass<int> c = a + b;
	c.print();

	VectorClass<string> cs = as + bs;
	cs.print();

	//VectorClass<bool> cb = ab + bb;
	//cb.print();

	return 0;
}