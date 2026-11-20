#include "../include/FinanceManager.h"
#include <iomanip>
#include <sstream>

const DynamicArray<RecurringTransaction> &FinanceManager::getRecurringTransactions() const {
    return recur;
}

bool FinanceManager::addRecurringTransaction(RecurringType type, const std::string &sourceId, long long amount, 
                                             const std::string &walletId, const std::string &description, const Date &startDate,
                                             bool hasEndDate, const Date &endDate, int dayOfMonth) {
    std::ostringstream oss;
    oss << "REC" << std::setfill('0') << std::setw(4) << nextRecurID++;
    std::string id = oss.str();

    recur.push(RecurringTransaction(id, type, sourceId, amount, walletId, description, startDate, hasEndDate, endDate, dayOfMonth));
    saveData();
    return true;
}

bool FinanceManager::deleteRecurringTransaction(const std::string &id) {
    for (int i = 0; i < recur.size(); i++) {
        if (recur[i].getId() == id) {
            recur.remove(i);
            saveData();
            return true;
        }
    }
    return false;
}

int FinanceManager::checkAndProcessRecurring(const Date &curDate) {
    int cnt = 0;
    auto isBefore = [](const Date &a, const Date &b) {
        if (a.year < b.year) return true;
        else if (a.year == b.year && a.month < b.month) return true;
        else if (a.year == b.year && a.month == b.month && a.day < b.day) return true;
        else return false; 
    };
    
    for (int i = 0; i < recur.size(); i++) {
        const RecurringTransaction &rec = recur[i];
        int endYear = curDate.year;
        int endMonth = curDate.month;

        if (rec.hasEndDate()) {
            if (rec.getEndDate().year < endYear || (rec.getEndDate().year == endYear && rec.getEndDate().month < endMonth)) {
                endYear = rec.getEndDate().year;
                endMonth = rec.getEndDate().month;
            }
        }

        int year = rec.getStartDate().year, month = rec.getStartDate().month;
        while (year < endYear || (year == endYear && month <= endMonth)) {
            int maxDays = Date::DateofMonth(year, month);
            int day = (maxDays < rec.getDayOfMonth()) ? maxDays : rec.getDayOfMonth();
            Date transDate(year, month, day);

            bool isOutRange = false;
            isOutRange |= isBefore(transDate, rec.getStartDate());
            isOutRange |= isBefore(curDate, transDate);
            isOutRange |= (rec.hasEndDate() && isBefore(rec.getEndDate(), transDate));

            if (!isOutRange) {
                std::ostringstream oss;
                oss << "[Rec:" << rec.getId() << ":" << year << "-" << std::setfill('0') << std::setw(2) << month << "]";
                std::string tag = oss.str();

                bool exist = false;
                if (rec.getType() == RecurringType::INCOME) {
                    for (int j = 0; j < incomes.size(); j++) {
                        if (incomes[j].getDescription().find(tag) != std::string::npos) {
                            exist = true;
                            break;
                        }
                    }
                }
                else {
                    for (int j = 0; j < expenses.size(); j++) {
                        if (expenses[j].getDescription().find(tag) != std::string::npos) {
                            exist = true;
                            break;
                        }
                    }
                }

                if (!exist) {
                    std::string fullDesc = rec.getDescription();
                    if (!fullDesc.empty()) fullDesc += ' ';
                    fullDesc += tag;

                    if (rec.getType() == RecurringType::INCOME) {
                        addIncome(transDate, rec.getSourceOrCategoryId(), rec.getAmount(), rec.getWalletId(), fullDesc);
                    }
                    else {
                        addExpense(transDate, rec.getSourceOrCategoryId(), rec.getAmount(), rec.getWalletId(), fullDesc);
                    }
                    cnt++;
                }
            }
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
    return cnt;
}