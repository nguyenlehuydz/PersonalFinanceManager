#include "../include/Income.h"
Income::Income()
    : Transaction(),
      sourceId("")
{}
Income::Income(
    const std::string& id,
    const Date& date,
    const std::string& sourceId,
    long long amount,
    const std::string& walletId,
    const std::string& description)
    : Transaction(id, date, amount, walletId, description),
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
