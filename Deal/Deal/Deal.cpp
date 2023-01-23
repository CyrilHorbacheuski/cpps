#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    double price;

public:
    string name;

    Product() {}
    Product(double _p, string _n) {
        price = _p;
        name = _n;
    }
    ~Product() {}

    double getTotalPrice(int countOfProducts) {
        return price * countOfProducts;
    }
};

class BankAccount {
protected:
    double amountOnAccount;
    string number;

public:

    BankAccount() {}
    BankAccount(double _a, string _n) {
        amountOnAccount = _a;
        number = _n;
    }
    ~BankAccount() {}

    void checkMoney() {
        cout << endl << "Remaining funds: " << amountOnAccount;
    }

    friend void bueSomeProducts(Product& p, BankAccount& b, int count);
};
void bueSomeProducts(Product& p, BankAccount& b, int count) {
    if (b.amountOnAccount > p.getTotalPrice(count)) {
        cout << endl << "You bought " << count << " " << p.name;
        b.amountOnAccount -= p.getTotalPrice(count);
        
    }
    else cout << endl << "Insufficient funds to buy " << count << " " << p.name << endl;
}


int main() {
    Product milk(6.15, "milk");
    BankAccount Albert(978.89, "FP15987564213");

    Product car(900, "car");

    bueSomeProducts(milk, Albert, 12);
    bueSomeProducts(car, Albert, 2);
    bueSomeProducts(car, Albert, 1);

    Albert.checkMoney();

    return 0;
}
