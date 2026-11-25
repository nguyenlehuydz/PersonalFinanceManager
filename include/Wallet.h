#ifndef WALLET_H
#define WALLET_H
#include <string>
class Wallet
{
private:
    std::string id;
    std::string name;
    long long initialBalance;
public:
    Wallet();
    Wallet(
        const std::string& id,
        const std::string& name,
        long long initialBalance = 0);
    const std::string& getId() const;
    void setId(const std::string& id);
    const std::string& getName() const;
    void setName(const std::string& name);
    long long getInitialBalance() const;
    void setInitialBalance(long long balance);
};
#endif
