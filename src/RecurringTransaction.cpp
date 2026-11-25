#include "../include/RecurringTransaction.h"
#include <iostream>
RecurringTransaction::RecurringTransaction()
    : type(INCOMETYPE),
      startDate(),
      endDate(),
      hasEndDate(false),
      sourceOrCategoryId(""),
      walletId(""),
      amount(0.0),
      description("")
{}
RecurringTransaction::RecurringTransaction(
    TransactionType type,
    const Date& startDate,
    const Date& endDate,
    bool hasEndDate,
    const std::string& sourceOrCategoryId,
    const std::string& walletId,
    double amount,
    const std::string& description)
    : type(type),
      startDate(startDate),
      endDate(endDate),
      hasEndDate(hasEndDate),
      sourceOrCategoryId(sourceOrCategoryId),
      walletId(walletId),
      amount(amount),
      description(description)
{}
void RecurringTransaction::display() const
{
    std::cout
        << "Recurring Transaction\n"
        << "Wallet Id: " << walletId << '\n'
        << "Amount: " << amount << '\n'
        << "Description: " << description << '\n';
}
