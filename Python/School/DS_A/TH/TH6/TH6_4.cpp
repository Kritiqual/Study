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

#define MAX 6
struct SV {
    char MaSV[10], hoDem[30], ten[15];
    float diem;
};

struct List {
    int count;
    SV e[MAX];
};

void init(List& L) {
    L.count = -1;
}

int empty(List L) {
    return (L.count == -1);
}

int full(List L) {
    return (L.count == MAX - 1);
}
List L;

int add(List& L, SV sv) {
    if (full(L))
        return 0;
    else {
        L.count++;
        L.e[L.count] = sv;
        return 1;
    }
}
void input(SV& sv) {
    cout << " - Nhap MaSV     : ";  cin >> sv.MaSV;
    if (strcmp(sv.MaSV, "***") == 0) return;
    cout << " - Nhap Ho dem   : ";  cin >> sv.hoDem;
    cout << " - Nhap Ten      : ";  cin >> sv.ten;
    cout << " - Nhap Diem     : ";  cin >> sv.diem;
    cin.ignore();
}
void ipL(List& L) {
    init(L);
    SV sv;
    int i = 1;
    do {
        cls();
        cout << "=== Sinh vien thu " << i << " ===\n";
        input(sv);
        if (strcmp(sv.MaSV, "***") == 0) return;
        if (!add(L, sv)) return;
        i++;
    } while (1);
}
void opL(List L) {
    cls();
    for (int i = 0; i <= L.count; i++) {
        cout << "=== Sinh vien thu " << i + 1 << " ===\n";
        cout << " - SBD      : " << L.e[i].MaSV << endl;
        cout << " - Ho dem   : " << L.e[i].hoDem << endl;
        cout << " - Ten      : " << L.e[i].ten << endl;
        cout << " - Diem     : " << L.e[i].diem << endl;
    }
    pause();
}
int insert(List& L, int k, SV sv) {
    if (k <= L.count + 1 && k > 0 && !full(L)) {
        for (int i = L.count; i >= k - 1; i--)
            L.e[i + 1] = L.e[i];
        L.e[k - 1] = sv;
        L.count++;
        return 0;
    }
    else return 1;
}

int main() {
    ipL(L); opL(L);
    SV sv{ "1006", "Le Thi", "Doan", 7.6 };
    insert(L, 4, sv); opL(L);
}