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

    TransactionType getType() const;
    const Date& getStartDate() const;
    const Date& getEndDate() const;
    bool getHasEndDate() const;
    const std::string& getSourceOrCategoryId() const;
    const std::string& getWalletId() const;
    double getAmount() const;
    const std::string& getDescription() const;
    void display() const;
};
#endif
