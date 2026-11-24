#include <iostream>
#include "../include/FinanceManager.h"
#include "../include/menu.h"

int main() {
    std::cout << "Starting Personal Finance Manager..." << '\n';
    
    FinanceManager manager("data/finance_data.xml", true);
    if (!manager.loadData()) {
        std::cout << "Initializing default wallets and categories..." << '\n';
        manager.initializeDefault();
        manager.saveData();
    }

    return 0;
}