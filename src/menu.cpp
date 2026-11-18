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
                  << std::left  << std::setw(20) << "Wallet's name" 
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




