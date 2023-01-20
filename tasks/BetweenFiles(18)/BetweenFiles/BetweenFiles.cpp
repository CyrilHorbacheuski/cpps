#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdio.h>

using namespace std;

#define FileFrom "from.txt";
#define FileInto "into.txt";


class SingleBook {
public:
	string name;
	string author;
	int year;

	SingleBook(string _n, string _a, int _y) {
		name = _n;
		author = _a;
		year = _y;
	}
	SingleBook() {}
	~SingleBook() {}


};

class AllBooks {
public:
	vector<SingleBook> books;
	int countOfWinterDatesValue = 0;

	AllBooks() {}
	~AllBooks() {}

	void rewrite() {
		ofstream fin("into.txt");

		if (fin.bad() || !fin.is_open()) {
			fin.close();

			return;
		}

		int userYearValue;

		cout << "Enter year: ";
		cin >> userYearValue;

		for (int i = 0; i < books.size(); i++) {
			if (books[i].year > userYearValue) 
				fin << books[i].name << endl << books[i].author << endl << books[i].year << endl << endl;
		}
		
		fin.close();
	}


	void getBooksFromFile() {
		ifstream fin("from.txt");

		if (fin.bad() || !fin.is_open()) {
			fin.close();

			return;
		}

		books.clear();

		while (!fin.eof()) {

			SingleBook t;

			string tmpYear;
			string emptyStr;


			if (!getline(fin, t.name) ||
				!getline(fin, t.author) ||
				!getline(fin, tmpYear))
				break;

			t.year = stoi(tmpYear);

			books.push_back(t);
			getline(fin, emptyStr);
		}

		fin.close();
	}
};


AllBooks box;

bool main() {

	box.getBooksFromFile();
	box.rewrite();

	return false;
}
