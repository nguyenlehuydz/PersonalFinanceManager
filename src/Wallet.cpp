#include "../include/Wallet.h"
#include <iostream>
Wallet::Wallet()
    : id(""),
      name("")
{}
Wallet::Wallet(
    const std::string& id,
    const std::string& name)
    : id(id),
      name(name)
{}
void Wallet::setId(const std::string& id)
{
    this->id = id;
}
void Wallet::setName(const std::string& name)
{
    this->name = name;
}
const std::string& Wallet::getId() const
{
    return id;
}
const std::string& Wallet::getName() const
{
    return name;
}
void Wallet::display() const
{
    std::cout << id << " - " << name << '\n';
}
