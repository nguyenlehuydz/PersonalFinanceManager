#include "../include/Expense.h"
#include <iostream>
using namespace std;
Expense :: Expense()
{
    sourceId = "";
}
Expense :: Expense(
    Date date,
    string sourceId,
    double amount,
    string WalletId,
    string decription
)
    : Transaction(date , amount , WalletId, decription)
{
    this-> sourceId = sourceId;
}
string Expense::getsourceId() const
{
    return sourceId;
}
void Expense::display() const
{
    cout << "Expense\n"
         << "Amount:" << amount << endl;
}
