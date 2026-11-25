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
    std::cout << "  ==================================================\n";
    std::cout << "  |            PERSONAL FINANCE MANAGEMENT          |\n";
    std::cout << "  ==================================================\n";
    std::cout << Color::RESET;
    return;
}

void Menu::showDashboard()const {
    showHeader();
    long long totalBalance = getTotalBalance();
    std::cout << Color::BOLD << "  TOTAL BALANCE: " << totalBalance << " VND\n" << Color::RESET;
    std::cout << "  --------------------------------------------------\n";
    showWallet();
    std::cout << "  --------------------------------------------------\n";
    std::cout << Color::YELLOW << "  NAVIGATION MENU:\n" << Color::RESET;
    std::cout << "  " << Color::GREEN << "[1]" << Color::RESET << " Wallet Management\n";
    std::cout << "  " << Color::GREEN << "[2]" << Color::RESET << " Add Transaction\n";
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
            std::cout << Color::MAGENTA << "  [INFO] Opening Add Transaction..." << Color::RESET << "\n";
            break;
        case 3:
            std::cout << Color::MAGENTA << "  [INFO] Opening Recurring Transactions..." << Color::RESET << "\n";
            break;
        case 4:
            std::cout << Color::MAGENTA << "  [INFO] Opening Statistics..." << Color::RESET << "\n";
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
    if (wallets.size() == 0) {
        std::cout << "    (No wallet is added)\n";
    }
    else{
        std::cout << "    " 
                  << std::left  << std::setw(6)  << "STT" 
                  << std::left  << std::setw(20) << "Bank Account" 
                  << std::right << std::setw(18) << "Cash (VND)" << "\n";
        std::cout << "    ------------------------------------------\n";
        for(int i=0;i<wallets.size();i++){
            const Wallet& w = wallets[i];
            std::cout << "    " 
                      << std::left  << std::setw(6)  << ("[" + std::to_string(i + 1) + "]")
                      << std::left  << std::setw(20) << w.getName
                      << std::right << std::setw(18) << getWalletBalance(w.getId())
                      << "\n";
        }
    }
    return;
}

void Menu::showWalletVer2() const {
    std::cout << Color::BOLD << "  WALLET BALANCES:\n" << Color::RESET;
    if (wallets.size() == 0) {
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

        for (int i = 0; i < wallets.size(); ++i) {
            const Wallet& w = wallets[i];
            std::cout << "  "
                    << std::left  << std::setw(6)  << ("[" + std::to_string(i + 1) + "]")
                    << std::left  << std::setw(10) << w.getId()
                    << std::left  << std::setw(22) << w.getName()
                    << std::right << std::setw(18) << w.getBalance()
                    << "\n";
        }
    }
    return;
}

void Menu::showHeaderWallet() const {
    std::cout << Color::CYAN << Color::BOLD;
    std::cout << "  ==================================================\n";
    std::cout << "  |                 WALLET  MANAGEMENT              |\n";
    std::cout << "  ==================================================\n";
    std::cout << Color::RESET;
    return;
}

void Menu::showDashboard()const {
    showHeader();
    long long totalBalance = getTotalBalance();
    std::cout << Color::BOLD << "  TOTAL BALANCE: " << totalBalance << " VND\n" << Color::RESET;
    std::cout << "  --------------------------------------------------\n";
    showWallet();
    std::cout << "  --------------------------------------------------\n";
    std::cout << Color::YELLOW << "  NAVIGATION MENU:\n" << Color::RESET;
    std::cout << "  " << Color::GREEN << "[1]" << Color::RESET << " Wallet Management\n";
    std::cout << "  " << Color::GREEN << "[2]" << Color::RESET << " Add Transaction\n";
    std::cout << "  " << Color::GREEN << "[3]" << Color::RESET << " Recurring Transactions\n";
    std::cout << "  " << Color::GREEN << "[4]" << Color::RESET << " Statistics\n";
    std::cout << "  " << Color::RED << "[0]" << Color::RESET << " Exit Application\n";
    std::cout << "  --------------------------------------------------\n";
    std::cout << Color::BOLD << "  Enter your choice: " << Color::RESET;
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
    std::cout << "  --------------------------------------------------\n";
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
            if(addWallet(id,name,balance))std::cout << Color::MAGENTA << " SAVED!!! " << Color::RESET << "\n";
            else std::cout << Color::MAGENTA << "  [ERROR]Can not save!!! " << Color::RESET << "\n";
            break;
        case 2:
            std::cout << Color::MAGENTA << "  [INFO] Wallet will be updated for the entered ID." << Color::RESET << "\n";
            std::cout << Color::MAGENTA << "  [INFO] Pls enter your wallet's id, name and balance respectively: " << Color::RESET << "\n";
            std::string line,name,id;
            long long balance;
            readWalletLine(line,id,name,balance);
            if(editWallet(id,name,balance))std::cout << Color::MAGENTA << " SAVED!!! " << Color::RESET << "\n";
            else std::cout << Color::MAGENTA << " [ERROR]Id was not found!!!" << Color::RESET << "\n";
            break;
        case 3:
            std::cout << Color::MAGENTA << "  [INFO] Wallet will be deleted for the entered ID." << Color::RESET << "\n";
            std::cout << Color::MAGENTA << "  [INFO] Pls enter your wallet's id: " << Color::RESET << "\n";
            std::string id;
            getline(cin,id);
            if(deleteWallet(id))std::cout << Color::MAGENTA << " SAVED!!! " << Color::RESET << "\n";
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


