#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include "Date.h"
class Transaction
{
protected:
    Date date;
    double amount;
    std::string walletId;
    std::string description;
public:
    Transaction();
    Transaction(
        const Date& date,
        double amount,
        const std::string& walletId,
        const std::string& description);
    virtual ~Transaction() = default;
    const Date& getDate() const;
    double getAmount() const;
    const std::string& getWalletId() const;
    const std::string& getDescription() const;
    virtual void display() const = 0;
};
#endif
