#ifndef RECURRING_TRANSACTION_H
#define RECURRING_TRANSACTION_H
#include <string>
#include "Date.h"
enum class RecurringType
{
    INCOME,
    EXPENSE
};
class RecurringTransaction
{
private:
    std::string id;
    RecurringType type;
    std::string sourceOrCategoryId;
    long long amount;
    std::string walletId;
    std::string description;
    Date startDate;
    bool hasEndDateFlag;
    Date endDate;
    int dayOfMonth;
public:
    RecurringTransaction();
    RecurringTransaction(
        const std::string& id,
        RecurringType type,
        const std::string& sourceOrCategoryId,
        long long amount,
        const std::string& walletId,
        const std::string& description,
        const Date& startDate,
        bool hasEndDate = false,
        const Date& endDate = Date(),
        int dayOfMonth = 1);
    const std::string& getId() const;
    void setId(const std::string& id);
    RecurringType getType() const;
    void setType(RecurringType type);
    const std::string& getSourceOrCategoryId() const;
    void setSourceOrCategoryId(const std::string& sourceOrCategoryId);
    long long getAmount() const;
    void setAmount(long long amount);
    const std::string& getWalletId() const;
    void setWalletId(const std::string& walletId);
    const std::string& getDescription() const;
    void setDescription(const std::string& description);
    const Date& getStartDate() const;
    void setStartDate(const Date& startDate);
    bool hasEndDate() const;
    void setHasEndDate(bool hasEndDate);
    const Date& getEndDate() const;
    void setEndDate(const Date& endDate);
    int getDayOfMonth() const;
    void setDayOfMonth(int dayOfMonth);
};
#endif
