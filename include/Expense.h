#ifndef EXPENSE_H
#define EXPENSE_H
#include <string>
#include "Transaction.h"
class Expense : public Transaction
{
private:
    std::string sourceId;
public:
    Expense();
    Expense(
        const Date& date,
        const std::string& sourceId,
        double amount,
        const std::string& walletId,
        const std::string& description);
    const std::string& getsourceId() const;
    void display() const override;
};
#endif
