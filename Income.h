#ifndef INCOME_H
#define INCOME_H
using namespace std;
#include "Transaction.h"
class Income : public Transaction
{
    private:
    string sourceId;

public:
    Income();

    Income(
        Date date,
        string sourceId,
        double amount,
        string walletId,
        string description
    );

    string getSourceId() const;

    void display() const override;
};
#endif