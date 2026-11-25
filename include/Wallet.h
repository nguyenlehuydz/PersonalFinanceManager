#ifndef WALLET_H
#define WALLET_H
#include <string>
class Wallet
{
private:
    std::string id;
    std::string name;
public:
    Wallet();
    Wallet(
        const std::string& id,
        const std::string& name);
    void setId(const std::string& id);
    void setName(const std::string& name);
    const std::string& getId() const;
    const std::string& getName() const;
    void display() const;
};
#endif
