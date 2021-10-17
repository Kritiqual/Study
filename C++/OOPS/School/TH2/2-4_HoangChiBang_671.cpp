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
class PHONGMAY;

class QUANLY
{
private:
    char maQL[10], hoTen[30];

public:
    void Nhap();
    void Xuat();
};

void QUANLY::Nhap()
{
    cout << "Nhap Ma quan ly: ";
    cin.getline(maQL, 10);
    cout << "Nhap Ho ten: ";
    cin.getline(hoTen, 30);
}

void QUANLY::Xuat()
{
    cout << left << "Ma Quan ly: "
         << setw(12) << maQL
         << left << "Ho ten Qly: "
         << left << hoTen << endl;
}

class MAY
{
private:
    char maMay[10], kieuMay[15], tinhTrang[15];

public:
    void Nhap();
    void Xuat();
    friend void Sua(PHONGMAY &pm1);
};

void MAY::Nhap()
{
    cout << "Nhap Ma may: ";
    cin.getline(maMay, 10);
    cout << "Nhap Kieu may: ";
    cin.getline(kieuMay, 15);
    cout << "Nhap Tinh trang: ";
    cin.getline(tinhTrang, 15);
}

void MAY::Xuat()
{
    cout << left << setw(12) << maMay
         << left << setw(17) << kieuMay
         << left << tinhTrang << endl;
}

class PHONGMAY
{
private:
    char maPhong[10], tenPhong[30];
    float dienTich;
    QUANLY qly;
    MAY *may;
    int n;

public:
    void Nhap();
    void Xuat();
    friend void Sua(PHONGMAY &pm1);
    friend void SuaDT(PHONGMAY &pm1);
};

void PHONGMAY::Nhap()
{
    cls();
    cout << "Nhap Ma phong: ";
    cin.getline(maPhong, 10);
    cout << "Nhap Ten phong: ";
    cin.getline(tenPhong, 30);
    cout << "Nhap Dien tich: ";
    cin >> dienTich;
    cin.ignore();
    qly.Nhap();
    cout << "Nhap So luong may: ";
    cin >> n;
    cin.ignore();
    may = new MAY[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        may[i].Nhap();
    }
}

void PHONGMAY::Xuat()
{
    cls();
    cout << "  DIEM CUNG CAP DICH VU INTERNET\n\n";
    cout << left << setw(12) << "Ma phong:"
         << left << setw(12) << maPhong
         << left << setw(12) << "Ten phong: "
         << left << tenPhong << endl
         << left << "Dien tich:  " << dienTich << endl;
    qly.Xuat();
    cout << left << setw(12) << "Ma may"
         << left << setw(17) << "Kieu may"
         << left << "Tinh trang" << endl;
    for (int i = 0; i < n; i++)
        may[i].Xuat();
    pause();
}

void Sua(PHONGMAY &pm1)
{
    for (int i = 0; i < pm1.n; i++)
        if (strcmp(pm1.may[i].maMay, "MS001") == 0)
            strcpy(pm1.may[i].tinhTrang, "Tot");
}

void SuaDT(PHONGMAY &pm1)
{
    pm1.dienTich = 50;
}

int main()
{
    PHONGMAY pm1;
    pm1.Nhap();
    pm1.Xuat();
    Sua(pm1);
    pm1.Xuat();
    SuaDT(pm1);
    pm1.Xuat();
}
