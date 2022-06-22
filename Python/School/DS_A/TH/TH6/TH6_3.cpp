// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <fstream>
// #include <conio.h>
using namespace std;
void pause(void) {
    system("echo '\nPress any key to continue...' && ( read x 2> nul; rm nul || pause > nul )");
    return;
}
void cls(void) {
    system("cls||clear");
    return;
}

// Cau truc
struct Data {
    char SBD[10], hoDem[30], ten[15];
    float diem;
};
struct Node {
    Data info;
    Node* next;
};
typedef Node* ptr;
ptr L;

// Ham phu tro cau truc
ptr CreateNode(Data info) {
    ptr tmp = new Node;
    tmp->info = info;
    tmp->next = NULL;
    return tmp;
}
void Init(ptr& L) {
    L = NULL;
}

// Ham chuc nang chinh
Data input(Data info) {
    cout << "Nhap SBD: "; cin.getline(info.SBD, 10);
    cout << "Nhap Ho dem: "; cin.getline(info.hoDem, 30);
    cout << "Nhap Ten: "; cin.getline(info.ten, 15);
    cout << "Nhap Diem: "; cin >> info.diem;
    cin.ignore();
    return info;
}
void output(ptr L) {
    cout << left << setw(10) << "SBD"
        << left << setw(30) << "Ho dem"
        << left << setw(10) << "Ten"
        << "Diem" << endl;
    for (ptr i = L; i != NULL; i = i->next) {
        cout << left << setw(10) << i->info.SBD
            << left << setw(30) << i->info.hoDem
            << left << setw(10) << i->info.ten
            << i->info.diem << endl;
    }
}
void input_List(ptr& L) {
    cls();
    ptr P, Q;
    Data elem;
    Init(L);
    for (int i = 0; i < 5; i++) {
        cout << "=== Sinh vien thu " << i + 1 << " ===\n";
        input(elem);
        P = CreateNode(elem);
        if (L == NULL) L = P;
        else Q->next = P;
        Q = P;
    }
}


int main() {
    input_List(L);
    output(L);
}
