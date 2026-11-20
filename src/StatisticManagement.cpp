#include "../include/FinanceManager.h"

// Balance Calculations
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
        if (expenses[i].getWalletId() == walletId) {
            balance -= expenses[i].getAmount();
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

// Statistics
void FinanceManager::getTimeStatistic(const Date &start, const Date &end, long long &totalInc, long long &totalEx, long long &netBal) const {
    totalInc = totalEx = 0;
    for (int i = 0; i < incomes.size(); i++) {
        if (incomes[i].getDate() >= start && incomes[i].getDate() <= end) {
            totalInc += incomes[i].getAmount();
        }
    }
    for (int i = 0; i < expenses.size(); i++) {
        if (expenses[i].getDate() >= start && expenses[i].getDate() <= end) {
            totalEx += expenses[i].getAmount();
        }
    }
    netBal = totalInc - totalEx;
}

void FinanceManager::getTimeAndWalletStatistics(const Date &start, const Date &end, const std::string &walletId, 
                                                long long &totalInc, long long &totalEx, long long &netBal) const {
    totalInc = totalEx = 0;
    for (int i = 0; i < incomes.size(); i++) {
        if (incomes[i].getWalletId() == walletId) {
            if (incomes[i].getDate() >= start && incomes[i].getDate() <= end) {
                totalInc += incomes[i].getAmount();
            }
        }
    }
    for (int i = 0; i < expenses.size(); i++) {
        if (expenses[i].getWalletId() == walletId) {
            if (expenses[i].getDate() >= start && expenses[i].getDate() <= end) {
                totalEx += expenses[i].getAmount();
            }
        }
    }
    netBal = totalInc - totalEx;
}

DynamicArray<YearSummary> FinanceManager::getAnnualOverview(const DynamicArray<int> &years) const {
    DynamicArray<YearSummary> result;
    for (int i = 0; i < years.size(); i++) {
        int year = years[i];
        YearSummary ans;
        ans.year = year;
        ans.totalIncome = ans.totalExpense = ans.netBalance = 0;

        for (int j = 0; j < incomes.size(); j++) {
            if (incomes[j].getDate().year == year) {
                ans.totalIncome += incomes[j].getAmount();
            }
        }

        for (int j = 0; j < expenses.size(); j++) {
            if (expenses[j].getDate().year == year) {
                ans.totalExpense += expenses[j].getAmount();
            }
        }

        ans.netBalance = ans.totalIncome - ans.totalExpense;
        result.push(ans);
    }
    return result;
}

DynamicArray<SourceSummary> FinanceManager::getIncomeBreakdown(const DynamicArray<int> &years, long long &totalInc) const {
    totalInc = 0;
    DynamicArray<SourceSummary> res;
    for (int i = 0; i < incomeSources.size(); i++) {
        SourceSummary ans;
        ans.sourceID = incomeSources[i].getId();
        ans.sourceName = incomeSources[i].getName();
        ans.totalAmount = 0;

        for (int j = 0; j < incomes.size(); j++) {
            if (incomes[j].getSourceId() == incomeSources[i].getId()) {
                for (int t = 0; t < years.size(); t++) {
                    if (years[t] == incomes[j].getDate().year) {
                        ans.totalAmount += incomes[j].getAmount();
                        break;
                    }
                }
            }
        }
        totalInc += ans.totalAmount;
        res.push(ans);
    }
    return res;
}

DynamicArray<CategorySummary> FinanceManager::getExpenseBreakdown(const DynamicArray<int> &years, long long &totalExp) const {
    totalExp = 0;
    DynamicArray<CategorySummary> res;
    for (int i = 0; i < expenseCategories.size(); i++) {
        CategorySummary ans;
        ans.categoryID = expenseCategories[i].getId();
        ans.categoryName = expenseCategories[i].getName();
        ans.totalAmount = 0;

        for (int j = 0; j < expenses.size(); j++) {
            if (expenses[j].getCategoryId() == ans.categoryID) {
                for (int t = 0; t < years.size(); t++) {
                    if (years[t] == expenses[j].getDate().year) {
                        ans.totalAmount += expenses[j].getAmount();
                        break;
                    }
                }
            }
        }
        totalExp += ans.totalAmount;
        res.push(ans);
    }
    return res;
}

DynamicArray<int> FinanceManager::getYears() const {
    DynamicArray<int> years;

    for (int i = 0; i < incomes.size(); i++) {
        bool check = true;
        int y = incomes[i].getDate().year;
        for (int j = 0; j < years.size(); j++) {
            if (years[j] == y) {
                check = false;
                break;
            }
        }
        if (check) years.push(y);
    }

    for (int i = 0; i < expenses.size(); i++) {
        bool check = true;
        int y = expenses[i].getDate().year;
        for (int j = 0; j < years.size(); j++) {
            if (years[j] == y) {
                check = false;
                break;
            }
        }
        if (check) years.push(y);
    }

    return years;
}