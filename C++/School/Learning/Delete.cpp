// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
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

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nNumber to remove: ";
    int k;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        while (a[i] == k && i < n)
        {
            int *b = new int[n];
            for (int j = 0; j < i; j++)
                b[j] = a[j];
            for (int j = i + 1; j < n; j++)
                b[j - 1] = a[j];

            delete a;
            a = new int[n--];
            for (int j = 0; j < n; j++)
                a[j] = b[j];
        }
    }

    cout << "Result: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}