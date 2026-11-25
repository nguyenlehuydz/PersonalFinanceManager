#ifndef INCOME_H
#define INCOME_H
#include <string>
#include "Transaction.h"
class Income : public Transaction
{
private:
    std::string sourceId;
public:
    Income();
    Income(
        const Date& date,
        const std::string& sourceId,
        double amount,
        const std::string& walletId,
        const std::string& description);
    const std::string& getSourceId() const;
    void setSourceId(const std::string& sourceId);
    void display() const override;
};
#endif
