#include "../include/FinanceManager.h"
#include <iostream>

// Wallet List
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
    const Wallet *ptr = findWallet(id);
    return ptr? ptr->getName() : ("Unknown (" + id + ")");
}

// Income Sources
const DynamicArray<IncomeSource> &FinanceManager::getIncomeSources() const {
    return incomeSources;
}

const IncomeSource *FinanceManager::findIncomeSource(const std::string &id) const {
    for (int i = 0; i < incomeSources.size(); i++) {
        if (incomeSources.getId() == id) {
            return &incomeSources[i];
        }
    }
    return nullptr;
}

bool FinanceManager::addIncomeSource(const std::string &id, const std::string &name) {
    if (id.empty() || name.empty()) return false;
    if (findIncomeSource(id) != nullptr) return false;
    incomeSources.push(IncomeSource(id, name));
    saveData();
    return true;
}

bool FinanceManager::editIncomeSource(const std::string &id, const std::string &newName) {
    for (int i = 0; i < incomeSources.size(); i++) {
        if (incomeSources[i].getId() == id) {
            if (!newName.empty()) incomeSources[i].setName(newName);
            saveData();
            return true;
        }
    }
    return false;
}

bool FinanceManager::deleteIncomeSource(const std::string &id) {
    for (int i = 0; i < incomeSources.size(); i++) {
        if (incomeSources[i].getId() == id) {
            incomeSources.remove(id);
            saveData();
            return true;
        }
    }
    return false;
}
std::string FinanceManager::getIncomeSourceName(const std::string &id) const{
    const IncomeSource *ptr = findIncomeSource(id);
    return ptr? ptr->getName() : ("Unknown (" + id ")");
}

// Expense Categories
const DynamicArray<ExpenseCategory> FinanceManager::getExpenseCategories() const {
    return expenseCategories;
}

const ExpenseCategory *FinanceManager::findExpenseCategory(const std::string &id) const {
    for (int i = 0; i < expenseCategories.size(); i++) {
        if (expenseCategories[i].getId() == id) {
            return &expenseCategories[i];
        }
    }
    return nullptr;
}

bool FinanceManager::addExpenseCategory(const std::string &id, const std::string &name) {
    if (id.empty() || name.empty()) return false;
    if (findExpenseCategory(id) != nullptr) return false;
    expenseCategories.push(ExpenseCategory(id, name));
    saveData();
    return true;
}

bool FinanceManager::editExpenseCategory(const std::string &id, const std::string &newName) {
    for (int i = 0; i < expenseCategories.size(); i++) {
        if (expenseCategories[i].getId() == id) {
            if (!newName.empty()) expenseCategories.setName(newName);
            saveData();
            return true;
        }
    }
    return false;
}

bool FinanceManager::deleteExpenseCategory(const std::string &id) {
    for (int i = 0; i < expenseCategories.size(); i++) {
        if (expenseCategories[i].getId() == id) {
            expenseCategories.remove(i);
            saveData();
            return true;
        }
    }
    return false;
}

std::string FinanceManager::getExpenseCategoryName(const std::string &id) {
    const ExpenseCategory *ptr = findExpenseCategory(id);
    return ptr? ptr->getName() : ("Unknown (" + id + ")");
}
