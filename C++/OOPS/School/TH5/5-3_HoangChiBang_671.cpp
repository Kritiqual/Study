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

class PTB2
{
private:
    double a, b, c;

public:
    PTB2();
    PTB2(double a, double b, double c);
    PTB2 operator+(PTB2 pt2);
    PTB2 operator-(PTB2 pt2);
    PTB2 operator!();
    friend ostream &operator<<(ostream &os, PTB2 pt);
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

PTB2 PTB2::operator+(PTB2 pt2)
{
    PTB2 res;
    res.a = a + pt2.a;
    res.b = b + pt2.b;
    res.c = c + pt2.c;
    return res;
}

PTB2 PTB2::operator-(PTB2 pt2)
{
    PTB2 res;
    res.a = a - pt2.a;
    res.b = b - pt2.b;
    res.c = c - pt2.c;
    return res;
}

PTB2 PTB2::operator!()
{
    a = -a;
    b = -b;
    c = -c;
    return *this;
}

ostream &operator<<(ostream &os, PTB2 pt)
{
    os << pt.a << "x^2 " << (pt.b >= 0 ? "+ " : "- ")
       << abs(pt.b) << "x " << (pt.c >= 0 ? "+ " : "- ")
       << abs(pt.c) << " = 0 ";
    return os;
}

int main()
{
    cls();
    PTB2 P(1, 2, -3), Q(3, -6, 8);
    cout << "P = " << P << " >  -P = " << !P << endl
         << "Q = " << Q << " >  -Q = " << !Q << endl
         << "P + Q = " << P + Q << endl
         << "P - Q = " << P - Q << endl;
}
