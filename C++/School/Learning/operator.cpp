// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
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

/*
This luôn trỏ tới ngôi 1 nên
Toán tử 2 ngôi:
    operator? (đối 1, đối 2)
    -> operator? (this, đối 2) 
    -> operator? (đối 2)
Toán tử 1 ngôi:
    operator? (<0 đối>)
*/

class PHANSO
{
private:
    float ts, ms;

public:
    void Nhap();
    void Xuat();
    PHANSO operator+(PHANSO b);
    PHANSO operator-();
    operator double();
};

void PHANSO::Nhap()
{
    cout << "Nhap a va b: ";
    cin >> ts >> ms;
}

void PHANSO::Xuat()
{
    cout << ts << "/" << ms << endl;
}

PHANSO PHANSO::operator+(PHANSO b)
{
    PHANSO kq;
    kq.ts = ts * b.ms + ms * b.ts;
    kq.ms = ms * b.ms;
    return kq;
}

PHANSO PHANSO::operator-()
{
    ts = -ts;
    return *this;
}

PHANSO::operator double()
{
    return (double)ts / ms;
}

int main()
{
    PHANSO a, b;
    a.Nhap();
    b.Nhap();
    PHANSO sum = a + b;
    sum.Xuat();
    PHANSO neg = -sum;
    neg.Xuat();
    cout << " = " << (double)neg;
}