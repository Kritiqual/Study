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

class DATE
{
private:
    int D, M, Y;

public:
    void Nhap();
    void Xuat();
};

void DATE::Nhap()
{
    cout << "Nhap ngay thang nam: ";
    cin >> D >> M >> Y;
}

void DATE::Xuat()
{
    cout << D << "/" << M << "/" << Y;
}

class NHANSU
{
private:
    char maNS[10], hoTen[30];
    DATE ns;

public:
    void Nhap();
    void Xuat();
};

void NHANSU::Nhap()
{
    cls();
    cout << "Nhap Ma NS: ";
    cin.getline(maNS, 10);
    cout << "Nhap Ten NS: ";
    cin.getline(hoTen, 30);
    ns.Nhap();
}

void NHANSU::Xuat()
{
    cls();
    cout << "Ma NS: " << maNS << endl;
    cout << "Ho Ten: " << hoTen << endl;
    cout << "Ngay sinh:";
    ns.Xuat();
}

int main()
{
    NHANSU nsa;
    nsa.Nhap();
    nsa.Xuat();
}