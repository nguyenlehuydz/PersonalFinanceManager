#include "../include/RecurringTransaction.h"
RecurringTransaction::RecurringTransaction()
    : id(""),
      type(RecurringType::INCOME),
      sourceOrCategoryId(""),
      amount(0),
      walletId(""),
      description(""),
      startDate(),
      hasEndDateFlag(false),
      endDate(),
      dayOfMonth(1)
{}
RecurringTransaction::RecurringTransaction(
    const std::string& id,
    RecurringType type,
    const std::string& sourceOrCategoryId,
    long long amount,
    const std::string& walletId,
    const std::string& description,
    const Date& startDate,
    bool hasEndDate,
    const Date& endDate,
    int dayOfMonth)
    : id(id),
      type(type),
      sourceOrCategoryId(sourceOrCategoryId),
      amount(amount),
      walletId(walletId),
      description(description),
      startDate(startDate),
      hasEndDateFlag(hasEndDate),
      endDate(endDate),
      dayOfMonth(dayOfMonth)
{}
const std::string& RecurringTransaction::getId() const
{
    return id;
}
void RecurringTransaction::setId(const std::string& id)
{
    this->id = id;
}
RecurringType RecurringTransaction::getType() const
{
    return type;
}
void RecurringTransaction::setType(RecurringType type)
{
    this->type = type;
}
const std::string& RecurringTransaction::getSourceOrCategoryId() const
{
    return sourceOrCategoryId;
}
void RecurringTransaction::setSourceOrCategoryId(const std::string& sourceOrCategoryId)
{
    this->sourceOrCategoryId = sourceOrCategoryId;
}
long long RecurringTransaction::getAmount() const
{
    return amount;
}
void RecurringTransaction::setAmount(long long amount)
{
    this->amount = amount;
}
const std::string& RecurringTransaction::getWalletId() const
{
    return walletId;
}
void RecurringTransaction::setWalletId(const std::string& walletId)
{
    this->walletId = walletId;
}
const std::string& RecurringTransaction::getDescription() const
{
    return description;
}
void RecurringTransaction::setDescription(const std::string& description)
{
    this->description = description;
}
const Date& RecurringTransaction::getStartDate() const
{
    return startDate;
}
void RecurringTransaction::setStartDate(const Date& startDate)
{
    this->startDate = startDate;
}
bool RecurringTransaction::hasEndDate() const
{
    return hasEndDateFlag;
}
void RecurringTransaction::setHasEndDate(bool hasEndDate)
{
    this->hasEndDateFlag = hasEndDate;
}
const Date& RecurringTransaction::getEndDate() const
{
    return endDate;
}
void RecurringTransaction::setEndDate(const Date& endDate)
{
    this->endDate = endDate;
}
int RecurringTransaction::getDayOfMonth() const
{
    return dayOfMonth;
}
void RecurringTransaction::setDayOfMonth(int dayOfMonth)
{
    this->dayOfMonth = dayOfMonth;
}
