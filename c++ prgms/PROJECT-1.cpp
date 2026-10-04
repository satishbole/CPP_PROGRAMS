#include<bits/stdc++.h>

using namespace std;

// ==========================================================
// BANK ACCOUNT CLASS
// ==========================================================
class BankAccount
{
private:
    string accountHolder;
    long long accountNumber;
    double balance;
    int pin;

public:

    // Constructor
    BankAccount()
    {
        accountHolder = "";
        accountNumber = 0;
        balance = 0.0;
        pin = 0;
    }

    BankAccount(string name, long long number, double amount, int p)
    {
        accountHolder = name;
        accountNumber = number;
        balance = amount;
        pin = p;
    }

    // Get functions
    string getName()
    {
        return accountHolder;
    }

    long long getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }

    int getPIN()
    {
        return pin;
    }

    // PIN verification
    bool verifyPIN(int enteredPIN)
    {
        if (enteredPIN == pin)
        {
            return true;
        }

        return false;
    }

    // Deposit
    bool deposit(double amount)
    {
        if (amount <= 0)
        {
            return false;
        }

        balance = balance + amount;
        return true;
    }

    // Withdraw
    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            return false;
        }

        if (amount > balance)
        {
            return false;
        }

        balance = balance - amount;
        return true;
    }

    // Display account details
    void displayAccount()
    {
        cout << "\n";
        cout << "========================================\n";
        cout << "           ACCOUNT DETAILS\n";
        cout << "========================================\n";
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Security PIN   : ****" << endl;
        cout << "Balance        : Rs."
             << fixed << setprecision(2)
             << balance << endl;
        cout << "========================================\n";
    }

    // Save account to file
    void saveToFile(ofstream &file)
    {
        file << accountNumber << endl;
        file << accountHolder << endl;
        file << fixed << setprecision(2) << balance << endl;
        file << pin << endl;
    }
};


