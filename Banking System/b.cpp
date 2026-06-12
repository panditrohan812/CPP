#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() : accountNumber(0),
                    accountHolderName(""),
                    balance(0.0) {}

    BankAccount(int accNum, string accHolderName, double bal)
        : accountNumber(accNum), accountHolderName(accHolderName), balance(bal) {}

    virtual ~BankAccount() {}

    void deposit(double amount)
    {
        if (amount <= 0)
            cout << "Invalid deposit amount!" << endl;
        else
        {
            balance += amount;
            cout << "Deposited $" << amount << " successfully." << endl;
        }
    }

    virtual void withdraw(double amount)
    {
        if (amount <= 0)
            cout << "Invalid withdrawal amount!" << endl;
        else if (amount > balance)
            cout << "Insufficient funds!" << endl;
        else
        {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully." << endl;
        }
    }

    double getBalance() const
    {
        return balance;
    }

    void setBalance(double bal)
    {
        balance = bal;
    }

    virtual void calculateInterest() = 0;

    virtual void displayAccountInfo() const
    {
        cout << "Account Number     : " << accountNumber << endl;
        cout << "Account Holder     : " << accountHolderName << endl;
        cout << "Balance            : $" << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int accNum, string accHolderName, double bal, double rate)
        : BankAccount(accNum, accHolderName, bal), interestRate(rate) {}

    void calculateInterest() override
    {
        double interest = getBalance() * (interestRate / 100);
        deposit(interest);
        cout << "Interest @ " << interestRate << "% = $" << interest << " added to balance." << endl;
    }

    void displayAccountInfo() const override
    {
        cout << "\n--- Savings Account ---" << endl;
        BankAccount::displayAccountInfo();
        cout << "Interest Rate      : " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, string accHolderName, double bal, double overdraft)
        : BankAccount(accNum, accHolderName, bal), overdraftLimit(overdraft) {}

    void withdraw(double amount) override
    {
        if (amount <= 0)
            cout << "Invalid withdrawal amount!" << endl;
        else if (amount > getBalance() + overdraftLimit)
            cout << "Withdrawal exceeds overdraft limit of $" << overdraftLimit << "!" << endl;
        else
        {
            setBalance(getBalance() - amount);
            cout << "Withdrawn $" << amount << " successfully." << endl;
        }
    }

    void checkOverdraft(double amount)
    {
        if (amount > getBalance() + overdraftLimit)
            cout << "This withdrawal EXCEEDS the overdraft limit." << endl;
        else
            cout << "This withdrawal is within the overdraft limit." << endl;
    }

    void calculateInterest() override
    {
        cout << "Checking accounts do not earn interest." << endl;
    }

    void displayAccountInfo() const override
    {
        cout << "\n--- Checking Account ---" << endl;
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit    : $" << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int termMonths;
    double interestRate;

public:
    FixedDepositAccount(int accNum, string accHolderName, double bal, int months, double rate)
        : BankAccount(accNum, accHolderName, bal), termMonths(months), interestRate(rate) {}

    void calculateInterest() override
    {
        double timeYears = termMonths / 12.0;
        double interest = getBalance() * (interestRate / 100) * timeYears;
        double maturityAmount = getBalance() + interest;
        cout << "Fixed Deposit Details:" << endl;
        cout << "  Principal        : $" << getBalance() << endl;
        cout << "  Term             : " << termMonths << " months" << endl;
        cout << "  Interest Rate    : " << interestRate << "% per annum" << endl;
        cout << "  Interest Earned  : $" << interest << endl;
        cout << "  Maturity Amount  : $" << maturityAmount << endl;
    }

    void withdraw(double amount) override
    {
        cout << "Early withdrawal not allowed for Fixed Deposit accounts!" << endl;
    }

    void displayAccountInfo() const override
    {
        cout << "\n--- Fixed Deposit Account ---" << endl;
        BankAccount::displayAccountInfo();
        cout << "Term               : " << termMonths << " months" << endl;
        cout << "Interest Rate      : " << interestRate << "% per annum" << endl;
    }
};

void showMenu(const string &accountType)
{
    cout << "\n===== Banking System =====" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Calculate Interest" << endl;
    cout << "4. Display Account Info" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{

    SavingsAccount sa(10001, "Raj Patel", 5000.0, 4.5);
    CheckingAccount ca(10002, "Nayan Shah", 3000.0, 1000.0);
    FixedDepositAccount fda(10003, "Amit Desai", 20000.0, 12, 7.5);

    BankAccount *accounts[3];
    accounts[0] = &sa;
    accounts[1] = &ca;
    accounts[2] = &fda;

    for (int i = 0; i < 3; i++)
    {
        accounts[i]->displayAccountInfo();
        accounts[i]->calculateInterest();
    }

    int accountChoice;
    cout << "\n===== Select Account to Manage =====" << endl;
    cout << "1. Savings Account " << endl;
    cout << "2. Checking Account " << endl;
    cout << "3. Fixed Deposit Account " << endl;
    cout << "Enter choice: ";
    cin >> accountChoice;

    BankAccount *selected = nullptr;
    string accType;
    if (accountChoice == 1)
    {
        selected = &sa;
        accType = "Savings";
    }
    else if (accountChoice == 2)
    {
        selected = &ca;
        accType = "Checking";
    }
    else if (accountChoice == 3)
    {
        selected = &fda;
        accType = "Fixed Deposit";
    }
    else
    {
        cout << "Invalid choice!";
    }

    int choice;
    do
    {
        showMenu(accType);
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            double amount;
            cout << "Enter amount to deposit: $";
            cin >> amount;
            selected->deposit(amount);
            break;
        }
        case 2:
        {
            double amount;
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            selected->withdraw(amount);
            break;
        }
        case 3:
            selected->calculateInterest();
            break;
        case 4:
            selected->displayAccountInfo();
            break;
        case 5:
            cout << "Exiting... Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
}