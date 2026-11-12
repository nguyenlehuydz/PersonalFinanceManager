#ifndef MENU_H
#define MENU_H

class Menu{
public:
    void run();
private:
    void clearScreen() const;
    void showHeader()const;
    void showOptions()const;
    void handleChoice(int &choice, bool & isRunning);
};

#endif