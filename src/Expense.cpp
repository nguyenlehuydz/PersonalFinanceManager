#include "../include/Expense.h"
Expense::Expense()
    : Transaction(),
      categoryId("")
{}
Expense::Expense(
    const std::string& id,
    const Date& date,
    const std::string& categoryId,
    long long amount,
    const std::string& walletId,
    const std::string& description)
    : Transaction(id, date, amount, walletId, description),
      categoryId(categoryId)
{}
const std::string& Expense::getCategoryId() const
{
    return categoryId;
}
void Expense::setCategoryId(const std::string& categoryId)
{
    this->categoryId = categoryId;
}
