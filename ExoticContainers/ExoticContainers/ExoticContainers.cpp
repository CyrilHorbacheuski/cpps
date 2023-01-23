#include <iostream>
#include <map>
#include <set>
#include <deque>
#include <list>

using namespace std;

int main() {
    map <string, int> mp = {
        {"five", 5},
        {"seven", 7},
        {"zero", 0}
    };
    map <string, int>::iterator it = mp.begin();

    cout << "[ Map container: ]" << endl << endl;
    for (int i = 0; it != mp.end(); it++, i++) {
        cout << "key: " << it->first << ", value: " << it->second << " | ";
    }



    multimap <string, int> mm = {
        {"five", 5},
        {"zero", 0},
        {"seven", 7},
        {"zero", 0} // not error
    };
    multimap <string, int>::iterator mmi = mm.begin();

    cout << "\n\n\n" << "[ Multimap container: ]" << endl << endl;
    for (int i = 0; mmi != mm.end(); mmi++, i++) {
        cout << "key: " << mmi->first << ", value: " << mmi->second << " | ";
    }




    set <int, greater<int>> setCont;
    setCont.insert(20);
    setCont.insert(7);
    setCont.insert(19);
    setCont.insert(0);
    setCont.insert(0);
    set <int>::iterator sc = setCont.begin();

    cout << "\n\n\n" << "[ Set container: ]" << endl << endl;
    for (sc = setCont.begin(); sc != setCont.end(); sc++) {
        cout << *sc << " | ";
    }




    multiset <int> mulstisetCont{ 1,2,-5,6,9,2,0,-5 };
    set <int>::iterator msc = mulstisetCont.begin();

    cout << "\n\n\n" << "[ Multiset container: ]" << endl << endl;
    for (int i = 0; msc != mulstisetCont.end(); msc++, i++) {
        cout << *msc << " | ";
    }




    cout << "\n\n\n" << "[ List container: ]" << endl << endl;
    list <int> l{ 4, 6, 3, 2 };
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " | "));
    l.sort(); 
    cout << endl << endl << "Sorted: ";
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " | "));


    return 0;
}
