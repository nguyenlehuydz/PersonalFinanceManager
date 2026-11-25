#include "../include/RecurringTransaction.h"
#include <iostream>
RecurringTransaction::RecurringTransaction()
    : type(INCOMETYPE),
      startDate(),
      endDate(),
      hasEndDate(false),
      sourceOrCategoryId(),
      walletId(),
      amount(0.0),
      description()
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
TransactionType RecurringTransaction::getType() const
{
    return type;
}
const Date& RecurringTransaction::getStartDate() const
{
    return startDate;
}
const Date& RecurringTransaction::getEndDate() const
{
    return endDate;
}
bool RecurringTransaction::getHasEndDate() const
{
    return hasEndDate;
}
const std::string& RecurringTransaction::getSourceOrCategoryId() const
{
    return sourceOrCategoryId;
}
const std::string& RecurringTransaction::getWalletId() const
{
    return walletId;
}
double RecurringTransaction::getAmount() const
{
    return amount;
}
const std::string& RecurringTransaction::getDescription() const
{
    return description;
}
void RecurringTransaction::display() const
{
    std::cout
        << "Recurring Transaction\n"
        << "Type: " << (type == INCOMETYPE ? "Income" : "Expense") << '\n'
        << "Source/Category Id: " << sourceOrCategoryId << '\n'
        << "Wallet Id: " << walletId << '\n'
        << "Amount: " << amount << '\n'
        << "Description: " << description << '\n';
}
