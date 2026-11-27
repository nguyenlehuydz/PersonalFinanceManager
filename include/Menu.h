#ifndef MENU_H
#define MENU_H

class Menu{
public:
    void run();

private:
    FinanceManager financeManager;
    void showAvailableYears() const;
    
    char txViewMode{'I'};
    void clearScreen() const;
    void showHeader()const;
    void showDashboard()const;
    void handleChoice(int &choice, bool & isRunning);
    
    void showWallet()const;
    void showWalletVer2()const;
    void runWalletManager();
    void showHeaderWallet() const;
    void showWalletDashboard()const;
    void handleChoiceWallet(int &choiceWalletManager, bool &isRunningWalletManager);
    
    
    void showIncomeTransaction()const;
    void showExpenseTransaction()const;
    void runTransactionManager();
    void showHeaderTransaction() const;
    void showTransactionDashboard()const;
    void handleChoiceTransaction(int &choiceTransactionManager, bool &isRunningTransactionManager);

    void showRecurringTransaction() const;
    void showHeaderRecurring() const;
    void showRecurringDashboard() const;
    void runRecurringManager();
    void handleChoiceRecurring(int &choiceRecurring, bool &isRunningRecurring);

    void showStatistics() const;
    void showHeaderStatistics() const;
    void showStatisticsDashboard() const;
    void runStatisticsManager();
    void handleChoiceStatistics(int &choiceStatistics, bool &isRunningStatistics);
};

#endif
