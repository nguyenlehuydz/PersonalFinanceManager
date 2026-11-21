#ifndef WALLET_H
#define WALLET_H
#include <string>
using namespace std;
class Wallet
{
  private:
    string WalletId;
    string WalletName;
  public:
    Wallet();
    Wallet ( string Id , string Name);
    void setId(string Id);
    void setName(string Name);
    string getId() const;
    string getName() const;
    void display() const;
    
};
#endif
