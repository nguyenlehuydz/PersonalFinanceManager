#ifndef MENU_H
#define MENU_H

class Menu{
public:
    void run();

private:
    void clearScreen() const;
    void showHeader()const;
    void showDashboard()const;
    void handleChoice(int &choice, bool & isRunning);
    void showWallet()const;
    void showWalletVer2()const;
    void runWalletManager();
    void showHeaderWallet() const;
    void showWalletDashboard()const;

};

#endif
