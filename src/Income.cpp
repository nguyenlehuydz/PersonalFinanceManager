#include "../include/Income.h"
#include <iostream>
using namespace std;
Income :: Income()
{
    sourceId = "";
}
Income :: Income(
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
string Income::getSourceId() const
{
    return sourceId;
}
void Income::display() const
{
    cout << "Income\n"
         << "Amount:" << amount << endl;
}
