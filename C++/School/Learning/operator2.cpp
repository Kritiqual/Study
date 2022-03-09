// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
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

class HANG
{
private:
    char maH[10], tenH[30];
    float dG;

public:
    friend istream &operator>>(istream &is, HANG &hang);
    friend ostream &operator<<(ostream &os, HANG hang);
};

istream &operator>>(istream &is, HANG &hang)
{
    cout << "Nhap Ma hang: ";
    is.getline(hang.maH, 10);
    cout << "Nhap Ten hang: ";
    is.getline(hang.tenH, 30);
    cout << "Nhap Don gia: ";
    is >> hang.dG;
    return is;
}

ostream &operator<<(ostream &os, HANG hang)
{
    os << left << setw(12) << hang.maH
       << left << setw(32) << hang.tenH
       << left << hang.dG;
    return os;
}

int main()
{
    cls();
    int n;
    cout << "n = ";
    cin >> n;
    cin.ignore();
    HANG *hang = new HANG[n];
    for (int i = 0; i < n; i++)
        cin >> hang[i];
    for (int i = 0; i < n; i++)
        cout << hang[i];

    ofstream file("/home/kritiqual/hang.txt", ios::app);
    for (int i = 0; i < n; i++)
        file << hang[i];
    file.close();
}