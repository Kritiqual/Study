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

class SINHVIEN
{
private:
    char maSV[10], tenSV[30];
    int Tuoi;
    float Diem;

public:
    void Nhap();
    void Xuat();
};

void SINHVIEN::Nhap()
{
    cout << "Nhap Ma SV: ";
    cin.getline(maSV, 10);
    cout << "Nhap Ten SV: ";
    cin.getline(tenSV, 30);
    cout << "Nhap Tuoi SV: ";
    cin >> Tuoi;
    cout << "Nhap Diem SV: ";
    cin >> Diem;
    cin.ignore();
}

void SINHVIEN::Xuat()
{
    cout << "\nMa SV: " << maSV << endl;
    cout << "Ten SV: " << tenSV << endl;
    cout << "Tuoi: " << Tuoi << endl;
    cout << "Diem: " << Diem;
}

int main()
{
    SINHVIEN a, b;
    a.Nhap();
    b.Nhap();
    a.Xuat();
    b.Xuat();
}