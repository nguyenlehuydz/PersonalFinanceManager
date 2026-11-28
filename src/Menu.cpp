#include "../include/Menu.h"
#include "../include/FinanceManager.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>

namespace Color {
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string CYAN = "\033[36m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string RED = "\033[31m";
    const std::string MAGENTA = "\033[35m";
}

void Menu::clearScreen() const {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}


void Menu::showHeader() const {
    std::cout << Color::CYAN << Color::BOLD;
    std::cout << "  ============================================================================\n";
    std::cout << "  |                      PERSONAL FINANCE MANAGEMENT                          |\n";
    std::cout << "  ============================================================================\n";
    std::cout << Color::RESET;
    return;
}

void Menu::showDashboard()const {
    showHeader();
    long long totalBalance = financeManager.getTotalBalance();
    std::cout << Color::BOLD << "  TOTAL BALANCE: " << totalBalance << " VND\n" << Color::RESET;
    std::cout << "  --------------------------------------------------\n";
    showWallet();
    std::cout << "  --------------------------------------------------\n";
    std::cout << Color::YELLOW << "  NAVIGATION MENU:\n" << Color::RESET;
    std::cout << "  " << Color::GREEN << "[1]" << Color::RESET << " Wallet Management\n";
    std::cout << "  " << Color::GREEN << "[2]" << Color::RESET << " Transaction\n";
    std::cout << "  " << Color::GREEN << "[3]" << Color::RESET << " Recurring Transactions\n";
    std::cout << "  " << Color::GREEN << "[4]" << Color::RESET << " Statistics\n";
    std::cout << "  " << Color::RED << "[0]" << Color::RESET << " Exit Application\n";
    std::cout << "  --------------------------------------------------\n";
    std::cout << Color::BOLD << "  Enter your choice: " << Color::RESET;
    return;
}

void Menu::handleChoice(int &choice, bool& isRunning) {
    std::cout << "\n";
    switch (choice) {
        case 1:
            std::cout << Color::MAGENTA << "  [INFO] Opening Wallet Management..." << Color::RESET << "\n";
            runWalletManager();
            break;
        case 2:
            std::cout << Color::MAGENTA << "  [INFO] Opening Transaction..." << Color::RESET << "\n";
            runTransactionManager();
            break;
        case 3:
            std::cout << Color::MAGENTA << "  [INFO] Opening Recurring Transactions..." << Color::RESET << "\n";
            runRecurringManager();
            break;
        case 4:
            std::cout << Color::MAGENTA << "  [INFO] Opening Statistics..." << Color::RESET << "\n";
            runStatisticsManager();
            break;
        case 0:
            std::cout << Color::GREEN << "  Thank you for using the application. Goodbye!" << Color::RESET << "\n";
            isRunning = false;
            break;
        default:
            std::cout << Color::RED << "  [ERROR] Invalid choice! Please select a number from 0 to 4." << Color::RESET << "\n";
    }
    return;
}

void Menu::run() {
    bool isRunning = true;
    int choice{};
    while (isRunning) {
        clearScreen();
        showHeader();
        showDashboard();
        if (!(std::cin >> choice)) {
            std::cout << "\n  " << Color::RED << "[ERROR] Please enter a valid integer!" << Color::RESET << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n  Press Enter to continue...";
            std::cin.get();
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        handleChoice(choice, isRunning);
        if (isRunning) {
            std::cout << "\n  Press Enter to continue...";
            std::cin.get();
        }
    }
    return;
}

void Menu::showWallet() const {
    std::cout << Color::BOLD << "  WALLET BALANCES:\n" << Color::RESET;
    if (financeManager.wallets.size() == 0) {
        std::cout << "    (No wallet is added)\n";
    }
    else{
        std::cout << "    " 
                  << std::left  << std::setw(6)  << "STT" 
                  << std::left  << std::setw(20) << "Bank Account" 
                  << std::right << std::setw(18) << "Cash (VND)" << "\n";
        std::cout << "    ------------------------------------------\n";
        for(int i=0;i<financeManager.wallets.size();i++){
            const Wallet& w = financeManager.wallets[i];
            std::cout << "    " 
                      << std::left  << std::setw(6)  << ("[" + std::to_string(i + 1) + "]")
                      << std::left  << std::setw(20) << clipText(financeManager.getWalletName(w.getId()),20)
                      << std::right << std::setw(18) << clipText(financeManager.getWalletBalance(w.getId()),18)
                      << "\n";
        }
    }
    return;
}

void Menu::showWalletVer2() const {
    std::cout << Color::BOLD << "  WALLET BALANCES:\n" << Color::RESET;
    if (financeManager.wallets.size() == 0) {
        std::cout << "    (No wallet is added)\n";
    }
    else{
        std::cout << "  "
                << std::left  << std::setw(6)  << "STT"
                << std::left  << std::setw(10) << "ID"
                << std::left  << std::setw(22) << "Wallet Name"
                << std::right << std::setw(18) << "Balance"
                << "\n";
        std::cout << "  ----------------------------------------------------------\n";

        for (int i = 0; i < financeManager.wallets.size(); ++i) {
            const Wallet& w = financeManager.wallets[i];
            std::cout << "  "
                    << std::left  << std::setw(6)  << ("[" + std::to_string(i + 1) + "]")
                    << std::left  << std::setw(10) << clipText(w.getId(),10)
                    << std::left  << std::setw(22) << clipText(w.getName(),22)
                    << std::right << std::setw(18) << formatMoney(w.getBalance())
                    << "\n";
        }
    }
    std::cout << "  --------------------------------------------------\n";
    return;
}

void Menu::showHeaderWallet() const {
    std::cout << Color::CYAN << Color::BOLD;
    std::cout << "  ============================================================================\n";
    std::cout << "  |                            WALLET MANAGEMENT                              |\n";
    std::cout << "  ============================================================================\n";
    std::cout << Color::RESET;
    return;
}

void Menu::runWalletManager() {
    bool isRunningWalletManager = true;
    int choiceWalletManager{};
    while (isRunningWalletManager) {
        clearScreen();
        showWalletDashboard();
        if (!(std::cin >> choiceWalletManager)) {
            std::cout << "\n  " << Color::RED << "[ERROR] Please enter a valid integer!" << Color::RESET << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n  Press Enter to continue...";
            std::cin.get();
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        handleChoiceWallet(choiceWalletManager, isRunningWalletManager);
        if (isRunningWalletManager) {
            std::cout << "\n  Press Enter to continue...";
            std::cin.get();
        }
    }
    return;
}

void Menu::showWalletDashboard()const {
    showHeaderWallet();
    showWalletVer2();
    std::cout << "  " << Color::GREEN << "[1]" << Color::RESET << " Add Wallet\n";
    std::cout << "  " << Color::GREEN << "[2]" << Color::RESET << " Edit Wallet\n";
    std::cout << "  " << Color::GREEN << "[3]" << Color::RESET << " Delete Wallet\n";
    std::cout << "  " << Color::GREEN << "[0]" << Color::RESET << " Back to Dashboard\n";
    std::cout << "  --------------------------------------------------\n";
    std::cout << Color::BOLD << "  Enter your choice: " << Color::RESET;
    return;
}

void Menu::handleChoiceWallet(int &choiceWalletManager, bool& isRunningWalletManager) {
    std::cout << "\n";
    switch (choiceWalletManager) {
        case 1:
            std::cout << Color::MAGENTA << "  [INFO] Pls enter your wallet's id, name and balance respectively: " << Color::RESET << "\n";
            std::string line,name,id;
            long long balance;
            readWalletLine(line,id,name,balance);
            if(financeManager.addWallet(id,name,balance))std::cout << Color::MAGENTA << " SAVED!!! " << Color::RESET << "\n";
            else std::cout << Color::MAGENTA << "  [ERROR]Can not save!!! " << Color::RESET << "\n";
            break;
        case 2:
            std::cout << Color::MAGENTA << "  [INFO] Wallet will be updated for the entered ID." << Color::RESET << "\n";
            std::cout << Color::MAGENTA << "  [INFO] Pls enter your wallet's id, name and balance respectively: " << Color::RESET << "\n";
            std::string line,name,id;
            long long balance;
            readWalletLine(line,id,name,balance);
            if(financeManager.editWallet(id,name,balance))std::cout << Color::MAGENTA << " SAVED!!! " << Color::RESET << "\n";
            else std::cout << Color::MAGENTA << " [ERROR]Id was not found!!!" << Color::RESET << "\n";
            break;
        case 3:
            std::cout << Color::MAGENTA << "  [INFO] Wallet will be deleted for the entered ID." << Color::RESET << "\n";
            std::cout << Color::MAGENTA << "  [INFO] Pls enter your wallet's id: " << Color::RESET << "\n";
            std::string id;
            getline(cin,id);
            if(financeManager.deleteWallet(id))std::cout << Color::MAGENTA << " SAVED!!! " << Color::RESET << "\n";
            else std::cout << Color::MAGENTA << " [ERROR]Id was not found!!!" << Color::RESET << "\n";
            break;
        case 0:
            std::cout << Color::GREEN << "  Return to Dashboard now!!!" << Color::RESET << "\n";
            isRunningWalletManager = false;
            break;
        default:
            std::cout << Color::RED << "  [ERROR] Invalid choice! Please select a number from 0 to 3." << Color::RESET << "\n";
    }
    return;
}

void readWalletLine(const std::string& line, std::string& id, std::string& name, long long& balance) {
    std::istringstream iss(line);
    std::string token, lastToken;
    name.clear();
    balance = 0;

    iss >> id;

    while (iss >> token) {
        if (!lastToken.empty()) {
            if (!name.empty()) name += " ";
            name += lastToken;
        }
        lastToken = token;
    }

    if (!lastToken.empty()) {
        balance = std::stoll(lastToken);
    }
    return;
}
























void Menu::showIncomeTransaction() const {
    std::cout << Color::BOLD << "  INCOME TRANSACTION:\n" << Color::RESET;
    if (financeManager.Income.size() == 0) {
        std::cout << "    (No transaction is added)\n";
    }
    else{
        std::cout << "    "
                  << std::left  << std::setw(6)  << "STT"
                  << std::left  << std::setw(11) << "Date"
                  << std::left  << std::setw(7)  << "ID"
                  << std::left  << std::setw(14) << "Name"
                  << std::left  << std::setw(7)  << "Wallet"
                  << std::left  << std::setw(16) << "Description"
                  << std::right << std::setw(11) << "Amount"
                  << "\n";
        std::cout << "    ------------------------------------------\n";
        for(int i=0;i<financeManager.Income.size();i++){
            const auto& t = financeManager.Income[i];  
            std::cout << "    "
                      << std::left  << std::setw(6)  << ("[" + std::to_string(i + 1) + "]")
                      << std::left  << std::setw(11) << t.date
                      << std::left  << std::setw(7)  << clipText(t.sourceId)
                      << std::left  << std::setw(14) << clipText(financeManager.getIncomeSourceName(t.sourceId),14)
                      << std::left  << std::setw(7)  << clipText(t.walletid,7)
                      << std::left  << std::setw(16) << clipText(t.description,16)
                      << std::right << std::setw(11) << formatMoney(t.amount)
                      << "\n";
        }
    }
    return;
}

void Menu::showExpenseTransaction() const {
    std::cout << Color::BOLD << "  EXPENSE TRANSACTION:\n" << Color::RESET;
    if (financeManager.Expense.size() == 0) {
        std::cout << "    (No transaction is added)\n";
    }
    else{
        std::cout << "    "
                  << std::left  << std::setw(6)  << "STT"
                  << std::left  << std::setw(11) << "Date"
                  << std::left  << std::setw(7)  << "ID"
                  << std::left  << std::setw(14) << "Name"
                  << std::left  << std::setw(7)  << "Wallet"
                  << std::left  << std::setw(16) << "Description"
                  << std::right << std::setw(11) << "Amount"
                  << "\n";
        std::cout << "    ------------------------------------------\n";
        for(int i=0;i<financeManager.Expense.size();i++){
            const auto& t = Expense[i];  
            std::cout << "    "
                      << std::left  << std::setw(6)  << ("[" + std::to_string(i + 1) + "]")
                      << std::left  << std::setw(11) << t.date
                      << std::left  << std::setw(7)  << clipText(t.sourceId)
                      << std::left  << std::setw(14) << clipText(financeManager.getExpenseCatagoryName(t.sourceId),14)
                      << std::left  << std::setw(7)  << clipText(t.walletid,7)
                      << std::left  << std::setw(16) << clipText(t.description,16)
                      << std::right << std::setw(11) << formatMoney(t.amount)
                      << "\n";
        }
    }
    return;
}

void Menu::showHeaderTransaction() const {
    std::cout << Color::CYAN << Color::BOLD;
    std::cout << "  ============================================================================\n";
    std::cout << "  |                                TRANSACTION                                |\n";
    std::cout << "  ============================================================================\n";
    std::cout << Color::RESET;
    return;
}

void Menu::showTransactionDashboard()const {
    showHeaderTransaction();
    if (txViewMode == 'I') {
        showIncomeTransaction();
    } else if (txViewMode == 'E') {
        showExpenseTransaction();
    } else {
        showIncomeTransaction();
        std::cout << "\n";
        showExpenseTransaction();
    }
    std::cout << "  --------------------------------------------------\n";
    std::cout << "  " << Color::GREEN << "[1]" << Color::RESET << " Switch View (Income / Expense / All)\n";
    std::cout << "  " << Color::GREEN << "[2]" << Color::RESET << " Add Transaction\n";
    std::cout << "  " << Color::GREEN << "[3]" << Color::RESET << " Edit Transaction\n";
    std::cout << "  " << Color::GREEN << "[4]" << Color::RESET << " Delete Transaction\n";
    std::cout << "  " << Color::GREEN << "[0]" << Color::RESET << " Back to Dashboard\n";
    std::cout << "  --------------------------------------------------\n";
    std::cout << Color::BOLD << "  Enter your choice: " << Color::RESET;
    return;
}

void Menu::runTransactionManager() {
    bool isRunningTransactionManager = true;
    int choiceTransactionManager{};
    while (isRunningTransactionManager) {
        clearScreen();
        showTransactionDashboard();
        if (!(std::cin >> choiceTransactionManager)) {
            std::cout << "\n  " << Color::RED << "[ERROR] Please enter a valid integer!" << Color::RESET << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n  Press Enter to continue...";
            std::cin.get();
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        handleChoiceTransaction(choiceTransactionManager, isRunningTransactionManager);
        if (isRunningTransactionManager) {
            std::cout << "\n  Press Enter to continue...";
            std::cin.get();
        }
    }
    return;
}

void Menu::handleChoiceTransaction(int &choiceTransactionManager, bool& isRunningTransactionManager) {
    std::cout << "\n";
    switch (choiceTransactionManager) {
        case 1: {
            std::cout << Color::MAGENTA
                      << "  [INFO] Choose view mode ([I] Income, [E] Expense, [A] All): "
                      << Color::RESET;
            char mode{};
            std::cin >> mode;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mode = static_cast<char>(std::toupper(static_cast<unsigned char>(mode)));
            if (mode == 'I' || mode == 'E' || mode == 'A') {
                txViewMode = mode;
                std::cout << Color::GREEN << "  [INFO] Display mode updated!\n" << Color::RESET;
            } else {
                std::cout << Color::RED << "  [ERROR] Invalid view mode!\n" << Color::RESET;
            }
            break;
        }
        case 2: {
            std::cout << Color::MAGENTA
                      << "  [INFO] Choose type ([I] Income / [E] Expense): "
                      << Color::RESET;
            char type{};
            std::cin >> type;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            type = static_cast<char>(std::toupper(static_cast<unsigned char>(type)));

            std::cout << Color::MAGENTA
                      << "  [INFO] Enter: <date> <sourceId> <walletId> <amount> <name> | <description>\n"
                      << Color::RESET << "  ";

            std::string line, date, sourceId, walletId, name, description;
            long long amount = 0;
            std::getline(std::cin, line);
            readTransactionInputLine(line, date, sourceId, walletId, amount, name, description);

            bool ok = false;
            if (type == 'I') {
                ok = financeManager.addIncome(date, sourceId, amount, walletId, name, description);
            } else if (type == 'E') {
                ok = financeManager.addExpense(date, sourceId, amount, walletId, name, description);
            }

            if (ok) {
                std::cout << Color::GREEN << "  SAVED!!!\n" << Color::RESET;
            } else {
                std::cout << Color::RED << "  [ERROR] Duplicate ID or invalid data!!!\n" << Color::RESET;
            }
            break;
        }
        case 3: {
            std::cout << Color::MAGENTA
                      << "  [INFO] Enter transaction ID to edit: "
                      << Color::RESET;
            std::string id;
            std::getline(std::cin, id);

            std::cout << Color::MAGENTA
                      << "  [INFO] Enter new: <date> <sourceId> <walletId> <amount> <name> | <description>\n"
                      << Color::RESET << "  ";
            std::string line, date, sourceId, walletId, name, description;
            long long amount = 0;
            std::getline(std::cin, line);
            readTransactionInputLine(line, date, sourceId, walletId, amount, name, description);

            if (financeManager.editIncome(id, date, sourceId, walletId, amount, name, description) ||
                financeManager.editExpense(id, date, sourceId, walletId, amount, name, description)) {
                std::cout << Color::GREEN << "  SAVED!!!\n" << Color::RESET;
            } else {
                std::cout << Color::RED << "  [ERROR] ID was not found or can not update!!!\n" << Color::RESET;
            }
            break;
        }
        case 4: {
            std::cout << Color::MAGENTA
                      << "  [INFO] Transaction will be deleted for the entered ID.\n"
                      << "  [INFO] Pls enter transaction id: "
                      << Color::RESET;
            std::string id;
            std::getline(std::cin, id);

            if (financeManager.deleteIncomeSource(id) || financeManager.deleteExpenseCategory(id)) {
                std::cout << Color::GREEN << "  DELETED / SAVED!!!\n" << Color::RESET;
            } else {
                std::cout << Color::RED << "  [ERROR] ID was not found!!!\n" << Color::RESET;
            }
            break;
        }
        case 0:
            std::cout << Color::GREEN << "  Return to Dashboard now!!!" << Color::RESET << "\n";
            isRunningTransactionManager = false;
            break;
        default:
            std::cout << Color::RED << "  [ERROR] Invalid choice! Please select a number from 0 to 4." << Color::RESET << "\n";
    }
    return;
}

static void readTransactionInputLine(const std::string& line,
                                   std::string& date,
                                   std::string& sourceId,
                                   std::string& walletId,
                                   long long& amount,
                                   std::string& name,
                                   std::string& description) {
    date.clear();
    sourceId.clear();
    walletId.clear();
    amount = 0;
    name.clear();
    description.clear();

    size_t pipePos = line.find('|');
    std::string mainPart = (pipePos == std::string::npos) ? line : line.substr(0, pipePos);
    if (pipePos != std::string::npos) {
        description = line.substr(pipePos + 1);
        size_t first = description.find_first_not_of(" \t");
        size_t last = description.find_last_not_of(" \t");
        description = (first == std::string::npos) ? "" : description.substr(first, last - first + 1);
    }

    std::istringstream iss(mainPart);
    std::string amtStr, token;
    iss >> date >> sourceId >> walletId >> amtStr;
    if (!amtStr.empty()) {
        amount = std::stoll(amtStr);
    }
    while (iss >> token) {
        if (!name.empty()) name += " ";
        name += token;
    }
}










static std::string clipText(const std::string& text, size_t maxLen) {
    if (text.size() <= maxLen) return text;
    if (maxLen <= 2) return text.substr(0, maxLen);
    return text.substr(0, maxLen - 2) + "..";
}

void Menu::showRecurringTransaction() const {
    std::cout << Color::BOLD << "  RECURRING TRANSACTIONS :\n" << Color::RESET;
    if (financeManager.recurringTransactions.size() == 0) {
        std::cout << "    (No recurring transaction is added)\n";
    } else {
        std::cout << "    "
              << std::left  << std::setw(5)  << "STT"
              << std::left  << std::setw(8)  << "Type"
              << std::left  << std::setw(5)  << "ID"
              << std::left  << std::setw(11) << "Name"
              << std::left  << std::setw(7)  << "Wallet"
              << std::left  << std::setw(11) << "Start"
              << std::left  << std::setw(11) << "End"
              << std::right << std::setw(9)  << "Amount"
              << " "
              << std::left  << std::setw(8)  << "Desc"
              << "\n";
        std::cout << "    --------------------------------------------------------------------------\n";

        for (int i = 0; i < financeManager.RecurringTransaction.size(); i++) {
            const auto& r = financeManager.RecurringTransactions[i];
            std::string typeStr = (r.getType() == RecurringType::INCOME) ? "INCOME" : "EXPENSE";
            std::string srcid = r.getSourceOrCategoryId();
            std::string nameStr = getSourceOrCategoryName(srcid);
            std::string startStr = r.getStartDate().toString();
            std::string endStr = r.hasEndDate() ? r.getEndDate().toString() : "None";
            long long absAmount = r.getAmount();

            std::cout << "    "
                    << std::left  << std::setw(5)  << ("[" + std::to_string(i + 1) + "]")
                    << std::left  << std::setw(8)  << typeStr
                    << std::left  << std::setw(5)  << clipText(srcid, 5)
                    << std::left  << std::setw(11) << clipText(nameStr, 11)
                    << std::left  << std::setw(7)  << clipText(r.getWalletId(), 7)
                    << std::left  << std::setw(11) << clipText(startStr, 11)
                    << std::left  << std::setw(11) << clipText(endStr, 11)
                    << std::right << std::setw(9)  << formatmoney(absAmount)
                    << " "
                    << std::left  << std::setw(8)  << clipText(r.getDescription(), 8)
                    << "\n";
        }
    }
    return;
}

void Menu::showHeaderRecurring() const {
    std::cout << Color::CYAN << Color::BOLD;
    std::cout << "  ============================================================================\n";
    std::cout << "  |                           RECURRING TRANSACTION                           |\n";
    std::cout << "  ============================================================================\n";
    std::cout << Color::RESET;
    return;
}

void Menu::showRecurringDashboard() const {
    showHeaderRecurring();
    showRecurringTransaction();
    std::cout << "  --------------------------------------------------\n";
    std::cout << "  " << Color::GREEN << "[1]" << Color::RESET << " Add Recurring Transaction\n";
    std::cout << "  " << Color::GREEN << "[2]" << Color::RESET << " Edit Recurring Transaction\n";
    std::cout << "  " << Color::GREEN << "[3]" << Color::RESET << " Delete Recurring Transaction\n";
    std::cout << "  " << Color::GREEN << "[0]" << Color::RESET << " Back to Dashboard\n";
    std::cout << "  --------------------------------------------------\n";
    std::cout << Color::BOLD << "  Enter your choice: " << Color::RESET;
    return;
}

void Menu::runRecurringManager() {
    bool isRunningRecurring = true;
    int choiceRecurring{};
    while (isRunningRecurring) {
        clearScreen();
        showRecurringDashboard();
        if (!(std::cin >> choiceRecurring)) {
            std::cout << "\n  " << Color::RED << "[ERROR] Please enter a valid integer!" << Color::RESET << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n  Press Enter to continue...";
            std::cin.get();
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        handleChoiceRecurring(choiceRecurring, isRunningRecurring);
        if (isRunningRecurring) {
            std::cout << "\n  Press Enter to continue...";
            std::cin.get();
        }
    }
    return;
}

void Menu::handleChoiceRecurring(int &choiceRecurring, bool& isRunningRecurring) {
    std::cout << "\n";
    switch (choiceRecurring) {
        case 1: {
            RecurringType rType{};
            if (!readRecurringType(rType)) {
                std::cout << Color::RED << "  [ERROR] Invalid type! Please choose I or E.\n" << Color::RESET;
                break;
            }

            std::cout << Color::MAGENTA
                      << "  [INFO] Enter: <sourceId> <walletId> <amount> <dayOfMonth> <startDate> <endDate or -> <description>\n"
                      << Color::RESET << "  ";

            std::string sourceId, walletId, description;
            long long amount = 0;
            int dayOfMonth = 1;
            Date startDate, endDate;
            bool hasEndDate = false;

            if (!readRecurringInputLine(sourceId, walletId, amount, dayOfMonth, startDate, hasEndDate, endDate, description)) {
                std::cout << Color::RED << "  [ERROR] Invalid input format!\n" << Color::RESET;
                break;
            }

            if (financeManager.addRecurringTransaction(rType, sourceId, amount, walletId, description, startDate, hasEndDate, endDate, dayOfMonth)) {
                std::cout << Color::GREEN << "  SAVED!!!\n" << Color::RESET;
            } else {
                std::cout << Color::RED << "  [ERROR] Can not save recurring transaction!\n" << Color::RESET;
            }
            break;
        }
        case 2: {
            std::cout << Color::MAGENTA
                      << "  [INFO] Enter recurring ID to edit: "
                      << Color::RESET;
            std::string id;
            std::getline(std::cin, id);

            RecurringType rType{};
            if (!readRecurringType(rType)) {
                std::cout << Color::RED << "  [ERROR] Invalid type! Please choose I or E.\n" << Color::RESET;
                break;
            }

            std::cout << Color::MAGENTA
                      << "  [INFO] Enter new: <sourceId> <walletId> <amount> <dayOfMonth> <startDate> <endDate or -> <description>\n"
                      << Color::RESET << "  ";

            std::string sourceId, walletId, description;
            long long amount = 0;
            int dayOfMonth = 1;
            Date startDate, endDate;
            bool hasEndDate = false;

            if (!readRecurringInputLine(sourceId, walletId, amount, dayOfMonth, startDate, hasEndDate, endDate, description)) {
                std::cout << Color::RED << "  [ERROR] Invalid input format!\n" << Color::RESET;
                break;
            }

            if (financeManager.editRecurringTransaction(id, rType, sourceId, amount, walletId, description, startDate, hasEndDate, endDate, dayOfMonth)) {
                std::cout << Color::GREEN << "  SAVED!!!\n" << Color::RESET;
            } else {
                std::cout << Color::RED << "  [ERROR] ID was not found or can not update!!!\n" << Color::RESET;
            }
            break;
        }
        case 3: {
            std::cout << Color::MAGENTA
                      << "  [INFO] Recurring transaction will be deleted for the entered ID.\n"
                      << "  [INFO] Pls enter recurring id: "
                      << Color::RESET;
            std::string id;
            std::getline(std::cin, id);

            if (financeManager.deleteRecurringTransaction(id)) {
                std::cout << Color::GREEN << " SAVED!!!\n" << Color::RESET;
            } else {
                std::cout << Color::RED << "  [ERROR] ID was not found!!!\n" << Color::RESET;
            }
            break;
        }
        case 0:
            std::cout << Color::GREEN << "  Return to Dashboard now!!!" << Color::RESET << "\n";
            isRunningRecurring = false;
            break;
        default:
            std::cout << Color::RED << "  [ERROR] Invalid choice! Please select a number from 0 to 3." << Color::RESET << "\n";
    }
    return;
}

static bool readRecurringType(RecurringType& outType) {
    std::cout << Color::MAGENTA
              << "  [INFO] Choose type ([I] Income / [E] Expense): "
              << Color::RESET;
    char typeChar{};
    if (!(std::cin >> typeChar)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    typeChar = static_cast<char>(std::toupper(static_cast<unsigned char>(typeChar)));

    if (typeChar == 'I') {
        outType = RecurringType::INCOME;
        return true;
    }
    if (typeChar == 'E') {
        outType = RecurringType::EXPENSE;
        return true;
    }
    return false;
}

static bool readRecurringInputLine(std::string& sourceId,
                                   std::string& walletId,
                                   long long& amount,
                                   int& dayOfMonth,
                                   Date& startDate,
                                   bool& hasEndDate,
                                   Date& endDate,
                                   std::string& description) {
    sourceId.clear();
    walletId.clear();
    amount = 0;
    dayOfMonth = 1;
    hasEndDate = false;
    endDate = Date();
    description.clear();

    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::string amtStr, dayStr, startStr, endStr, token;

    if (!(iss >> sourceId >> walletId >> amtStr >> dayStr >> startStr >> endStr)) {
        return false; 
    }
    while (iss >> token) {
        if (!description.empty()) description += " ";
        description += token;
    }
    try {
        amount = std::stoll(amtStr);
        dayOfMonth = std::stoi(dayStr);
    } catch (...) {
        return false; 
    }
    if (amount <= 0 || dayOfMonth < 1 || dayOfMonth > 31) {
        return false;
    }
    startDate = Date::fromString(startStr);
    if (!endStr.empty() && endStr != "-" && endStr != "None" && endStr != "none") {
        hasEndDate = true;
        endDate = Date::fromString(endStr);
    }
    return true;
}






void Menu::showHeaderStatistics() const {
    std::cout << Color::CYAN << Color::BOLD;
    std::cout << "  ============================================================================\n";
    std::cout << "  |                        STATISTICS AND REPORTING                           |\n";
    std::cout << "  ============================================================================\n";
    std::cout << Color::RESET;
    return;
}

void Menu::showStatisticsDashboard() const {
    showHeaderStatistics();
    std::cout << "  " << Color::GREEN << "[1]" << Color::RESET << " Time-based Statistics (From Date A to Date B)\n";
    std::cout << "  " << Color::GREEN << "[2]" << Color::RESET << " Time & Wallet-based Statistics\n";
    std::cout << "  " << Color::GREEN << "[3]" << Color::RESET << " Annual Income/Expense Overview\n";
    std::cout << "  " << Color::GREEN << "[4]" << Color::RESET << " Annual Income Breakdown (by Source)\n";
    std::cout << "  " << Color::GREEN << "[5]" << Color::RESET << " Annual Expense Breakdown (by Category)\n";
    std::cout << "  " << Color::RED   << "[0]" << Color::RESET << " Back to Dashboard\n";
    std::cout << "  ----------------------------------------------------------------------------\n";
    std::cout << Color::BOLD << "  Enter your choice: " << Color::RESET;
    return;
}

void Menu::runStatisticsManager() {
    bool isRunningStats = true;
    int choiceStats{};
    while (isRunningStats) {
        clearScreen();
        showStatisticsMenu();

        if (!(std::cin >> choiceStats)) {
            std::cout << "\n  " << Color::RED << "[ERROR] Please enter a valid integer!" << Color::RESET << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n  Press Enter to continue...";
            std::cin.get();
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        handleChoiceStatistics(choiceStats, isRunningStats);

        if (isRunningStats) {
            std::cout << "\n  Press Enter to continue...";
            std::cin.get();
        }
    }
    return;
}

static bool readSingleDate(Date& outDate) {
    std::string line;
    if (!std::getline(std::cin, line)) return false;
    std::istringstream iss(line);
    std::string dateStr, extra;
    if (!(iss >> dateStr) || (iss >> extra)) {
        return false;
    }
    Date tmp = Date::fromString(dateStr);
    if (!tmp.isValid()) {
        return false;
    }
    outDate = tmp;
    return true;
}

void Menu::handleChoiceStatistics(int choiceStats, bool& isRunningStats) {
    std::cout << "\n";
    switch (choiceStats) {
        case 1: {
            Date startDate, endDate;
            cout<<"  [INFO] Enter start date (DD/MM/YYYY):\n  > ";
            if (!readSingleDate(startDate)) {
                std::cout << Color::RED << "  [ERROR] Invalid start date!\n" << Color::RESET;
                break;
            }
            cout<<"  [INFO] Enter start date (DD/MM/YYYY):\n  > ";
            if (!readSingleDate(endDate)) {
                std::cout << Color::RED << "  [ERROR] Invalid end date!\n" << Color::RESET;
                break;
            }

            long long totalIncome, totalExpense , netBalance;
            financeManager.getTimeStatistic(startDate,endDate,totalIncome,totalExpense,netBalance);
            std::cout << "\n  ----------------------------------------------------------------------------\n";
            std::cout << "  Period        : " << startDate << " -> " << endDate << "\n";
            std::cout << "  ----------------------------------------------------------------------------\n";
            std::cout << "  Total Income  : " << std::right << std::setw(15) << formatMoney(totalIncome)  << " VND\n";
            std::cout << "  Total Expense : " << std::right << std::setw(15) << formatMoney(totalExpense) << " VND\n";
            std::cout << "  ----------------------------------------------------------------------------\n";
            std::cout << "  Net Balance   : " << std::right << std::setw(15) << formatMoney(netBalance)   << " VND\n";
            std::cout << "  ----------------------------------------------------------------------------\n";
            break;
        }
        case 2:{
            showWalletVer2();
            Date startDate, endDate;
            cout<<"  [INFO] Enter start date (DD/MM/YYYY):\n  > ";
            if (!readSingleDate(startDate)) {
                std::cout << Color::RED << "  [ERROR] Invalid start date!\n" << Color::RESET;
                break;
            }
            cout<<"  [INFO] Enter start date (DD/MM/YYYY):\n  > ";
            if (!readSingleDate(endDate)) {
                std::cout << Color::RED << "  [ERROR] Invalid end date!\n" << Color::RESET;
                break;
            }
            std::cout << Color::MAGENTA << "  [INFO] Enter wallet ID:\n  > " << Color::RESET;
            std::string walletId;
            std::getline(std::cin, walletId);
            long long totalIncome, totalExpense , netBalance;
            Wallet *wal=financeManager.findWallet(walletId);
            if(wal == nullptr){
                std::cout << Color::RED << "  [ERROR] Invalid wallet id!\n" << Color::RESET;
                break;
            }
            financeManager.getTimeAndWalletStatistics(startDate,endDate,walletId,totalIncome,totalExpense,netBalance);
            std::cout << "\n  ----------------------------------------------------------------------------\n";
            std::cout << "  Wallet        : " << walletId << " -- " << financeManager.getWalletName(walletId) << "\n";
            std::cout << "  Period        : " << startDate << " -> " << endDate << "\n";
            std::cout << "  ----------------------------------------------------------------------------\n";
            std::cout << "    "
                      << std::left  << std::setw(12) << "Date"
                      << std::left  << std::setw(9)  << "Type"
                      << std::left  << std::setw(17) << "Name"
                      << std::left  << std::setw(21) << "Description"
                      << std::right << std::setw(13) << "Amount"
                      << "\n";
            std::cout << "    ------------------------------------------------------------------------\n";
            DynamicArray<Income>in=financeManager.getIncomesByWallet(walletId,startDate,endDate);
            DynamicArray<Income>ex=financeManager.getExpensesByWallet(walletId,startDate,endDate);
            if(!in.empty()||!ex.empty()){
                for(auto tmp:in){
                    std::cout << "    "
                              << std::left  << std::setw(12) << tmp.date.toString()
                              << std::left  << std::setw(9)  << ("INCOME")
                              << std::left  << std::setw(17) << clipText(financeManager.getIncomeSourceName(tmp.sourceId), 17)
                              << std::left  << std::setw(21) << clipText(tmp.description, 21)
                              << std::right << std::setw(13) << formatMoney(t.amount)
                              << "\n";
                }
                for(auto tmp:ex){
                    std::cout << "    "
                              << std::left  << std::setw(12) << tmp.date.toString()
                              << std::left  << std::setw(9)  << ("INCOME")
                              << std::left  << std::setw(17) << clipText(financeManager.getExpenseCategoryName(tmp.categoryId), 17)
                              << std::left  << std::setw(21) << clipText(tmp.description, 21)
                              << std::right << std::setw(13) << formatMoney(t.amount)
                              << "\n";
                }
            }
            std::cout << "    ------------------------------------------------------------------------\n";
            std::cout << "  Total Income  : " << std::right << std::setw(15) << formatMoney(totalIncome)  << " VND\n";
            std::cout << "  Total Expense : " << std::right << std::setw(15) << formatMoney(totalExpense) << " VND\n";
            std::cout << "  ----------------------------------------------------------------------------\n";
            std::cout << "  Net Balance   : " << std::right << std::setw(15) << formatMoney(netBalance)   << " VND\n";
            std::cout << "  ----------------------------------------------------------------------------\n";
            break;
        }
        case 3:{
            showAvailableYears();
            if (financeManager.getYears().size() == 0) {
                std::cout << Color::RED
                        << "  [WARN] There is no transaction data to generate annual statistics.\n"
                        << Color::RESET;
                break;
            }
            DynamicArray<int>years;
            inputYearsUntilStop(years);
            if (years.empty()) {
                std::cout << Color::RED << "  [ERROR] No valid year entered!\n" << Color::RESET;
                break;
            }
            DynamicArray<YearSummary>result=financeManager.getAnnualOverview(years);
            std::cout << "\n  ANNUAL OVERVIEW:\n";
            std::cout << "    "
                      << std::left  << std::setw(7)  << "Year"
                      << std::right << std::setw(17) << "Total Income"
                      << std::right << std::setw(18) << "Total Expense"
                      << std::right << std::setw(18) << "Net Balance"
                      << "\n";
            std::cout << "    ------------------------------------------------------------------------\n";
            for (auto y : result) {
                std::cout << "    "
                          << std::left  << std::setw(7)  << y.year;
                          << std::right << std::setw(17) << formatMoney(y.totalIncome)
                          << std::right << std::setw(18) << formatMoney(y.totalExpense)
                          << std::right << std::setw(18) << formatMoney(y.netBalance)
                          << "\n";
            }
            std::cout << "    ------------------------------------------------------------------------\n";
            break;
        }
        case 4:{
            showAvailableYears();
            if (financeManager.getYears().size() == 0) {
                std::cout << Color::RED
                        << "  [WARN] There is no transaction data to generate annual statistics.\n"
                        << Color::RESET;
                break;
            }
            DynamicArray<int>years;
            inputYearsUntilStop(years);
            if (years.empty()) {
                std::cout << Color::RED << "  [ERROR] No valid year entered!\n" << Color::RESET;
                break;
            }
            long long totalincome;
            DynamicArray<SourceSummary>res=financeManager.getIncomeBreakdown(years,totalincome);
            std::cout << "\n  INCOME BREAKDOWN :\n";
            std::cout << "    "
                      << std::left  << std::setw(7)  << "STT"
                      << std::left  << std::setw(9)  << "ID"
                      << std::left  << std::setw(35) << "Income Source"
                      << std::right << std::setw(21) << "Amount"
                      << "\n";
            std::cout << "    ------------------------------------------------------------------------\n";
            long long cnt=0;
            for (auto s:res) {
                std::cout << "    "
                          << std::left  << std::setw(7)  << ("[" + std::to_string(cnt + 1) + "]")
                          << std::left  << std::setw(9)  << clipText(s.sourceID, 8)
                          << std::left  << std::setw(35) << clipText(s.sourceName, 34)
                          << std::right << std::setw(21) << formatMoney(s.totalAmount)
                          << "\n";
                cnt++;
            }
            std::cout << "    ------------------------------------------------------------------------\n";
            std::cout << "    Total Income  : " << std::right << std::setw(15) << formatMoney(totalincome) << " VND\n";
            std::cout << "    ------------------------------------------------------------------------\n";
            break;
        }
        case 5:{
            showAvailableYears();
            if (financeManager.getYears().size() == 0) {
                std::cout << Color::RED
                        << "  [WARN] There is no transaction data to generate annual statistics.\n"
                        << Color::RESET;
                break;
            }
            DynamicArray<int>years;
            inputYearsUntilStop(years);
            if (years.empty()) {
                std::cout << Color::RED << "  [ERROR] No valid year entered!\n" << Color::RESET;
                break;
            }
            long long totalexpense;
            DynamicArray<CategorySummary>ans=financeManager.getExpenseBreakdown(years,totalexpense);
            std::cout << "\n  EXPENSE BREAKDOWN :\n";
            std::cout << "    "
                      << std::left  << std::setw(7)  << "STT"
                      << std::left  << std::setw(9)  << "ID"
                      << std::left  << std::setw(35) << "Expense Category"
                      << std::right << std::setw(21) << "Amount"
                      << "\n";
            std::cout << "    ------------------------------------------------------------------------\n";
            long long cnt=0;
            for (auto s:ans) {
                std::cout << "    "
                          << std::left  << std::setw(7)  << ("[" + std::to_string(cnt + 1) + "]")
                          << std::left  << std::setw(9)  << clipText(s.categoryID, 8)
                          << std::left  << std::setw(35) << clipText(s.categoryName, 34)
                          << std::right << std::setw(21) << formatMoney(s.totalAmount)
                          << "\n";
                cnt++;
            }
            std::cout << "    ------------------------------------------------------------------------\n";
            std::cout << "    Total Expense  : " << std::right << std::setw(15) << formatMoney(totalexpense) << " VND\n";
            std::cout << "    ------------------------------------------------------------------------\n";
            break;
        }
        case 0:
            std::cout << Color::GREEN << "  Return to Dashboard now!!!" << Color::RESET << "\n";
            isRunningStats = false;
            break;

        default:
            std::cout << Color::RED << "  [ERROR] Invalid choice! Please select a number from 0 to 5.\n" << Color::RESET;
    }
    break;
}

void Menu::showAvailableYears() const {
    DynamicArray<int> availYears = financeManager.getYears();
    std::cout << "  ----------------------------------------------------------------------------\n";
    std::cout << "  Available Years (with transactions) : ";

    if (availYears.size() == 0) {
        std::cout << Color::YELLOW << "(No transaction data found)" << Color::RESET << "\n";
    } else {
        std::cout << Color::GREEN;
        for (int i = 0; i < availYears.size(); ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << availYears[i];
        }
        std::cout << Color::RESET << "\n";
    }
    std::cout << "  ----------------------------------------------------------------------------\n";
    return;
}

static void inputYearsUntilStop(DynamicArray<int>&years){
    years.clear();
    std::cout << Color::MAGENTA
                  << "  [INFO] Enter year (or enter 0 to stop): "
                  << Color::RESET;
    int year{};
    while(cin>>year){
        if(year==0){
            break;
        }
        if(year<0){
            std::cout << Color::RED << "  [ERROR] Invalid number! Skipped.\n" << Color::RESET;
            continue;
        }
        years.push(year);
    }
    return;
}

static std::string formatMoney(long long amount) {
    bool neg = amount < 0;
    unsigned long long val = neg ? static_cast<unsigned long long>(-(amount + 1)) + 1ULL
                                 : static_cast<unsigned long long>(amount);
    std::string s = std::to_string(val);
    std::string out;
    int count = 0;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (count > 0 && count % 3 == 0) out.push_back(',');
        out.push_back(*it);
        ++count;
    }
    if (neg) out.push_back('-');
    std::reverse(out.begin(), out.end());
    return out;
}