#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Date.h"
using namespace std;
#include <string>
class Transaction
{
    protected:
    Date date;
    double amount;
    string WalletId;
    string description;
    public:
    Transaction();
    Transaction
    (
        Date date,
        double amount,
        string WalletId,
        string description
    );
    virtual void display() const = 0;
    double getAmount() const;
    string getWalletId() const;

};
#endif
