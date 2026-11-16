#pragma once
#include <string>
#include "DynamicArray.h"
#include "Wallet.h"
#include "Income.h"
#include "Expense.h"
#include "RecurringTransaction.h"

struct SourceSummary {
    std::string sourceID;
    std::string sourceName;
    long long totalAmount;
};

struct CategorySummary {
    std::string categoryID;
    std::string categoryName;
    long long totalAmount;
};

struct YearSummary {
    int year;
    long long totalIncome;
    long long totalExpense;
    long long netBalance;
};

class FinanceManager {
    private:
        DynamicArray<Wallet> wallets;
        DynamicArray<IncomeSource> incomeSources;
        DynamicArray<ExpenseCategory> expenseCategories;   
        DyanamicArray<Income> incomes;
        DynamicArray<Expense> expenses;
        DynamicArray<RecurrringTransaction> recurrTrans;

        std::string dateFilePath;
        bool XMLStorage;

        int nextIncomeID;
        int nextExpenseID;
        int nextRecurrID;

        void synchNextID();

    public:
        FinanceManager(const std::string& dataFilePath = "data/finance_data.xml", bool useXML = true);

        void initializeDefault();

        bool loadData();
        bool saveData();

        // Wallets
        const DynamicArray<Wallet> &FinanceManager::getWallets() const;
        const Wallet *FinanceManager::findWallet(const std::string &id) const;
        bool FinanceManager::addWallet(const std::string &id, const std::string &name, double iniBalance);
        bool FinanceManager::editWallet(const std::string &id, const std::string &newName, long long newIniBalance);
        bool FinanceManager::deleteWallet(const std::string &id);
        std::string FinanceManager::getWalletName(const std::string &id) const;

        //Income Sources
        const DynamicArray<IncomeSource> &FinanceManager::getIncomeSources() const;
        const IncomeSource *FinanceManager::findIncomeSource(const std::string &id) const;
        bool FinanceManager::addIncomeSource(const std::string &id, const std::string &name);
        bool FinanceManager::editIncomeSource(const std::string &id, const std::string &newName);
        bool FinanceManager::deleteIncomeSource(const std::string &id);
        std::string FinanceManager::getIncomeSourceName(const std::string &id) const;

        // Expense Categories
        const DynamicArray<ExpenseCategory> &FinanceManager::getExpenseCategories() const;
        const ExpenseCategory *FinanceManager::findExpenseCategory(const std::string &id) const;
        bool FinanceManager::addExpenseCategory(const std::string &id, const std::string &name);
        bool FinanceManager::editExpenseCategory(const std::string &id, const std::string &newName);
        bool FinanceManager::deleteExpenseCategory(const std::string &id);
        std::string FinanceManager::getExpenseCategoryName(const std::string &id) const;
};



