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

class PHIEU;
class NhaCC
{
private:
    char maNCC[10], tenNCC[30], diaChi[50];

public:
    void Nhap();
    void Xuat();
};

void NhaCC::Nhap()
{
    cout << "Nhap Ma NCC: ";
    cin.getline(maNCC, 10);
    cout << "Nhap Ten NCC: ";
    cin.getline(tenNCC, 30);
    cout << "Nhap Dia chi: ";
    cin.getline(diaChi, 50);
}

void NhaCC::Xuat()
{
    cout << left << setw(10) << "Ma NCC:" << left << setw(12) << maNCC
         << left << setw(10) << "Ten NCC: " << left << tenNCC
         << left << setw(10) << "Dia chi:" << diaChi << endl;
}

class HANG
{
private:
    char tenHang[30];
    float donGia;
    int Slg;

public:
    void Nhap();
    void Xuat();
    friend class PHIEU;
};

void HANG::Nhap()
{
    cout << "Nhap Ten hang: ";
    cin.getline(tenHang, 30);
    cout << "Nhap Don gia va So luong: ";
    cin >> donGia >> Slg;
    cin.ignore();
}

void HANG::Xuat()
{
    cout << left << setw(20) << tenHang
         << left << setw(9) << donGia
         << left << setw(11) << Slg;
}

class PHIEU
{
private:
    char maPhieu[10], ngayLap[12];
    NhaCC NCC;
    int n;
    HANG *hang;

public:
    void Nhap();
    void Xuat();
};

void PHIEU::Nhap()
{
    cls();
    cout << "Nhap Ma phieu: ";
    cin.getline(maPhieu, 10);
    cout << "Nhap Ngay lap: ";
    cin.getline(ngayLap, 12);
    NCC.Nhap();
    cout << "Nhap So luong hang hoa: ";
    cin >> n;
    cin.ignore();
    hang = new HANG[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        cout << "=== STT: " << i + 1 << " ===" << endl;
        hang[i].Nhap();
    }
}

void PHIEU::Xuat()
{
    cls();
    cout << "\t\tPHIEU NHAP HANG\n\n";
    cout << left << setw(10) << "Ma phieu:" << left << setw(12) << maPhieu
         << left << setw(10) << "Ngay lap:" << left << ngayLap << endl;
    NCC.Xuat();
    cout << left << setw(20) << "Ten hang"
         << left << setw(9) << "Don gia"
         << left << setw(11) << "So luong"
         << left << "Thanh tien" << endl;
    float tong = 0;
    for (int i = 0; i < n; i++)
    {
        hang[i].Xuat();
        cout << hang[i].donGia * hang[i].Slg << endl;
        tong += hang[i].donGia * hang[i].Slg;
    }
    cout << left << setw(15) << "\t\t\tCong thanh tien " << tong;
}

int main()
{
    PHIEU a;
    a.Nhap();
    a.Xuat();
}