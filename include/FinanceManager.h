#pragma once
#include <string>

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



