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

class VEHICLE
{
protected:
    char nhanHieu[30], hangSX[30];
    int namSX;

public:
    void Nhap();
    void Xuat();
};

void VEHICLE::Nhap()
{
    cout << "Nhap Nhan hieu: ";
    cin.getline(nhanHieu, 30);
    cout << "Nhap Hang SX: ";
    cin.getline(hangSX, 30);
    cout << "Nhap Nam SX: ";
    cin >> namSX;
}

void VEHICLE::Xuat()
{
    cout << "Nhan hieu  : " << nhanHieu << endl
         << "Hang SX    : " << hangSX << endl
         << "Nam SX     : " << namSX << endl;
}

class OTO : public VEHICLE
{
private:
    int soChoNgoi;
    float dungTich;

public:
    void Nhap();
    void Xuat();
    friend void Sua(OTO &oto);
};

void OTO::Nhap()
{
    cls();
    cout << "=== OTO ===" << endl;
    VEHICLE::Nhap();
    cout << "Nhap So cho ngoi: ";
    cin >> soChoNgoi;
    cout << "Nhap Dung tich: ";
    cin >> dungTich;
    cin.ignore();
}

void OTO::Xuat()
{
    cout << "=== OTO ===" << endl;
    VEHICLE::Xuat();
    cout << "So cho ngoi: " << soChoNgoi << endl
         << "Dung tich  : " << dungTich << endl;
}

class MOTO : public VEHICLE
{
private:
    float phanKhoi;

public:
    void Nhap();
    void Xuat();
};

void MOTO::Nhap()
{
    cls();
    cout << "=== MOTO ===" << endl;
    VEHICLE::Nhap();
    cout << "Nhap Phan khoi: ";
    cin >> phanKhoi;
    cin.ignore();
}

void MOTO::Xuat()
{
    cout << "\n=== MOTO ===" << endl;
    VEHICLE::Xuat();
    cout << "Phan khoi  : " << phanKhoi << endl;
}

void Sua(OTO &oto)
{
    oto.dungTich = 3.0;
}

int main()
{
    OTO oto;
    MOTO moto;
    oto.Nhap();
    moto.Nhap();

    cls();
    oto.Xuat();
    moto.Xuat();

    Sua(oto);
    oto.Xuat();
}