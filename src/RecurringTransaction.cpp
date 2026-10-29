#include "../include/RecurringTransaction.h"
#include <iostream>
using namespace std;
RecurringTransaction :: RecurringTransaction()
{
    amount = 0;
    hasEndDate = false;
}
RecurringTransaction :: RecurringTransaction(
    TransactionType type,
    Date startDate,
    Date endDate,
    
    bool hasEndDate,
    
    string SourceOrCategoryId,
    string WalletId,

    double amount,
    string decription
)
{
    this-> type = type;
    this-> startDate = startDate;
    this-> endDate = endDate;
    this-> hasEndDate = hasEndDate;
    this-> SourceOrCategoryId = SourceOrCategoryId;
    this-> WalletId = WalletId;
    this-> amount = amount;
    this-> decription = decription;
}
void RecurringTransaction::display() const
{
    cout << "Recurring Transaction\n"
         << "Amount:" << amount << endl;
}
