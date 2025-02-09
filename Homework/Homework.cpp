//1
#include <iostream>
#include <string>

using namespace std;

enum Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {
    int i;

    while (true) {
        cout << "Enter the month number: ";
        cin >> i;

        if (i == 0) {
            cout << "Bye bye!" << endl;
            break;
        }

        Month month = static_cast<Month>(i);

        switch (month) {
        case January:   cout << "January" << endl; break;
        case February:  cout << "February" << endl; break;
        case March:     cout << "March" << endl; break;
        case April:     cout << "April" << endl; break;
        case May:       cout << "May" << endl; break;
        case June:      cout << "June" << endl; break;
        case July:      cout << "July" << endl; break;
        case August:    cout << "August" << endl; break;
        case September: cout << "September" << endl; break;
        case October:   cout << "October" << endl; break;
        case November:  cout << "November" << endl; break;
        case December:  cout << "December" << endl; break;
        default:
            cout << "Try again!" << endl;
            break;
        }
    }

    return 0;
}

//2

/*struct Bank {
    int id;
    string name;
    double money;
};
void  updateMoney(Bank& account, double newmoney) {
    account.money = newmoney;
}

int main() {
    Bank account;

    cout << "Enter account number:";
    cin >> account.id;

    cout << "Enter owner name:";
    cin >> account.name;

    cout << "Enter balance:";
    cin >> account.money;

    double newmoney;
    cout << "Enter new balance:";
    cin >> newmoney;

    updateMoney(account, newmoney);

    cout << "Your account: " << account.name << ", " << account.id << ", " << account.money;

    return 0;
}*/

//3 

/*struct Address {
    string city;
    string street;
    int houseNumber;
    int apartmentNumber;
    int id;
};


void printAddress(const Address& addr) {
    cout << "\nCity: " << addr.city << endl;
    cout << "Street: " << addr.street << endl;
    cout << "House number: " << addr.houseNumber << endl;
    cout << "Apartment number: " << addr.apartmentNumber << endl;
    cout << "Postal code: " << addr.id << endl;
}

int main() {
    Address address1, address2;

    cout << "Enter house number: ";
    cin >> address1.houseNumber;
    cin.ignore(); 

    cout << "Enter city: ";
    getline(cin, address1.city);

    cout << "Enter street: ";
    getline(cin, address1.street);

    cout << "Enter apartment number: ";
    cin >> address1.apartmentNumber;

    cout << "Enter index: ";
    cin >> address1.id;
    cin.ignore(); 

    cout << "\nEnter house number: ";
    cin >> address2.houseNumber;
    cin.ignore(); 

    cout << "Enter city: ";
    getline(cin, address2.city);

    cout << "Enter street: ";
    getline(cin, address2.street);

    cout << "Enter apartment number: ";
    cin >> address2.apartmentNumber;

    cout << "Enter index: ";
    cin >> address2.id;

  
    cout << "\nAddress details:\n";
    printAddress(address1);
    printAddress(address2);

    return 0;
}*/
