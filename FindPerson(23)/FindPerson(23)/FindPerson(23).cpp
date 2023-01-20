#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;


struct employee {
	string firstname;
	string secondname;
	string phone;
};

class AllRecords {
public:
	vector<employee> records;

	AllRecords() {}
	~AllRecords() {}

	void findRecordBy(string _phoneOrSecondname) {
		for (int i = 0; i < records.size(); i++) {
			if (records[i].phone == _phoneOrSecondname || records[i].secondname == _phoneOrSecondname) {
				cout << endl << endl << "Was found: " << records[i].firstname << endl << records[i].secondname << endl << records[i].phone << endl;
			}
		}
	}
};

AllRecords box;

class BinaryFile {
public:
	string filename = "persons.b";
    ifstream f_in;
    ofstream f_out;
    fstream filestream;

	BinaryFile() {}
	~BinaryFile() {}

    void getRecordsFromFile() {
		f_in.open(filename, ios::binary);

		if (f_in.bad() || !f_in.is_open()) {
			f_in.close();

			return;
		}

		employee t;
		string emptyStr;

		box.records.clear();

		while (getline(f_in, t.firstname, '\r')) {
			if (f_in.eof())
				break;

			f_in.get();
			getline(f_in, t.secondname, '\r');

			f_in.get();
			getline(f_in, t.phone, '\r');

			box.records.push_back(t);

			f_in.get();
			getline(f_in, emptyStr, '\r');
			f_in.get();
		}

		f_in.close();
    }

	friend class AllRecords;
};



int main() {
	BinaryFile file;
	file.getRecordsFromFile();

	string val;
	cout << "Enter secondname or phone number: ";
	cin >> val;

	box.findRecordBy(val);


    return 0;
}


