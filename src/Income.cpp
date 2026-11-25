#include "../include/Income.h"
#include <iostream>
Income::Income()
    : Transaction(),
      sourceId("")
{}
Income::Income(
    const Date& date,
    const std::string& sourceId,
    double amount,
    const std::string& walletId,
    const std::string& description)
    : Transaction(date, amount, walletId, description),
      sourceId(sourceId)
{}
const std::string& Income::getSourceId() const
{
    return sourceId;
}
void Income::setSourceId(const std::string& sourceId)
{
    this->sourceId = sourceId;
}
void Income::display() const
{
    std::cout
        << "Income\n"
        << "Source Id: " << sourceId << '\n'
        << "Wallet Id: " << walletId << '\n'
        << "Amount: " << amount << '\n'
        << "Description: " << description << '\n';
}
