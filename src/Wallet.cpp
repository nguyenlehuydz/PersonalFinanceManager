#include "../include/Wallet.h"
#include <iostream>
using namespace std;
Wallet :: Wallet()
{
    WalletId = "";
    WalletName = "";
}
Wallet :: Wallet( string id , string name)
{
    WalletId = id;
    WalletName = name;
}
void Wallet::setId(string id)
{
    WalletId = id;
}
void Wallet::setName(string name)
{
    WalletName = name;
}
string Wallet::getId() const
{
    return WalletId;
}
string Wallet::getName() const
{
    return WalletName;
}
void Wallet::display() const
{
    cout << WalletId
         << "-"
         << WalletName
         << endl;
}
