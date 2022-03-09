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
class HANG
{
private:
    char maHang[10], tenHang[30];
    float donGia;

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
    cin.ignore();
}

void HANG::Xuat()
{
    cout << left << setw(10) << maHang
         << left << setw(20) << tenHang
         << left << donGia << endl;
}

class PHIEU
{
private:
    char maPhieu[10];
    HANG *hang;
    int n;

public:
    void Nhap();
    void Xuat();
};

void PHIEU::Nhap()
{
    cls();
    cout << "Nhap Ma phieu: ";
    cin.getline(maPhieu, 10);
    cout << "Nhap So luong hang hoa: ";
    cin >> n;
    cin.ignore();
    hang = new HANG[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        hang[i].Nhap();
    }
}

void PHIEU::Xuat()
{
    cls();
    cout << "\tPHIEU MUA HANG\n\n";
    cout << left << setw(10) << "Ma Phieu:" 
         << left << maPhieu << endl
         << left << setw(10) << "Ma hang"
         << left << setw(20) << "Ten hang"
         << left << "Don gia" << endl;
    for (int i = 0; i < n; i++)
    {
        hang[i].Xuat();
    }
}

int main()
{
    PHIEU p1;
    p1.Nhap();
    p1.Xuat();
}
