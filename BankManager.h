#ifndef BankManager_h
#define BankManager_h

#include <bits/stdc++.h>
using namespace std;

struct BankCard {
    string name;
    int birth_year;
    string created_date;
    long long balance;
    long long last_deposit;
};

struct BankManager {
    BankCard *data;
    int cnt;
    int cap;

    BankManager();
    ~BankManager();
    void push(BankCard card);
    void remove(int idx);
    void input();
};

#endif
