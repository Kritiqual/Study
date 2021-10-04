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
    float *arr;
    int n;

public:
    void Nhap();
    void Xuat();
    void Sx();
};

void ARRAY::Nhap()
{
    cout << "Nhap n = ";
    cin >> n;
    arr = new float[n];
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i + 1 << "] = ";
        cin >> arr[i];
    }
}

void ARRAY::Xuat()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void ARRAY::Sx()
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[min] > arr[j])
                min = j;

        int key = arr[min];
        while (min > i)
        {
            arr[min] = arr[min - 1];
            min--;
        }
        arr[i] = key;
    }
}

int main()
{
    ARRAY arr;
    arr.Nhap();
    arr.Sx();
    arr.Xuat();
}