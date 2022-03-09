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

class SOPHUC
{
private:
    float a, b;

public:
    SOPHUC(){};
    SOPHUC(float a, float b);
    SOPHUC operator+(SOPHUC nb);
    SOPHUC operator-(SOPHUC nb);
    friend ostream &operator<<(ostream &os, SOPHUC num);
};

SOPHUC::SOPHUC(float a, float b)
{
    this->a = a;
    this->b = b;
}

SOPHUC SOPHUC::operator+(SOPHUC nb)
{
    SOPHUC res;
    res.a = a + nb.a;
    res.b = b + nb.b;
    return res;
}

SOPHUC SOPHUC::operator-(SOPHUC nb)
{
    SOPHUC res;
    res.a = a - nb.a;
    res.b = b - nb.b;
    return res;
}

ostream &operator<<(ostream &os, SOPHUC num)
{
    os << num.a << (num.b > 0 ? " + " : " - ") << "i*" << abs(num.b);
    return os;
}

int main()
{
    SOPHUC SP1(1, 2), SP2(3, 9);
    SOPHUC SP3 = SP1 + SP2, SP4 = SP1 - SP2;
    cls();
    cout << "Num1: " << SP1 << endl
         << "Num2: " << SP2 << endl
         << "Tong: " << SP3 << endl
         << "Hieu: " << SP4;

    ofstream f("./cn.txt", ios::out);
    f << "Num1: " << SP1 << endl
      << "Num2: " << SP2 << endl
      << "Tong: " << SP3 << endl
      << "Hieu: " << SP4;
    f.close();
}