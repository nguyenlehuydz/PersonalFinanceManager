#ifndef STATISTIC_H
#define STATISTIC_H
#include <vector>
#include "Transaction.h"
class Statistic
{
private:
    std::vector<const Transaction*> transactions;
public:
    Statistic();
    Statistic(
        const std::vector<const Transaction*>& transactions);
    double getTotalIncome() const;
    double getTotalExpense() const;
    double getBalance() const;
    void displayReport() const;
};
#endif
