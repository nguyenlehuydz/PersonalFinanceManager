#include "../include/Transaction.h"
using namespace std;
Transaction :: Transaction()
{
    amount = 0;
}
Transaction :: Transaction(
    Date date,
    double amount,
    string WalletId,
    string description
)
{
    this-> date = date;
    this-> amount= amount;
    this-> WalletId = WalletId;
    this-> description = description;
}
double Transaction::getAmount() const
{
    return amount;
}
string Transaction::getWalletId() const
{
    return WalletId;
}
