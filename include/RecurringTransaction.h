#ifndef RECURRING_TRANSACTION_H
#define RECURRING_TRANSACTION_H
#include <string>
#include "Date.h"
enum TransactionType
{
    INCOMETYPE,
    EXPENSETYPE
};
class RecurringTransaction
{
private:
    TransactionType type;
    Date startDate;
    Date endDate;
    bool hasEndDate;
    std::string sourceOrCategoryId;
    std::string walletId;
    double amount;
    std::string description;
public:
    RecurringTransaction();
    RecurringTransaction(
        TransactionType type,
        const Date& startDate,
        const Date& endDate,
        bool hasEndDate,
        const std::string& sourceOrCategoryId,
        const std::string& walletId,
        double amount,
        const std::string& description);

    void display() const;
};
#endif
