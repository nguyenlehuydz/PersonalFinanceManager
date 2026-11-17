#include "../include/FinanceManager.h"
#include <iomanip>

// Incomes
const DynamicArray<Income> &FinanceManager::getIncomes() const {
    return incomes;
}

bool FinanceManager::addIncome(const Date &date, const std::string &sourceId, long long amount, const std::string &walletId, const std::string &description, const std::string &customId) {
    std::string id = customId;
    if (id.empty()) {
        std::ostringstream oss;
        oss << "INC" << std::setfill('0') << std::setw(4) << nextIncomeID++;
        id = oss.str();
    }
    incomes.push(Income(id, date, sourceId, amount, walletId, description));
    saveData();
    return true;
}

bool FinanceManager::deleteIncome(const std::string &id) {
    for (int i = 0; i < incomes.size(); i++) {
        if (incomes[i].getId() == id) {
            incomes.remove(i);
            saveData();
            return true;
        }
    }
    return false;
}

// Expenses
const DynamicArray<Expense> &FinanceManager::getExpenses() const {
    return expenses;
}

bool FinanceManager::addExpense(const Date &date, const std::string &categoryId, long long amount, const std::string &walletId, const std::string &description, const std::string &customId) {
    std::string id = customId;
    if (id.empty()) {
        std::ostringstream oss;
        oss << "EXP" << std::setfill("0") << std::setw(4) << nextExpenseID++;
        id = oss.str();
    }
    expenses.push(Expense(id, date, categoryId, amount, walletId, description));
    saveData();
    return true;
}

bool FinanceManager::deleteExpense(const std::string &id) {
    for (int i = 0; i < expenses.size(); i++) {
        if (expenses[i].getId() == id) {
            expenses.remove(i);
            saveData();
            return true;
        }
    }
    return false;
}