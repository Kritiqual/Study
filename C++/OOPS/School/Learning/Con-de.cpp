// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <string.h>
using namespace std;
void pause(void)
{
    system("echo Press any key to continue... && ( read x 2> nul; rm nul || pause > nul )");
    return;
}
void cls(void)
{
    system("cls||clear");
    return;
}

class HANG
{
private:
    char maHang[10], tenHang[30];
    float donGia;
    int Slg;

public:
    HANG();
    HANG(const char *ma, const char *ten, float dg, int slg);
    void Xuat();
};

HANG::HANG()
{
    strcpy(maHang, "");
    strcpy(tenHang, "");
    donGia = 0;
    Slg = 0;
}

HANG::HANG(const char *ma, const char *ten, float dg, int slg)
{
    strcpy(maHang, ma);
    strcpy(tenHang, ten);
    donGia = dg;
    Slg = slg;
}

void HANG::Xuat()
{
    cout << "\nMa Hang: " << maHang;
    cout << "\nTen Hang: " << tenHang;
    cout << "\nDon Gia: " << donGia;
    cout << "\nSo luong: " << Slg;
}

int main()
{
    HANG k;
    cout << "Hang k:";
    k.Xuat();

    HANG q("hang01", "but viet", 3000, 10);
    cout << "\n\nHang q:";
    q.Xuat();
}