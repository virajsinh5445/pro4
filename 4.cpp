#include <iostream>
#include <string>
#include <limits>

using namespace std;

class BankAccount {
protected:
    int AccountNumber;
    string AccountHolderName;
    int amount;

public:
    void account(int number, const string& name, int amounts) {
        AccountNumber = number;
        AccountHolderName = name;
        amount = amounts;
    }

    void deposit(int depositAmount) {
        amount += depositAmount;
        cout << "Amount added successfully!" << endl;
    }

    void displayAccountInfo() const {
        cout << "Account Number: " << AccountNumber << endl;
        cout << "Account Holder Name: " << AccountHolderName << endl;
        cout << "Account Balance: " << amount << endl;
    }
};

class SavingAccount : public BankAccount {
    int interestrate;

public:
    void saving(int number, const string& name, int amounts, int rate) {
        account(number, name, amounts);
        interestrate = rate;
    }

    void calculateInterest() {
        amount += amount * interestrate / 100;
        cout << "Total Amount with Interest: " << amount << endl;
    }
};

class CheckingAccount : public BankAccount {
    int overdraftlimit;

public:
    void checking(int number, const string& name, int amounts, int limit) {
        account(number, name, amounts);
        overdraftlimit = limit;
    }

    void withdraw(int withdrawamount) {
        if (withdrawamount <= amount + overdraftlimit) {
            amount -= withdrawamount;
            cout << "Withdrawal Successful!" << endl;
            cout << "Remaining Balance: " << amount << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }
};

class FixedDepositAccount : public BankAccount {
    int term; // months

public:
    void fixeddeposit(int number, const string& name, int amounts, int terms) {
        account(number, name, amounts);
        term = terms;
    }

    void calculateInterest() {
        int years = term / 12;
        amount += amount * 7 * years / 100;
        cout << "Total Amount with Interest: " << amount << endl;
    }
};

int main() {
    SavingAccount s;
    CheckingAccount c;
    FixedDepositAccount fd;

    int choice;
    int number, amount, rate, limit, term;
    string name;

    cout << "1. Saving Account\n";
    cout << "2. Checking Account\n";
    cout << "3. Fixed Deposit Account\n";
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter Account Number: ";
    cin >> number;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Account Holder Name: ";
    getline(cin, name);

    cout << "Enter Initial Amount: ";
    cin >> amount;

    if (choice == 1) {
        cout << "Enter Interest Rate: ";
        cin >> rate;
        s.saving(number, name, amount, rate);
        s.displayAccountInfo();
        s.calculateInterest();
    }
    else if (choice == 2) {
        cout << "Enter Overdraft Limit: ";
        cin >> limit;
        c.checking(number, name, amount, limit);
        c.displayAccountInfo();
    }
    else if (choice == 3) {
        cout << "Enter Term (in months): ";
        cin >> term;
        fd.fixeddeposit(number, name, amount, term);
        fd.displayAccountInfo();
        fd.calculateInterest();
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
