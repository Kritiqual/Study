// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
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

class KHACHSAN;
class PHONG
{
protected:
    char maPhong[10], tenPhong[30];
    float dienTich;

public:
    void Nhap();
    void Xuat();
    friend void Sua(KHACHSAN &ks);
    friend void Sap(KHACHSAN &ks);
};

void PHONG::Nhap()
{
    cout << "Nhap Ma phong: ";
    cin.getline(maPhong, 10);
    cout << "Nhap Ten phong: ";
    cin.getline(tenPhong, 30);
    cout << "Nhap Dien tich: ";
    cin >> dienTich;
    cin.ignore();
}

void PHONG::Xuat()
{
    cout << left << setw(12) << maPhong
         << left << setw(27) << tenPhong
         << left << setw(12) << dienTich;
}

class PHONGNGU : public PHONG
{
private:
    char loaiPhong[20];
    int giaThue;
    float SALE;

public:
    void Nhap();
    void Xuat();
    friend void Sap(KHACHSAN &ks);
    friend void Dem(KHACHSAN ks);
};

void PHONGNGU::Nhap()
{
    PHONG::Nhap();
    cout << "Nhap Loai phong: ";
    cin.getline(loaiPhong, 20);
    cout << "Nhap Gia thue: ";
    cin >> giaThue;
    cout << "Nhap Sale: ";
    cin >> SALE;
    cin.ignore();
}

void PHONGNGU::Xuat()
{
    PHONG::Xuat();
    cout << left << setw(12) << loaiPhong
         << left << setw(10) << giaThue
         << left << SALE << endl;
}

class KHACHSAN
{
private:
    char maKS[10], tenKS[30], diaChi[50];
    PHONGNGU *y;
    int n;

public:
    void Nhap();
    void Xuat();
    friend void Sua(KHACHSAN &ks);
    friend void Sap(KHACHSAN &ks);
    friend void Dem(KHACHSAN ks);
};

void KHACHSAN::Nhap()
{
    cls();
    cout << "Nhap Ma KS: ";
    cin.getline(maKS, 10);
    cout << "Nhap Ten KS: ";
    cin.getline(tenKS, 30);
    cout << "Nhap Dia chi: ";
    cin.getline(diaChi, 50);

    cout << "Nhap So luong phong: ";
    cin >> n;
    cin.ignore();
    y = new PHONGNGU[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        cout << "=== STT: " << i + 1 << " ===" << endl;
        y[i].Nhap();
    }
}

void KHACHSAN::Xuat()
{
    // cls();
    cout << "\t\t\tDANH SACH CAC PHONG\n\n";
    cout << left << setw(9) << "Ma KS:" << left << setw(12) << maKS
         << left << setw(9) << "Ten KS:" << left << tenKS << endl
         << left << setw(9) << "Dia chi:" << left << diaChi << endl
         << left << setw(12) << "Ma phong" << left << setw(27) << "Ten phong"
         << left << setw(12) << "Dien tich" << left << setw(12) << "Loai phong"
         << left << setw(10) << "Gia thue" << left << "Sale" << endl;
    for (int i = 0; i < n; i++)
        y[i].Xuat();
}

void Sua(KHACHSAN &ks)
{
    for (int i = 0; i < ks.n; i++)
        if (strcmp(ks.y[i].maPhong, "DEL001") == 0)
            strcpy(ks.y[i].maPhong, "DELUXE");

    pause();
}

void Sap(KHACHSAN &ks)
{
    for (int i = 0; i < ks.n; i++)
        for (int j = i + 1; j < ks.n; j++)
            if (ks.y[j].dienTich < ks.y[i].dienTich)
                swap(ks.y[j], ks.y[i]);

    pause();
}

void Dem(KHACHSAN ks)
{
    int count = 0;
    for (int i = 0; i < ks.n; i++)
        if (strcmp(ks.y[i].loaiPhong, "STANDARD") == 0)
            count++;

    if (count == 0)
        cout << "\nKhach san khong co phong STANDARD!!\n";
    else
        cout << "\nKhach san co " << count << " phong STANDARD\n";
}

int main()
{
    KHACHSAN ks;
    ks.Nhap();
    ks.Xuat();
    Sua(ks);
    ks.Xuat();
    Sap(ks);
    ks.Xuat();
    Dem(ks);
    fflush(stdin);
}
