#ifndef RECURRINGTRANSACTION_H
#define RECURRINGTRANSACTION_H
using namespace std;
#include <string>
#include "Date.h"
enum TransactionType
{
    INCOMETYPE,
    EXPENSETYPE
};
class RecurringTransaction
{
    private:
    TransactionType type;
    Date startDate;
    Date endDate;
    
    bool hasEndDate;
    
    string SourceOrCategoryId;
    string WalletId;

    double amount;
    string decription;

    public:
    RecurringTransaction();
    RecurringTransaction(
    TransactionType type,
    Date startDate,
    Date endDate,
    
    bool hasEndDate,
    
    string SourceOrCategoryId,
    string WalletId,

    double amount,
    string decription
    );
    void display() const;

};
#endif
