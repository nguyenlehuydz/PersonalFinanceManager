#include "menu.h"
#include <bits/stdc++.h>
using namespace std;

void showMainMenu() {
    cout << "\n========== PERSONAL FINANCE MANAGER ==========\n";
    cout << "1. Manage Income\n";
    cout << "2. Manage Expenses\n";
    cout << "3. Manage Income Sources\n";
    cout << "4. Manage Expense Categories\n";
    cout << "5. Manage Wallets\n";
    cout << "6. Statistics\n";
    cout << "0. Exit\n";
    cout << "==============================================\n";
    cout << "Enter your choice: ";

}

void runMenu(FinanceManager&manager) {
    int choice;
    do {
        showMainMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        switch (choice) {
        case 1:
            showIncomeMenu(manager);
            break;
        case 2:
            cout << "Expense management is under development.\n";
            break;
        case 3:
            showIncomeSourceMenu(manager);
            break;
        case 4:
            showExpenseCategoryMenu(manager);
            break;
        case 5:
            showWalletMenu(manager);
            break;
        case 6:
            cout << "Statistics is under development.\n";
            break;
        case 0:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

}