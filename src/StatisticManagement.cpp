#include "../include/FinanceManager.h"

// Balances
long long FinanceManager::getWalletBalance(const std::string &walletId) const {
    const Wallet *ptr = findWallet(walletId);
    if (!ptr) return 0;
    long long balance = ptr->getInitialBalance();
    for (int i = 0; i < incomes.size(); i++) {
        if (incomes[i].getWalletId() == walletId) {
            balance += incomes[i].getAmount();
        }
    }
    for (int i = 0; i < expenses.size(); i++) {
        if (expenses[i].getWallet() == walletId) {
            balance += expenses[i].getAmount();
        }
    }
    return balance;
}

long long FinanceManager::getTotalBalance() const {
    long long total = 0;
    for (int i = 0; i < wallets.size(); i++) {
        total += getWalletBalance(wallets[i].getId());
    }
    return total;
}