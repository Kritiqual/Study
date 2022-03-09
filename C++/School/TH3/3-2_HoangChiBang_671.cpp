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
    char maNSX[10], tenNSX[30], dcNSX[50];
    friend class HANG;
};

class HANG
{
private:
    char maHang[10], tenHang[30];
    float donGia, trongLuong;
    NSX x;

public:
    void Nhap();
    void Xuat();
};

void HANG::Nhap()
{
    cout << "Nhap Ma hang: ";
    cin.getline(maHang, 10);
    cout << "Nhap Ten hang: ";
    cin.getline(tenHang, 30);
    cout << "Nhap Don gia: ";
    cin >> donGia;
    cout << "Nhap Trong luong: ";
    cin >> trongLuong;
    cin.ignore();
    cout << "Nhap Ma NSX: ";
    cin.getline(x.maNSX, 10);
    cout << "Nhap Ten NSX: ";
    cin.getline(x.tenNSX, 30);
    cout << "Nhap Dia chi: ";
    cin.getline(x.dcNSX, 50);
}

void HANG::Xuat()
{
    cls();
    cout << "Ma Hang: " << maHang << endl;
    cout << "Ten Hang: " << tenHang << endl;
    cout << "Don gia: " << donGia << endl;
    cout << "Trong luong: " << trongLuong << endl;
    cout << "Ma NSX: " << x.maNSX << endl;
    cout << "Ten NSX: " << x.tenNSX << endl;
    cout << "Dia chi: " << x.dcNSX << endl;
}

int main()
{
    cls();
    HANG hang;
    hang.Nhap();
    hang.Xuat();
}