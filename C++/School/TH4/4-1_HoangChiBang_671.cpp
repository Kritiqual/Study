// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
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

class PERSON
{
protected:
    char hoTen[30], ngaySinh[12], queQuan[50];
};

class KYSU : public PERSON
{
private:
    char Nganh[20];
    int namTN;

public:
    void Nhap();
    void Xuat();
    friend void NRSG(KYSU *ks, int n);
};

void KYSU::Nhap()
{
    cout << "Nhap Ho ten: ";
    cin.getline(hoTen, 30);
    cout << "Nhap Ngay sinh: ";
    cin.getline(ngaySinh, 12);
    cout << "Nhap Que quan: ";
    cin.getline(queQuan, 50);
    cout << "Nhap Nganh hoc: ";
    cin.getline(Nganh, 20);
    cout << "Nhap Nam TN: ";
    cin >> namTN;
    cin.ignore();
}

void KYSU::Xuat()
{
    cout << left << setw(32) << hoTen
         << left << setw(12) << ngaySinh
         << left << setw(30) << queQuan
         << left << setw(22) << Nganh
         << left << namTN << endl;
}

void NRSG(KYSU *ks, int n)
{
    int LN = ks[0].namTN;
    for (int i = 0; i < n; i++)
        if (ks[i].namTN > LN)
            LN = ks[i].namTN;

    for (int i = 0; i < n; i++)
        if (ks[i].namTN == LN)
            ks[i].Xuat();
}

int main()
{
    int n;
    cout << "Nhap So luong ky su: ";
    cin >> n;
    cin.ignore();
    KYSU *ks = new KYSU[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        cout << "=== STT: " << i + 1 << " ===" << endl;
        ks[i].Nhap();
    }

    cout << left << setw(32) << "Ho ten"
         << left << setw(12) << "Ngay sinh"
         << left << setw(30) << "Que quan"
         << left << setw(22) << "Nganh"
         << left << "Nam TN" << endl;
    for (int i = 0; i < n; i++)
        ks[i].Xuat();

    cout << "\nDanh sach TN gan nhat: " << endl
         << left << setw(32) << "Ho ten"
         << left << setw(12) << "Ngay sinh"
         << left << setw(30) << "Que quan"
         << left << setw(22) << "Nganh"
         << left << "Nam TN" << endl;
    NRSG(ks, n);
}