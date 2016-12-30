#include "Account.h"

using namespace std;

//Constructor, the :balance(0) is initialization syntax.  only works on constructors
Account::Account(void):balance(0)
{
}

//Double colons, scope resolution operator, used to specify method Report() is for class account
vector<string> Account::Report()
{
    vector<string> report;
    report.push_back("Balance is " + to_string(balance));
    report.push_back("Transactions: ");
    for(auto t:log)
    {
        report.push_back(t.Report());
    }
    report.push_back("----------------");

    return report;
}

bool Account::Deposit(int amt)
{
    if(amt >= 0)
    {
        balance += amt;
        log.push_back(Transaction(amt, "Deposit"));
        return true;
    }
    else
    {
        return false;
    }
}

bool Account::Withdraw(int amt)
{
    if(amt >= 0)
    {
        if(balance >= amt)
        {
            balance -= amt;
            log.push_back(Transaction(amt, "Withdraw"));
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
