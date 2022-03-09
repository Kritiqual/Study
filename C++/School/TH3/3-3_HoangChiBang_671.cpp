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

class HANG;
class DATE
{
    int D, M, Y;
    friend class HANG;
    friend void Xuat2017(HANG *x, int n);
};

class HANG
{
private:
    char maHang[10], tenHang[30];
    DATE ngaySX;

public:
    void Nhap();
    void Xuat();
    friend void Xuat2017(HANG *x, int n);
};

void HANG::Nhap()
{
    cout << "Nhap Ma Hang: ";
    cin.getline(maHang, 10);
    cout << "Nhap Ten Hang: ";
    cin.getline(tenHang, 30);
    cout << "Nhap Ngay SX: ";
    cin >> ngaySX.D >> ngaySX.M >> ngaySX.Y;
    cin.ignore();
}

void HANG::Xuat()
{
    cout << left << setw(12) << maHang
         << left << setw(32) << tenHang
         << left << ngaySX.D << "/" << ngaySX.M << "/" << ngaySX.Y << endl;
}

void Xuat2017(HANG *x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (x[i].ngaySX.Y == 2017)
        {
            x[i].Xuat();
        }
    }
}

int main()
{
    cls();
    int n;
    cout << "Nhap So luong hang hoa: ";
    cin >> n;
    cin.ignore();
    HANG *x = new HANG[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        cout << "=== STT: " << i + 1 << " ===" << endl;
        x[i].Nhap();
    }

    cls();
    cout << "\t\tDANH SACH HANG HOA\n";
    cout << left << setw(12) << "Ma Hang"
         << left << setw(32) << "Ten Hang"
         << left << "Ngay SX" << endl;
    Xuat2017(x, n);
}