// ==========================================================
// FIND ACCOUNT
// Returns true if account number exists.
// ==========================================================
bool findAccount(long long searchNumber, BankAccount &account)
{
    ifstream file("accounts.txt");

    if (!file)
    {
        return false;
    }

    long long number;
    string name;
    double balance;
    int pin;

    while (file >> number)
    {
        file.ignore(10000, '\n');

        getline(file, name);

        file >> balance;
        file >> pin;

        file.ignore(10000, '\n');

        if (number == searchNumber)
        {
            account = BankAccount(
                name,
                number,
                balance,
                pin
            );

            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


// ==========================================================
// SAVE NEW ACCOUNT
// ==========================================================
void saveNewAccount(BankAccount account)
{
    ofstream file("accounts.txt", ios::app);

    if (!file)
    {
        cout << "\nError: Could not open account file.\n";
        return;
    }

    account.saveToFile(file);

    file.close();
}


// ==========================================================
// UPDATE EXISTING ACCOUNT
// ==========================================================
void updateAccount(BankAccount updatedAccount)
{
    ifstream inputFile("accounts.txt");
    ofstream tempFile("temp.txt");

    if (!inputFile)
    {
        cout << "\nError: Account file not found.\n";
        return;
    }

    if (!tempFile)
    {
        cout << "\nError: Could not create temporary file.\n";
        return;
    }

    long long number;
    string name;
    double balance;
    int pin;

    while (inputFile >> number)
    {
        inputFile.ignore(10000, '\n');

        getline(inputFile, name);

        inputFile >> balance;
        inputFile >> pin;

        inputFile.ignore(10000, '\n');

        if (number == updatedAccount.getAccountNumber())
        {
            updatedAccount.saveToFile(tempFile);
        }
        else
        {
            tempFile << number << endl;
            tempFile << name << endl;
            tempFile << fixed << setprecision(2)
                     << balance << endl;
            tempFile << pin << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}


// ==========================================================
// CREATE NEW ACCOUNT
// ==========================================================
void createAccount()
{
    string name;
    long long accountNumber;
    double initialBalance;
    int pin;

    cout << "\n========================================\n";
    cout << "          CREATE NEW ACCOUNT\n";
    cout << "========================================\n";

    cin.ignore(10000, '\n');

    cout << "Enter Account Holder Name : ";
    getline(cin, name);

    // Account number
    cout << "Enter Account Number      : ";

    while (!(cin >> accountNumber) || accountNumber <= 0)
    {
        cout << "Invalid account number!\n";
        cout << "Enter Account Number      : ";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Check duplicate account
    BankAccount existingAccount;

    if (findAccount(accountNumber, existingAccount))
    {
        cout << "\n----------------------------------------\n";
        cout << "Account Number Already Exists!\n";
        cout << "Please use a different account number.\n";
        cout << "----------------------------------------\n";

        return;
    }

    // Initial balance
    cout << "Enter Initial Balance     : Rs.";

    while (!(cin >> initialBalance) || initialBalance < 0)
    {
        cout << "Invalid amount!\n";
        cout << "Enter Initial Balance     : Rs.";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    // PIN
    cout << "Set 4-Digit PIN           : ";

    while (!(cin >> pin) || pin < 1000 || pin > 9999)
    {
        cout << "Invalid PIN!\n";
        cout << "Enter a 4-digit PIN      : ";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Create account
    BankAccount newAccount(
        name,
        accountNumber,
        initialBalance,
        pin
    );

    saveNewAccount(newAccount);

    cout << "\n========================================\n";
    cout << "     ACCOUNT CREATED SUCCESSFULLY!\n";
    cout << "========================================\n";

    newAccount.displayAccount();

    cout << "\nYou can now login using your\n";
    cout << "Account Number and PIN.\n";
}


// ==========================================================
// BANKING MENU
// ==========================================================
void bankingMenu(BankAccount &account)
{
    int choice;
    int enteredPIN;
    double amount;

    do
    {
        cout << "\n";
        cout << "========================================\n";
        cout << "              MAIN MENU\n";
        cout << "========================================\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Account Details\n";
        cout << "5. Logout\n";
        cout << "========================================\n";

        cout << "Enter your choice (1-5): ";

        if (!(cin >> choice))
        {
            cout << "\nInvalid input!\n";

            cin.clear();
            cin.ignore(10000, '\n');

            continue;
        }

        // ==============================================
        // DEPOSIT
        // ==============================================
        if (choice == 1)
        {
            cout << "\nEnter 4-Digit PIN: ";

            if (!(cin >> enteredPIN))
            {
                cout << "\nInvalid PIN format!\n";

                cin.clear();
                cin.ignore(10000, '\n');

                continue;
            }

            if (!account.verifyPIN(enteredPIN))
            {
                cout << "\nIncorrect PIN!\n";
                cout << "Transaction Cancelled.\n";

                continue;
            }

            cout << "\nPIN Verified Successfully!\n";

            cout << "Enter Deposit Amount: Rs.";

            if (!(cin >> amount))
            {
                cout << "\nInvalid amount!\n";

                cin.clear();
                cin.ignore(10000, '\n');

                continue;
            }

            if (account.deposit(amount))
            {
                updateAccount(account);

                cout << "\nDeposit Successful!\n";
                cout << "Current Balance : Rs."
                     << fixed << setprecision(2)
                     << account.getBalance() << endl;
            }
            else
            {
                cout << "\nInvalid Deposit Amount!\n";
                cout << "Amount must be greater than zero.\n";
            }
        }

        // ==============================================
        // WITHDRAW
        // ==============================================
        else if (choice == 2)
        {
            cout << "\nEnter 4-Digit PIN: ";

            if (!(cin >> enteredPIN))
            {
                cout << "\nInvalid PIN format!\n";

                cin.clear();
                cin.ignore(10000, '\n');

                continue;
            }

            if (!account.verifyPIN(enteredPIN))
            {
                cout << "\nIncorrect PIN!\n";
                cout << "Transaction Cancelled.\n";

                continue;
            }

            cout << "\nPIN Verified Successfully!\n";

            cout << "Enter Withdrawal Amount: Rs.";

            if (!(cin >> amount))
            {
                cout << "\nInvalid amount!\n";

                cin.clear();
                cin.ignore(10000, '\n');

                continue;
            }

            if (amount <= 0)
            {
                cout << "\nInvalid Withdrawal Amount!\n";
                cout << "Amount must be greater than zero.\n";
            }
            else if (amount > account.getBalance())
            {
                cout << "\nInsufficient Balance!\n";
                cout << "Withdrawal Failed.\n";

                cout << "Current Balance : Rs."
                     << fixed << setprecision(2)
                     << account.getBalance() << endl;
            }
            else
            {
                account.withdraw(amount);

                updateAccount(account);

                cout << "\nWithdrawal Successful!\n";

                cout << "Current Balance : Rs."
                     << fixed << setprecision(2)
                     << account.getBalance() << endl;
            }
        }

        // ==============================================
        // CHECK BALANCE
        // ==============================================
        else if (choice == 3)
        {
            cout << "\nEnter 4-Digit PIN: ";

            if (!(cin >> enteredPIN))
            {
                cout << "\nInvalid PIN format!\n";

                cin.clear();
                cin.ignore(10000, '\n');

                continue;
            }

            if (account.verifyPIN(enteredPIN))
            {
                cout << "\nPIN Verified Successfully!\n";

                cout << "\nAvailable Balance : Rs."
                     << fixed << setprecision(2)
                     << account.getBalance()
                     << endl;
            }
            else
            {
                cout << "\nIncorrect PIN!\n";
                cout << "Access Denied.\n";
            }
        }

        // ==============================================
        // ACCOUNT DETAILS
        // ==============================================
        else if (choice == 4)
        {
            cout << "\nEnter 4-Digit PIN: ";

            if (!(cin >> enteredPIN))
            {
                cout << "\nInvalid PIN format!\n";

                cin.clear();
                cin.ignore(10000, '\n');

                continue;
            }

            if (account.verifyPIN(enteredPIN))
            {
                cout << "\nPIN Verified Successfully!\n";

                account.displayAccount();
            }
            else
            {
                cout << "\nIncorrect PIN!\n";
                cout << "Access Denied.\n";
            }
        }

        // ==============================================
        // LOGOUT
        // ==============================================
        else if (choice == 5)
        {
            cout << "\n========================================\n";
            cout << "         LOGGED OUT SUCCESSFULLY\n";
            cout << "========================================\n";
        }

        else
        {
            cout << "\nInvalid choice!\n";
            cout << "Please enter a number from 1 to 5.\n";
        }

    } while (choice != 5);
}


// ==========================================================
// EXISTING ACCOUNT LOGIN
// ==========================================================
void login()
{
    long long accountNumber;
    int pin;
    int attempts = 0;

    BankAccount account;

    cout << "\n========================================\n";
    cout << "          EXISTING ACCOUNT LOGIN\n";
    cout << "========================================\n";

    cout << "Enter Account Number: ";

    while (!(cin >> accountNumber) || accountNumber <= 0)
    {
        cout << "Invalid Account Number!\n";
        cout << "Enter Account Number: ";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Find account
    if (!findAccount(accountNumber, account))
    {
        cout << "\n========================================\n";
        cout << "          ACCOUNT NOT FOUND\n";
        cout << "========================================\n";

        cout << "This account number does not exist.\n";
        cout << "Please create a new account.\n";

        return;
    }

    cout << "\nAccount Found!\n";
    cout << "Account Holder : "
         << account.getName() << endl;

    // Give 3 PIN attempts
    while (attempts < 3)
    {
        cout << "\nEnter 4-Digit PIN: ";

        if (!(cin >> pin))
        {
            cout << "Invalid PIN format!\n";

            cin.clear();
            cin.ignore(10000, '\n');

            attempts++;
            continue;
        }

        if (account.verifyPIN(pin))
        {
            cout << "\n========================================\n";
            cout << "          LOGIN SUCCESSFUL\n";
            cout << "========================================\n";

            account.displayAccount();

            bankingMenu(account);

            return;
        }

        attempts++;

        cout << "\nIncorrect PIN!\n";

        if (attempts < 3)
        {
            cout << "Attempts remaining: "
                 << 3 - attempts << endl;
        }
    }

    cout << "\n========================================\n";
    cout << "       TOO MANY INCORRECT ATTEMPTS\n";
    cout << "========================================\n";

    cout << "Login cancelled for security reasons.\n";
}


// ==========================================================
// MAIN FUNCTION
// ==========================================================
int main()
{
    int choice;

    cout << "\n";
    cout << "========================================\n";
    cout << "       BANK ACCOUNT MANAGEMENT SYSTEM\n";
    cout << "========================================\n";

    do
    {
        cout << "\n";
        cout << "========================================\n";
        cout << "                WELCOME\n";
        cout << "========================================\n";
        cout << "1. Existing Account Login\n";
        cout << "2. Create New Account\n";
        cout << "3. Exit\n";
        cout << "========================================\n";

        cout << "Enter your choice (1-3): ";

        if (!(cin >> choice))
        {
            cout << "\nInvalid input!\n";
            cout << "Please enter 1, 2 or 3.\n";

            cin.clear();
            cin.ignore(10000, '\n');

            continue;
        }

        // Existing account
        if (choice == 1)
        {
            login();
        }

        // New account
        else if (choice == 2)
        {
            createAccount();
        }

        // Exit
        else if (choice == 3)
        {
            cout << "\n========================================\n";
            cout << "     THANK YOU FOR USING OUR BANK\n";
            cout << "========================================\n";
            cout << "Program Exited Successfully.\n";
        }

        else
        {
            cout << "\nInvalid choice!\n";
            cout << "Please enter a number from 1 to 3.\n";
        }

    } while (choice != 3);

    return 0;
}
