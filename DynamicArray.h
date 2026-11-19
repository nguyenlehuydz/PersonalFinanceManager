#ifndef DynamicArray_h
#define DynamicArray_h

#include <bits/stdc++.h>
using namespace std;

struct Account{
    string name;
    int bd, bm, by;
    int rd, rm, ry;
    long long bal;
    string stk;
};

struct DynamicArray{
    Account* a;
    int cnt;
    int cap;
};

void init(DynamicArray &da, int cap = 2);
void resize(DynamicArray &da, int newCap);
void push(DynamicArray &da, Account x);
void remove(DynamicArray &da, int idx);
Account get(DynamicArray &da, int idx);
void input(DynamicArray &da);
void del(DynamicArray &da);

#endif
