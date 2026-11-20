#include "../include/Statistic.h"
#include "../include/Income.h"
#include "../include/Expense.h"
using namespace std;
#include <iostream>

Statistic::Statistic()
{
}

Statistic::Statistic(
    const vector<Transaction*>& transactions)
{
    this->transactions = transactions;
}

double Statistic::getTotalIncome() const
{
    double total = 0;

    for(auto t : transactions)
    {
        if(dynamic_cast<Income*>(t))
        {
            total += t->getAmount();
        }
    }

    return total;
}

double Statistic::getTotalExpense() const
{
    double total = 0;

    for(auto t : transactions)
    {
        if(dynamic_cast<Expense*>(t))
        {
            total += t->getAmount();
        }
    }

    return total;
}

double Statistic::getBalance() const
{
    return getTotalIncome() - getTotalExpense();
}

void Statistic::displayReport() const
{
    cout << "\n===== STATISTIC REPORT =====\n";

    cout << "Total Income : "
              << getTotalIncome()
              << "\n";

    cout << "Total Expense : "
              << getTotalExpense()
              << "\n";

    cout << "Balance : "
              << getBalance()
              << "\n";
}
