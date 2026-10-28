#ifndef EXPENSE_H
#define EXPENSE_H
#include "Transaction.h"
using namespace std;
class Expense : public Transaction
{
    private:
    string sourceId;

public:
    Expense();
    Expense(
        Date date,
        string sourceId,
        double amount,
        string walletId,
        string description
    );
    string getsourceId() const;

    void display() const override;
};
#endif