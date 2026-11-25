#ifndef EXPENSE_H
#define EXPENSE_H
#include <string>
#include "Transaction.h"
class Expense : public Transaction
{
private:
    std::string categoryId;
public:
    Expense();
    Expense(
        const Date& date,
        const std::string& categoryId,
        double amount,
        const std::string& walletId,
        const std::string& description);
    const std::string& getCategoryId() const;
    void setCategoryId(const std::string& categoryId);
    void display() const override;
};
#endif
