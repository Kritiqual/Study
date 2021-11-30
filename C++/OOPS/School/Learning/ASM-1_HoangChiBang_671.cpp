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

class SanPham
{
private:
    char maSP[10], tenSP[30];
    int Slg;
    float donGia;

public:
    void Nhap();
    void Xuat();
    friend class Phieu;
};

void SanPham::Nhap()
{
    cout << "Nhap Ma SP: ";
    cin.getline(maSP, 10);
    cout << "Nhap Ten SP: ";
    cin.getline(tenSP, 30);
    cout << "Nhap So luong va Don gia: ";
    cin >> Slg >> donGia;
    cin.ignore();
}

void SanPham::Xuat()
{
    cout << left << setw(12) << maSP
         << left << setw(32) << tenSP
         << left << setw(10) << Slg
         << left << setw(9) << donGia
         << left << Slg * donGia << endl;
}

class NSX
{
private:
    char maNSX[10], tenNSX[30], dcNSX[50], sdt[11];

public:
    void Nhap();
    void Xuat();
};

void NSX::Nhap()
{
    cout << "Nha san xuat\n";
    cout << " - Nhap Ma NSX: ";
    cin.getline(maNSX, 10);
    cout << " - Nhap Ten NSX: ";
    cin.getline(tenNSX, 30);
    cout << " - Nhap Dia chi: ";
    cin.getline(dcNSX, 50);
    cout << " - Nhap Sdt: ";
    cin.getline(sdt, 11);
}

void NSX::Xuat()
{
    cout << left << setw(20) << "Ma nha cung cap:"
         << left << setw(12) << maNSX
         << left << setw(19) << "Ten nha cung cap:"
         << left << tenNSX << endl
         << left << setw(9) << "Dia chi:"
         << left << setw(23) << dcNSX
         << left << "SDT: " << sdt << endl;
}

class Phieu
{
private:
    char maPhieu[10], ngayLap[12];
    NSX x;
    int n;
    SanPham *SP;

public:
    void Nhap();
    void Xuat();
};

void Phieu::Nhap()
{
    cout << "Phieu\n";
    cout << " - Nhap Ma Phieu: ";
    cin.getline(maPhieu, 10);
    cout << " - Nhap Ngay lap: ";
    cin.getline(ngayLap, 10);
    x.Nhap();
    cout << "Nhap So luong VPP: ";
    cin >> n;
    cin.ignore();
    SP = new SanPham[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        cout << "=== STT: " << i + 1 << " ===" << endl;
        SP[i].Nhap();
    }
}

void Phieu::Xuat()
{
    cls();
    cout << "Dai hoc Victory\n";
    cout << "\t\tPHIEU NHAP VAN PHONG PHAM\n";
    cout << left << setw(20) << "Ma phieu:"
         << left << setw(12) << maPhieu
         << left << setw(10) << "Ngay lap:"
         << left << ngayLap << endl;
    x.Xuat();
    cout << left << setw(12) << "Ma SP"
         << left << setw(32) << "Ten san pham"
         << left << setw(10) << "So luong"
         << left << setw(9) << "Don gia"
         << left << "Thanh tien" << endl;
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        SP[i].Xuat();
        sum += SP[i].donGia * SP[i].Slg;
    }
    cout << setw(35) << "\t\t\t\tTONG" << sum << "\n\n";
    cout << left << setw(22) << "\tHieu truong"
         << left << setw(26) << "Phong tai chinh"
         << "Nguoi lap";
}

int main()
{
    cls();
    Phieu ph1;
    ph1.Nhap();
    ph1.Xuat();
}