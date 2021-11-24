// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <cmath>
// #include <conio.h>
using namespace std;
void pause(void)
{
    system("echo '\nPress any key to continue...' && ( read x 2> nul; rm nul || pause > nul )");
    return;
}
void cls(void)
{
    system("cls||clear");
    return;
}

class LASERPRINTER;
class PRINTER
{
protected:
    char hangSX[30];
    int namSX, tocDo;
    float trongLuong;
};

class DOTPRINTER : public PRINTER
{
private:
    int matdoKim;

public:
    void Nhap();
    void Xuat();
    friend void Sua(DOTPRINTER &dp, LASERPRINTER &lp);
};

void DOTPRINTER::Nhap()
{
    cls();
    cout << "Nhap Trong luong: ";
    cin >> trongLuong;
    cin.ignore();
    cout << "Nhap Hang SX: ";
    cin.getline(hangSX, 30);
    cout << "Nhap Nam SX: ";
    cin >> namSX;
    cout << "Nhap Toc do: ";
    cin >> tocDo;
}

void DOTPRINTER::Xuat()
{
    cout << "=== DOT PRINTER ===" << endl
         << "Trong luong: " << trongLuong << endl
         << "Hang SX    : " << hangSX << endl
         << "Nam SX     : " << namSX << endl
         << "Toc do     : " << tocDo << endl;
}

class LASERPRINTER : public PRINTER
{
private:
    int doPhanGiai;

public:
    void Nhap();
    void Xuat();
    friend void Sua(DOTPRINTER &dp, LASERPRINTER &lp);
};

void LASERPRINTER::Nhap()
{
    cls();
    cout << "Nhap Trong luong: ";
    cin >> trongLuong;
    cin.ignore();
    cout << "Nhap Hang SX: ";
    cin.getline(hangSX, 30);
    cout << "Nhap Nam SX: ";
    cin >> namSX;
    cout << "Nhap Do phan giai: ";
    cin >> doPhanGiai;
}

void LASERPRINTER::Xuat()
{
    cout << "\n=== LASER PRINTER ===" << endl
         << "Trong luong : " << trongLuong << endl
         << "Hang SX     : " << hangSX << endl
         << "Nam SX      : " << namSX << endl
         << "Do phan giai: " << doPhanGiai << endl;
}

void Sua(DOTPRINTER &dp, LASERPRINTER &lp)
{
    dp.namSX = 2020;
    lp.namSX = 2020;
}

int main()
{
    DOTPRINTER dp;
    LASERPRINTER lp;
    dp.Nhap();
    lp.Nhap();
    cls();
    dp.Xuat();
    lp.Xuat();

    Sua(dp, lp);
    cout << endl;
    dp.Xuat();
    lp.Xuat();
}