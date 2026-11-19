#include "DynamicArray.h"
#include <bits/stdc++.h>
using namespace std;

void init(DynamicArray &da, int cap) {
    da.cap = cap;
    da.cnt = 0;
    da.a = new Account[da.cap];
}

void resize(DynamicArray &da, int newCap) {
    Account* tmp = new Account[newCap];
    for (int i = 0; i < da.cnt; i++) {
        tmp[i] = da.a[i];
    }
    delete[] da.a;
    da.a = tmp;
    da.cap = newCap;
}

void push(DynamicArray &da, Account x) {
    if (da.cnt == da.cap) {
        resize(da, da.cap * 2);
    }
    da.a[da.cnt++] = x;
}

void remove(DynamicArray &da, int idx) {
    if (idx < 0 || idx >= da.cnt) {
        cout << "Vị trí không hợp lệ!\n";
        return;
    }
    for (int i = idx; i < da.cnt - 1; i++) {
        da.a[i] = da.a[i + 1];
    }
    da.cnt--;
}

Account get(DynamicArray &da, int idx) {
    if (idx < 0 || idx >= da.cnt) {
        cout << "Vị trí không hợp lệ!\n";
        return Account{};
    }
    return da.a[idx];
}

void input(DynamicArray &da) {
    Account x;
    cout << "Tên: ";
    getline(cin >> ws, x.name);
    cout << "Ngày tháng năm sinh (d m y): ";
    cin >> x.bd >> x.bm >> x.by;
    cout << "Ngày tháng năm đăng kí (d m y): ";
    cin >> x.rd >> x.rm >> x.ry;
    cout << "Số tiền: ";
    cin >> x.bal;
    cout << "Số tài khoản: ";
    cin >> x.stk;
    push(da, x);
}

void del(DynamicArray &da) {
    delete[] da.a;
    da.a = nullptr;
    da.cnt = 0;
    da.cap = 0;
}
