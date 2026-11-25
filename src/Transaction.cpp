#include "../include/Transaction.h"
Transaction::Transaction()
    : date(),
      amount(0.0),
      walletId(),
      description()
{}
Transaction::Transaction(
    const Date& date,
    double amount,
    const std::string& walletId,
    const std::string& description)
    : date(date),
      amount(amount),
      walletId(walletId),
      description(description)
{}
const Date& Transaction::getDate() const
{
    return date;
}
double Transaction::getAmount() const
{
    return amount;
}
const std::string& Transaction::getWalletId() const
{
    return walletId;
}
const std::string& Transaction::getDescription() const
{
    return description;
}
