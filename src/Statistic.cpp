#include "../include/Statistic.h"
#include "../include/Income.h"
#include "../include/Expense.h"
#include <iostream>
Statistic::Statistic()
{}
Statistic::Statistic(
    const std::vector<const Transaction*>& transactions)
    : transactions(transactions)
{}
double Statistic::getTotalIncome() const
{
    double total = 0.0;
    for (const Transaction* transaction : transactions)
    {
        if (dynamic_cast<const Income*>(transaction) != nullptr)
        {
            total += transaction->getAmount();
        }
    }
    return total;
}
double Statistic::getTotalExpense() const
{
    double total = 0.0;

    for (const Transaction* transaction : transactions)
    {
        if (dynamic_cast<const Expense*>(transaction) != nullptr)
        {
            total += transaction->getAmount();
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
    std::cout
        << "\n===== STATISTIC REPORT =====\n"
        << "Total Income  : "
        << getTotalIncome()
        << '\n'
        << "Total Expense : "
        << getTotalExpense()
        << '\n'
        << "Balance       : "
        << getBalance()
        << '\n';
}
