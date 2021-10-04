// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
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
    void Nhap();
    void Xuat();
};

void HANG::Nhap()
{
    cout << "Nhap Ma Hang: ";
    cin.getline(maHang, 10);
    cout << "Nhap Ten Hang: ";
    cin.getline(tenHang, 30);
    cout << "Nhap Don Gia: ";
    cin >> donGia;
    cout << "Nhap So Luong: ";
    cin >> Slg;
}

void HANG::Xuat()
{
    cout << left << setw(12) << maHang
         << left << setw(32) << tenHang
         << left << setw(12) << donGia
         << left << Slg << endl;
}

int main()
{
    int n;
    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    HANG *hang = new HANG[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        cin.ignore();
        hang[i].Nhap();
    }
    cout << "\n\t\tDANH SACH HANG HOA\n"
         << left << setw(12) << "Ma Hang"
         << left << setw(32) << "Ten Hang"
         << left << setw(12) << "Don Gia"
         << left << "So Luong" << endl;
    for (int i = 0; i < n; i++)
    {
        hang[i].Xuat();
    }
}