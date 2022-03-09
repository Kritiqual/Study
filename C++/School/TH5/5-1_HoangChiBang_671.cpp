// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <fstream>
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

class PHANSO
{
private:
    float t, m;

public:
    float operator!();
    PHANSO operator+(PHANSO ps2);
    PHANSO operator-(PHANSO ps2);
    PHANSO operator*(PHANSO ps2);
    PHANSO operator/(PHANSO ps2);
    friend istream &operator>>(istream &is, PHANSO &ps);
    friend ostream &operator<<(ostream &os, PHANSO ps);
};

istream &operator>>(istream &is, PHANSO &ps)
{
    cout << "Nhap Tu so va mau so: ";
    is >> ps.t >> ps.m;
    return is;
}

ostream &operator<<(ostream &os, PHANSO ps)
{
    os << ps.t << "/" << ps.m;
    return os;
}

PHANSO PHANSO::operator+(PHANSO ps2)
{
    PHANSO res;
    res.t = t * ps2.t + m * ps2.t;
    res.m = m * ps2.m;
    return res;
}

PHANSO PHANSO::operator-(PHANSO ps2)
{
    PHANSO res;
    res.t = t * ps2.t - m * ps2.t;
    res.m = m * ps2.m;
    return res;
}

PHANSO PHANSO::operator*(PHANSO ps2)
{
    PHANSO res;
    res.t = t * ps2.t;
    res.m = m * ps2.m;
    return res;
}

PHANSO PHANSO::operator/(PHANSO ps2)
{
    PHANSO res;
    res.t = t * ps2.m;
    res.m = m * ps2.t;
    return res;
}

float PHANSO::operator!()
{
    return t / m;
}

int main()
{
    PHANSO ps1, ps2, tong, hieu, tich, thuong;
    cls();
    cin >> ps1 >> ps2;
    tong = ps1 + ps2;
    hieu = ps1 - ps2;
    tich = ps1 * ps2;
    thuong = ps1 / ps2;

    cout << "Ps1: " << ps1 << " = " << !ps1 << endl
         << "Ps2: " << ps2 << " = " << !ps2 << endl
         << "Tong: " << tong << " = " << !tong << endl
         << "Hieu: " << hieu << " = " << !hieu << endl
         << "Tich: " << tich << " = " << !tich << endl
         << "Thuong: " << thuong << " = " << !thuong << endl;

    ofstream f("./ps.txt", ios::out);
    f << "Ps1: " << ps1 << " = " << !ps1 << endl
      << "Ps2: " << ps2 << " = " << !ps2 << endl
      << "Tong: " << tong << " = " << !tong << endl
      << "Hieu: " << hieu << " = " << !hieu << endl
      << "Tich: " << tich << " = " << !tich << endl
      << "Thuong: " << thuong << " = " << !thuong << endl;
    f.close();
}