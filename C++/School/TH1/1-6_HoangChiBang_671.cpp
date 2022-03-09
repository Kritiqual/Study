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

class ARRAY
{
private:
    int *arr;
    int n;

public:
    void Nhap();
    void fmax();
    void fmin();
};

void ARRAY::Nhap()
{
    cout << "Nhap n = ";
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i + 1 << "] = ";
        cin >> arr[i];
    }
}

void ARRAY::fmax()
{
    int mx = arr[0];
    for (int i = 0; i < n; i++)
        if (mx < arr[i])
            mx = arr[i];
    cout << "Max array: " << mx;
}

void ARRAY::fmin()
{
    int mn = arr[0];
    for (int i = 0; i < n; i++)
        if (mn > arr[i])
            mn = arr[i];
    cout << "Min array: " << mn;
}

int main()
{
    ARRAY arr;
    arr.Nhap();
    arr.fmax();
    cout << endl;
    arr.fmin();
}