#include "../include/Wallet.h"
Wallet::Wallet()
    : id(""),
      name(""),
      initialBalance(0)
{}
Wallet::Wallet(
    const std::string& id,
    const std::string& name,
    long long initialBalance)
    : id(id),
      name(name),
      initialBalance(initialBalance)
{}
const std::string& Wallet::getId() const
{
    return id;
}
void Wallet::setId(const std::string& id)
{
    this->id = id;
}
const std::string& Wallet::getName() const
{
    return name;
}
void Wallet::setName(const std::string& name)
{
    this->name = name;
}
long long Wallet::getInitialBalance() const
{
    return initialBalance;
}
void Wallet::setInitialBalance(long long balance)
{
    this->initialBalance = balance;
}
