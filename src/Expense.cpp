#include "../include/Expense.h"
#include <iostream>
Expense::Expense()
    : Transaction(),
      categoryId("")
{}
Expense::Expense(
    const Date& date,
    const std::string& categoryId,
    double amount,
    const std::string& walletId,
    const std::string& description)
    : Transaction(
          date,
          amount,
          walletId,
          description),
      categoryId(categoryId)
{}
const std::string& Expense::getCategoryId() const
{
    return categoryId;
}
void Expense::display() const
{
    std::cout
        << "Expense\n"
        << "Category Id: " << categoryId << '\n'
        << "Wallet Id: " << walletId << '\n'
        << "Amount: " << amount << '\n'
        << "Description: " << description << '\n';
}
