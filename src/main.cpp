#include <iostream>
#include "../include/FinanceManager.h"
#include "../include/menu.h"

int main() {
    std::cout << "Starting Personal Finance Manager..." << '\n';
    
    FinanceManager manager("data/finance_data.xml", true);
    if (!manager.loadData()) {
        std::cout << "[i] Initializing default wallets and categories..." << '\n';
        manager.initializeDefault();
        manager.saveData();
    }

    Date today = Date::today();
    int recCnt = manager.checkAndProcessRecurring(today);
    if (recCnt) {
        std::cout << "[i] Processed " << recCnt << " recurring transaction for the current cycle ("
                  << (today.month < 10? "0" : "") << today.month << "/" << today.year << ")";
    }

    return 0;
}