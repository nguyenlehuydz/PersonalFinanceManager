#include "BankManager.h"
#include <bits/stdc++.h>
using namespace std;

BankManager::BankManager() {
    cap = 2;
    cnt = 0;
    data = new BankCard[cap];
}

BankManager::~BankManager() {
    delete[] data;
}

void BankManager::push(BankCard card) {
    if (cnt == cap) {
        cap = cap << 1;
        BankCard *new_data = new BankCard[cap];
        for (int i = 0; i < cnt; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    data[cnt++] = card;
}

void BankManager::remove(int idx) {
    for (int i = idx; i < cnt - 1; i++) {
        data[i] = data[i + 1];
    }
    cnt--;
}

void BankManager::input() {
    BankCard card;
    cout << "Nhap ten: ";
    getline(cin, card.name);
    cin.ignore();
    cout << "Nhap nam sinh: ";
    cin >> card.birth_year;
    cin.ignore();
    cout << "Nhap ngay tao (dd/mm/yyyy): ";
    getline(cin, card.created_date);
    cin.ignore();
    cout << "Nhap so du (VND): ";
    cin >> card.balance;
    cin.ignore();
    cout << "Nhap so tien nap gan nhat (VND): ";
    cin >> card.last_deposit;
    cin.ignore();
    push(card);
}
