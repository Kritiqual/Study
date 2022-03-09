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

class SACH
{
private:
    char maSach[10], tenSach[30], Nxb[30];
    int soTrang;
    float giaTien;

public:
    void Nhap();
    void Xuat();
};

void SACH::Nhap()
{
    cout << "Nhap Ma Sach: ";
    cin.getline(maSach, 10);
    cout << "Nhap Ten Sach: ";
    cin.getline(tenSach, 30);
    cout << "Nhap NXB: ";
    cin.getline(Nxb, 30);
    cout << "Nhap So Trang: ";
    cin >> soTrang;
    cout << "Nhap Gia Tien: ";
    cin >> giaTien;
}

void SACH::Xuat()
{
    cout << left << setw(12) << maSach
         << left << setw(22) << tenSach
         << left << setw(22) << Nxb
         << left << setw(9) << soTrang
         << left << giaTien << endl;
}

int main()
{
    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;
    SACH *sach = new SACH[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        cin.ignore();
        sach[i].Nhap();
    }
    cls();
    cout << "\n\t\tDANH SACH MUA SACH\n"
         << left << setw(12) << "Ma Sach"
         << left << setw(22) << "Ten Sach"
         << left << setw(22) << "NXB"
         << left << setw(9) << "So Trang"
         << left << "Gia Tien" << endl;
    for (int i = 0; i < n; i++)
    {
        sach[i].Xuat();
    }
}