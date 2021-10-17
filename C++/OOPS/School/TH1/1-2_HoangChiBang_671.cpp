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

class RECTANGLE
{
private:
    double D, R;

public:
    void Nhap();
    void VE();
    float DIENTICH();
    float CHUVI();
};

void RECTANGLE::Nhap()
{
    cout << "Nhap Chieu dai va Chieu rong: ";
    cin >> D >> R;
}

void RECTANGLE::VE()
{
    cout << endl; // Beaufify
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < D; j++)
        {
            if ((i == 0 || i == R - 1) || (j == 0 || j == D - 1))
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << endl; // Beaufify
}

float RECTANGLE::DIENTICH()
{
    return D * R;
}

float RECTANGLE::CHUVI()
{
    return 2 * (D + R);
}

int main()
{
    RECTANGLE x;
    x.Nhap();
    x.VE();
    cout << "Dien tich: " << x.DIENTICH() << endl;
    cout << "Chu vi: " << x.CHUVI();
}