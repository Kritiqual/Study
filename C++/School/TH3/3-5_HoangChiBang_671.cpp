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

class ARRAY
{
private:
    int *VALUE, n;

public:
    ARRAY();
    ARRAY(int n);
    ~ARRAY();
    void Nhap();
    void Xuat();
};

ARRAY::ARRAY()
{
    n = 0;
    VALUE = NULL;
}

ARRAY::ARRAY(int n)
{
    this->n = n;
    VALUE = new int[n];
    for (int i = 0; i < n; i++)
        VALUE[i] = 0;
}

ARRAY::~ARRAY()
{
    n = 0;
    delete[] VALUE;
}

void ARRAY::Nhap()
{
    cout << "Nhap So luong phan tu: ";
    cin >> n;
    VALUE = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "value[" << i + 1 << "] = ";
        cin >> VALUE[i];
    }
}

void ARRAY::Xuat()
{
    cout << "Mang vua nhap: ";
    for (int i = 0; i < n; i++)
        cout << VALUE[i] << " ";
    cout << endl;
}

int main()
{
    ARRAY a1(10);
    a1.Xuat();

    ARRAY a2;
    a2.Nhap();
    a2.Xuat();
}
