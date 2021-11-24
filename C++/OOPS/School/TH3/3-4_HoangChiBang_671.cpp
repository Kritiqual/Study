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

class PTB2
{
private:
    double a, b, c;

public:
    PTB2();
    PTB2(double a, double b, double c);
    void Nhap();
    void Xuat();
    void Giai();
};

PTB2::PTB2()
{
    a = 0;
    b = 0;
    c = 0;
}

PTB2::PTB2(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

void PTB2::Nhap()
{
    cout << "\nNhap vao cac he so a, b, c: ";
    cin >> a >> b >> c;
}

void PTB2::Xuat()
{
    cout << "Phuong trinh: " << a << "x^2 "
         << (b >= 0 ? "+ " : "- ") << abs(b) << "x "
         << (c >= 0 ? "+ " : "- ") << abs(c) << " = 0 " << endl;
}

void PTB2::Giai()
{
    if (a == 0)
    {
        cout << "Khong phai phuong trinh bac 2!";
        // if (b == 0)
        //     if (c == 0)
        //         cout << "PT vo so nghiem!" << endl;
        //     else
        //         cout << "PT vo nghiem!" << endl;
        // else
        //     cout << "PT co nghiem duy nhat x = " << -b / c << endl;
    }
    else
    {
        double delta = b * b - 4 * a * c;
        if (delta < 0)
            cout << "PT vo nghiem!" << endl;
        if (delta == 0)
            cout << "PT co nghiem kep x = " << -b / (2 * a) << endl;
        if (delta > 0)
        {
            cout << "PT co x1 = " << (double)(-b + sqrt(delta)) / (4 * a) << endl;
            cout << "PT co x2 = " << (double)(-b - sqrt(delta)) / (4 * a) << endl;
        }
    }
}

int main()
{
    cls();
    PTB2 P(1, 2, -3);
    P.Xuat();
    P.Giai();

    PTB2 Q;
    Q.Nhap();
    Q.Xuat();
    Q.Giai();
}
