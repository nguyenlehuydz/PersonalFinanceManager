#include "../include/Transaction.h"
Transaction::Transaction()
    : id(""),
      date(),
      amount(0),
      walletId(""),
      description("")
{}
Transaction::Transaction(
    const std::string& id,
    const Date& date,
    long long amount,
    const std::string& walletId,
    const std::string& description)
    : id(id),
      date(date),
      amount(amount),
      walletId(walletId),
      description(description)
{}
const std::string& Transaction::getId() const
{
    return id;
}
void Transaction::setId(const std::string& id)
{
    this->id = id;
}
const Date& Transaction::getDate() const
{
    return date;
}
void Transaction::setDate(const Date& date)
{
    this->date = date;
}
long long Transaction::getAmount() const
{
    return amount;
}
void Transaction::setAmount(long long amount)
{
    this->amount = amount;
}
const std::string& Transaction::getWalletId() const
{
    return walletId;
}
void Transaction::setWalletId(const std::string& walletId)
{
    this->walletId = walletId;
}
const std::string& Transaction::getDescription() const
{
    return description;
}
void Transaction::setDescription(const std::string& description)
{
    this->description = description;
}
