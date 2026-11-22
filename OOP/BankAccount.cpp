#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:                       // Encapsulation: hidden data
    string owner;
    double balance;

public:
    BankAccount(string name, double initial) {   // Constructor
        owner = name;
        balance = initial;
    }

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) balance -= amount;
        else cout << "Insufficient balance\n";
    }

    void display() const {
        cout << owner << " has balance: " << balance << "\n";
    }
};

int main() {
    BankAccount acc("Anurag", 1000);
    acc.deposit(500);
    acc.withdraw(300);
    acc.display();    // Anurag has balance: 1200
}
