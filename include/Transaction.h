#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include "Date.h"
class Transaction
{
protected:
    std::string id;
    Date date;
    long long amount;
    std::string walletId;
    std::string description;
public:
    Transaction();
    Transaction(
        const std::string& id,
        const Date& date,
        long long amount,
        const std::string& walletId,
        const std::string& description);
    virtual ~Transaction() = default;
    const std::string& getId() const;
    void setId(const std::string& id);
    const Date& getDate() const;
    void setDate(const Date& date);
    long long getAmount() const;
    void setAmount(long long amount);
    const std::string& getWalletId() const;
    void setWalletId(const std::string& walletId);
    const std::string& getDescription() const;
    void setDescription(const std::string& description);
};
#endif
