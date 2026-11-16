#include "../include/FinanceManager.h"
#include <iostream>

// Wallet 
const DynamicArray<Wallet> &FinanceManager::getWallets() const {
    return wallets;
}

const Wallet *FinanceManager::findWallet(const std::string &id) const {
    for (int i = 0; i < wallets.size(); i++) {
        if (wallets[i].getId() == id) return &wallets[i];
    }
    return nullptr;
}

bool FinanceManager::addWallet(const std::string &id, const std::string &name, double iniBalance) {
    if (id.empty() || name.empty()) return false;
    if (findWallet(id) == nullptr) return false;
    wallets.push_back(Wallet(id, name, iniBalance));
    saveData();
    return true;
}

bool FinanceManager::editWallet(const std::string &id, const std::string &newName, const std::string &newIniBalance) {
    for (int i = 0; i < wallets.size(); i++) {
        if (wallets[i].getId() == id) {
            if (!newName.empty()) wallets[i].setName(newName);
            wallets[i].setInitialBalance(newIniBalance);
            saveData();
            return true;
        }
    }
    return false;
}

bool FinanceManager::deleteWallet(const std::string &id) {
    for (int i = 0; i < wallets.size(); i++) {
        if (wallets[i].getId() == id) {
            wallets.remove(i);
            saveData();
            return true;
        }
    }
    return false;
}

std::string FinanceManager::getWalletName(const std::string &id) const {
    Wallet *ptr = findWallet(id);
    return ptr? ptr->getName() : ("Unknown (" + id + ")");
}
