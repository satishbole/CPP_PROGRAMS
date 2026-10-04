#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// =======================================================
// Class: BankAccount
// Demonstrates: Encapsulation, Data Hiding, Constructors,
// Member Functions, User-Defined PIN & Verification.
// =======================================================
class BankAccount
{
private:
    // Private data members (Encapsulation / Data Hiding)
    string accountHolder;
    int accountNumber;
    double balance;
    int pin; // User-chosen 4-digit security PIN

public:
    // Parameterized Constructor: Initializes account details and stores user's chosen PIN
    BankAccount(string name, int number, double initialBalance, int userPin)
    {
        accountHolder = name;
        accountNumber = number;
        balance = initialBalance;
        pin = userPin;
    }

    // PIN Verification Function
    bool verifyPIN(int enteredPIN) const
    {
        if (enteredPIN == pin)
        {
            cout << "\nPIN Verified Successfully!\n";
            return true;
        }
        else
        {
            cout << "\nIncorrect PIN!\n";
            cout << "Access Denied. Transaction Cancelled.\n";
            return false;
        }
    }

    // Deposit Module: Validates amount and updates balance
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "\nDeposit Successful!" << endl;
            cout << "Current Balance : Rs." << fixed << setprecision(2) << balance << endl;
        }
        else
        {
            cout << "\nInvalid Deposit Amount! Amount must be greater than zero." << endl;
        }
    }

    // Withdrawal Module: Validates positive amount and checks for sufficient funds
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "\nInvalid Withdrawal Amount! Amount must be greater than zero." << endl;
        }
        else if (amount > balance)
        {
            cout << "\nInsufficient Balance!" << endl;
            cout << "Withdrawal Failed." << endl;
            cout << "Current Balance : Rs." << fixed << setprecision(2) << balance << endl;
        }
        else
        {
            balance -= amount;
            cout << "\nWithdrawal Successful!" << endl;
            cout << "Current Balance : Rs." << fixed << setprecision(2) << balance << endl;
        }
    }

    // Balance Check Module: Displays current available balance
    void checkBalance() const
    {
        cout << "\nAvailable Balance : Rs." << fixed << setprecision(2) << balance << endl;
    }

    // Account Summary Display
    void displayAccount() const
    {
        cout << "\n========== ACCOUNT DETAILS ==========" << endl;
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Security PIN   : " << pin << endl;
        cout << "Balance        : Rs." << fixed << setprecision(2) << balance << endl;
        cout << "=====================================" << endl;
    }
};

int main()
{
    string name;
    int accountNumber;
    double initialBalance;
    int userPin;

    cout << "=========================================\n";
    cout << "        BANK ACCOUNT SYSTEM (C++)        \n";
    cout << "=========================================\n\n";

    // Module 1: Account Creation & Input
    cout << "Enter Account Holder Name   : ";
    getline(cin, name);

    cout << "Enter Account Number        : ";
    while (!(cin >> accountNumber))
    {
        cout << "Invalid Account Number! Enter digits only: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter Initial Balance       : Rs.";
    while (!(cin >> initialBalance) || initialBalance < 0)
    {
        cout << "Invalid Balance! Enter a non-negative amount: Rs.";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Prompt user to choose their own 4-digit PIN
    cout << "Set your 4-Digit PIN (1000-9999): ";
    while (!(cin >> userPin) || userPin < 1000 || userPin > 9999)
    {
        cout << "Invalid PIN! Please enter a 4-digit number (1000-9999): ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Instantiate BankAccount object with user's custom PIN
    BankAccount account(name, accountNumber, initialBalance, userPin);

    cout << "\nAccount Created Successfully!\n";
    account.displayAccount();

    int choice;
    int enteredPIN;
    double amount;

    // Menu Loop (do-while) with PIN Authentication for transactions
    do
    {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4) : ";

        if (!(cin >> choice))
        {
            cout << "\nInvalid Choice! Please enter a number between 1 and 4.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
            continue;
        }

        switch (choice)
        {
            case 1:
                cout << "\nEnter 4-Digit PIN: ";
                if (!(cin >> enteredPIN))
                {
                    cout << "\nInvalid PIN format! Numeric digits only.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

                if (account.verifyPIN(enteredPIN))
                {
                    cout << "Enter Deposit Amount: Rs.";
                    if (cin >> amount)
                    {
                        account.deposit(amount);
                    }
                    else
                    {
                        cout << "\nInvalid input! Please enter a valid number.\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                break;

            case 2:
                cout << "\nEnter 4-Digit PIN: ";
                if (!(cin >> enteredPIN))
                {
                    cout << "\nInvalid PIN format! Numeric digits only.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

                if (account.verifyPIN(enteredPIN))
                {
                    cout << "Enter Withdrawal Amount: Rs.";
                    if (cin >> amount)
                    {
                        account.withdraw(amount);
                    }
                    else
                    {
                        cout << "\nInvalid input! Please enter a valid number.\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                break;

            case 3:
                cout << "\nEnter 4-Digit PIN: ";
                if (!(cin >> enteredPIN))
                {
                    cout << "\nInvalid PIN format! Numeric digits only.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

                if (account.verifyPIN(enteredPIN))
                {
                    account.checkBalance();
                }
                break;

            case 4:
                cout << "\nThank You!\n";
                cout << "Program Exited Successfully.\n";
                break;

            default:
                cout << "\nInvalid Choice! Please enter an option from 1 to 4.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
