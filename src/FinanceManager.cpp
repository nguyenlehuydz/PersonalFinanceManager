#include "../include/FinanceManager.h"
#include <iostream>

FinanceManager::FinanceManager(const std::string &dataFilePath, bool useXML):
    dataFilePath(dataFilePath), XMLStorage(useXML), nextIncomeID(1), 
    nextExpenseID(1), nextRecurringID(1) {}

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
        std::string id = expenses[i].getid();
        if (id.size() > 2 && id[0] == 'E' && id[1] == 'X' && id[2] == 'P') {
            try {
                int num = std::stoi(id.substr(3));
                if (num >= nextExpenseID) nextExpenseID = num + 1;
            }
        }
    }

    for (int i = 0; i < recurrTrans.size(); i++) {
        std::string id = recurrTrans[i].getId();
        if (id.size() > 2 && id[0] == 'R' && id[1] == 'E' && id[2] == 'C') {
            try {
                int num = std::stoi(id.substr(3));
                if (num >= nextRecurrID) nextRecurrID = num + 1;
            }
        }
    }
}

void FinanceManager::initializeDefault() {
    if (wallets.empty()) {
        wallets.push_back(Wallet("W1", "Cash", 0));
        wallets.push_back(Wallet("W2", "Bank Account", 0));
        wallets.push_back(Wallet("W3", "Credit Card", 0));
    }

    if (incomeSources.empty()) {
        incomeSources.push_back(IncomeSource("S1", "Salary"));
        incomeSources.push_back(IncomeSource("S2", "Bonus"));
        incomeSources.push_back(IncomeSource("S3", "Savings Interest"));
    }

    if (expenseCategories.empty()) {
        expenseCategories.push_back(ExpenseCategory("C1", "Food"));
        expenseCategories.push_back(ExpenseCategory("C2", "Rent"));
        expenseCategories.push_back(ExpenseCategory("C3", "Transportation"));
        expenseCategories.push_back(ExpenseCategory("C4", "Entertainment"));
    }
}


bool FinanceManager::loadData() {
    bool check = false;
    if (XMLStorage) {
        check = StorageManager::loadXml(dataFilePath, wallets, incomeSources,
                                     expenseCategories, incomes, expenses,
                                     recurringTransactions);
    } else {
        check = StorageManager::loadBinary(dataFilePath, wallets, incomeSources,
                                     expenseCategories, incomes, expenses,
                                     recurringTransactions);
    }
    if (check) synchNextID();
    return check;

}

bool FinanceManager::saveData() {
    if (XMLStorage) {
        return StorageManager::saveXml(dataFilePath, wallets, incomeSources,
                                       expenseCategories, incomes, expenses,
                                       recurringTransactions);
    } else {
        return StorageManager::saveBinary(dataFilePath, wallets, incomeSources,
                                          expenseCategories, incomes, expenses,
                                          recurringTransactions);
    }
}

