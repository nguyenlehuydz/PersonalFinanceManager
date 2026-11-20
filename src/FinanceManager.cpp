#include "../include/FinanceManager.h"
#include "../include/StorageManager.h"
#include <iostream>

FinanceManager::FinanceManager(const std::string &dataFilePath, bool useXML):
    dataFilePath(dataFilePath), XMLStorage(useXML), nextIncomeID(1), 
    nextExpenseID(1), nextRecurID(1) {}

void FinanceManager::synchNextID() {
    for (int i = 0; i < incomes.size(); i++) {
        std::string id = incomes[i].getId();
        if (id.size() > 2 && id[0] == 'I' && id[1] == 'N' && id[2] == 'C') {
            try {
                int num = std::stoi(id.substr(3));
                if (num >= nextIncomeID) nextIncomeID = num + 1;
            }
            catch(...) {}
        }
    }

    for (int i = 0; i < expenses.size(); i++) {
        std::string id = expenses[i].getId();
        if (id.size() > 2 && id[0] == 'E' && id[1] == 'X' && id[2] == 'P') {
            try {
                int num = std::stoi(id.substr(3));
                if (num >= nextExpenseID) nextExpenseID = num + 1;
            }
            catch(...) {}
        }
    }

    for (int i = 0; i < recur.size(); i++) {
        std::string id = recur[i].getId();
        if (id.size() > 2 && id[0] == 'R' && id[1] == 'E' && id[2] == 'C') {
            try {
                int num = std::stoi(id.substr(3));
                if (num >= nextRecurID) nextRecurID = num + 1;
            }
            catch(...) {}
        }
    }
}


bool FinanceManager::loadData() {
    bool check = false;
    if (XMLStorage) {
        check = StorageManager::loadXml(dataFilePath, wallets, incomeSources,
                                     expenseCategories, incomes, expenses,
                                     recur);
    } else {
        check = StorageManager::loadBinary(dataFilePath, wallets, incomeSources,
                                     expenseCategories, incomes, expenses,
                                     recur);
    }
    if (check) synchNextID();
    return check;

}

bool FinanceManager::saveData() {
    if (XMLStorage) {
        return StorageManager::saveXml(dataFilePath, wallets, incomeSources,
                                       expenseCategories, incomes, expenses,
                                       recur);
    } else {
        return StorageManager::saveBinary(dataFilePath, wallets, incomeSources,
                                          expenseCategories, incomes, expenses,
                                          recur);
    }
}

void FinanceManager::initializeDefault() {
    bool isModified = false;
    if (wallets.empty()) {
        isModified = true;
        wallets.push(Wallet("W1", "Cash", 0));
        wallets.push(Wallet("W2", "Bank Account", 0));
        wallets.push(Wallet("W3", "Credit Card", 0));
    }

    if (incomeSources.empty()) {
        isModified = true;
        incomeSources.push(IncomeSource("S1", "Salary"));
        incomeSources.push(IncomeSource("S2", "Bonus"));
        incomeSources.push(IncomeSource("S3", "Savings Interest"));
    }

    if (expenseCategories.empty()) {
        isModified = true;
        expenseCategories.push(ExpenseCategory("C1", "Food"));
        expenseCategories.push(ExpenseCategory("C2", "Rent"));
        expenseCategories.push(ExpenseCategory("C3", "Transportation"));
        expenseCategories.push(ExpenseCategory("C4", "Entertainment"));
    }
    if (isModified) saveData();
}

