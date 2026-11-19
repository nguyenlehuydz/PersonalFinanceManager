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
        DynamicArray<Income> incomes;
        DynamicArray<Expense> expenses;
        DynamicArray<RecurringTransaction> recur;

        std::string dataFilePath;
        bool XMLStorage;

        int nextIncomeID;
        int nextExpenseID;
        int nextRecurID;

        void synchNextID();

    public:
        FinanceManager(const std::string& dataFilePath = "data/finance_data.xml", bool useXML = true);

        void initializeDefault();

        bool loadData();
        bool saveData();

        // Wallets
        const DynamicArray<Wallet> &getWallets() const;
        const Wallet *findWallet(const std::string &id) const;
        bool addWallet(const std::string &id, const std::string &name, long long iniBalance = 0);
        bool editWallet(const std::string &id, const std::string &newName, long long newIniBalance);
        bool deleteWallet(const std::string &id);
        std::string getWalletName(const std::string &id) const;

        //Income Sources
        const DynamicArray<IncomeSource> &getIncomeSources() const;
        const IncomeSource *findIncomeSource(const std::string &id) const;
        bool addIncomeSource(const std::string &id, const std::string &name);
        bool editIncomeSource(const std::string &id, const std::string &newName);
        bool deleteIncomeSource(const std::string &id);
        std::string getIncomeSourceName(const std::string &id) const;

        // Expense Categories
        const DynamicArray<ExpenseCategory> &getExpenseCategories() const;
        const ExpenseCategory *findExpenseCategory(const std::string &id) const;
        bool addExpenseCategory(const std::string &id, const std::string &name);
        bool editExpenseCategory(const std::string &id, const std::string &newName);
        bool deleteExpenseCategory(const std::string &id);
        std::string getExpenseCategoryName(const std::string &id) const;

        // Incomes  
        const DynamicArray<Income> &getIncomes() const;
        bool addIncome(const Date &date, const std::string &sourceId, long long amount, const std::string &walletId, const std::string &description, const std::string &customId = "");
        bool deleteIncome(const std::string &id);

        // Expenses
        const DynamicArray<Expense> &getExpenses() const;
        bool addExpense(const Date &date, const std::string &categoryId, long long amount, const std::string &walletId, const std::string &description, const std::string &customId = "");
        bool deleteExpense(const std::string &id);

        // Recurring Management
        const DynamicArray<RecurringTransaction> &getRecurringTransactions() const;
        bool addRecurringTransaction(RecurringType type, const std::string &sourceId, long long amount, 
                                             const std::string &walletId, const std::string &description, const Date &startDate,
                                             bool hasEndDate, const Date &endDate, int dayOfMonth);
        bool deleteRecurringTransaction(const std::string &id);
        int checkAndProcessRecurring(const Date &curDate);

        // Balance Calculations
        long long getWalletBalance(const std::string &walletId) const;
        long long getTotalBalance() const;

        //Statistics
        void getTimeStatistic(const Date &start, const Date &end, long long &totalInc, long long totalEx, long long &netBal);
        void getTimeAndWalletStatistics(const Date &start, const Date &end, const std::string &walletId, 
                                                long long &totalInc, long long &totalEx, long long &netBal);
        DynamicArray<YearSummary> getAnnualOverview(const DynamicArray<int> &years) const;
        DynamicArray<SourceSummary> getIncomeBreakdown(const DynamicArray<int> &years, long long &totalInc);
};



