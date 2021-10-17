// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
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

class NSX
{
private:
    char maNSX[10], tenNSX[30], dcNSX[50];

public:
    void Nhap();
    void Xuat();
};

void NSX::Nhap()
{
    cout << "Nhap Ma NSX: ";
    cin.getline(maNSX, 10);
    cout << "Nhap Ten NSX: ";
    cin.getline(tenNSX, 30);
    cout << "Nhap Dia chi NSX: ";
    cin.getline(dcNSX, 50);
}

void NSX::Xuat()
{
    cout << left << setw(10) << "Ma NSX :" << setw(12) << maNSX
         << left << setw(10) << "Ten NSX :" << tenNSX << endl
         << left << setw(10) << "Dia chi:" << dcNSX << endl;
}

class HANG
{
private:
    char maHang[10], tenHang[30];
    NSX x;

public:
    void Nhap();
    void Xuat();
};

void HANG::Nhap()
{
    cls();
    cout << "Nhap Ma hang: ";
    cin.getline(maHang, 10);
    cout << "Nhap Ten hang: ";
    cin.getline(tenHang, 30);
    x.Nhap();
}

void HANG::Xuat()
{
    cls();
    cout << "\tTHONG TIN HANG HOA\n\n";
    cout << left << setw(10) << "Ma Hang:" << setw(12) << maHang
         << left << setw(10) << "Ten Hang:" << tenHang << endl;
    x.Xuat();
}

int main()
{
    HANG hang;
    hang.Nhap();
    hang.Xuat();
}