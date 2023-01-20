#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdio.h>

using namespace std;


class SingleDate {
public:
	string month;
	string day;
	string year;

	SingleDate(string _d, string _m, string _y) {
		month = _m;
		day = _d;
		year = _y;
	}
	SingleDate() {}
	~SingleDate() {}


};

class Dates {
public:
	vector<SingleDate> dates;
	int countOfWinterDatesValue = 0;

	Dates() {}
	~Dates() {}

	int countOfWinterDates() {
        for(int i = 0; i < dates.size(); i++) {
            if((dates[i].month)[1] == '3' || dates[i].month[1] == '4' || dates[i].month[1] == '5')
                countOfWinterDatesValue++;
        }
        return countOfWinterDatesValue;
	}



	void getDatesFromFile() {
		ifstream fin("dates.txt");

		if (fin.bad() || !fin.is_open()) {
			fin.close();
			
			return;
		}

		dates.clear();

		while (!fin.eof()) {
		    
			SingleDate t;
			string emptyStr;

			
			if (!getline(fin, t.day) ||
				!getline(fin, t.month) ||
				!getline(fin, t.year))
				break;

			dates.push_back(t);
			getline(fin, emptyStr);
		}

		fin.close();
	}
};


Dates cont;

bool main() {
    
    cont.getDatesFromFile();
    
    cout << "Winter's days count = " << cont.countOfWinterDates();
	
	return false;
}