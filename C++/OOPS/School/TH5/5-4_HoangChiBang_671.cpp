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

class MATRIX
{
private:
    double **a;
    int m, n;

public:
    MATRIX operator-();
    MATRIX operator+(MATRIX b);
    MATRIX operator-(MATRIX b);
    friend istream &operator>>(istream &is, MATRIX &mx);
    friend ostream &operator<<(ostream &os, MATRIX mx);
};

istream &operator>>(istream &is, MATRIX &mx)
{
    cls();
    cout << "M x n = ";
    is >> mx.m >> mx.n;

    mx.a = new double *[mx.m];
    for (int i = 0; i < mx.m; i++)
        mx.a[i] = new double[mx.n];

    for (int i = 0; i < mx.m; i++)
        for (int j = 0; j < mx.n; j++)
            is >> mx.a[i][j];
    return is;
}

ostream &operator<<(ostream &os, MATRIX mx)
{
    for (int i = 0; i < mx.m; i++)
    {
        for (int j = 0; j < mx.n; j++)
            os << (mx.a[i][j] >= 0 ? "  " : " ") << mx.a[i][j];
        cout << endl;
    }
    return os;
}

MATRIX MATRIX::operator+(MATRIX b)
{
    if (m != b.m || n != b.n)
    {
        cout << "Khong the cong 2 ma tran!";
        return *this;
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = a[i][j] + b.a[i][j];
    return *this;
}

MATRIX MATRIX::operator-(MATRIX b)
{
    if (m != b.m || n != b.n)
    {
        cout << "Khong the tru 2 ma tran!";
        return *this;
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = a[i][j] - 2 * b.a[i][j];
    return *this;
}

MATRIX MATRIX::operator-()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = -a[i][j];
    return *this;
}

int main()
{
    MATRIX P, Q;
    cin >> P >> Q;
    cls();
    cout << "P:\n"
         << P
         << "Q:\n"
         << Q << endl
         << "-P:\n"
         << -P
         << "-Q:\n"
         << -Q << endl
         << "P + Q:\n"
         << P + Q << endl
         << "P - Q:\n"
         << P - Q << endl;
}
